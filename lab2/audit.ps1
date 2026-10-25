$includePath = "d:\study\ppois\ppo-labs\lab2\include"
$srcPath = "d:\study\ppois\ppo-labs\lab2\src"

# 1. Classes
$headerFiles = Get-ChildItem -Path $includePath -Recurse -Filter *.h
$classes = @()
foreach ($file in $headerFiles) {
    $content = Get-Content $file.FullName -Raw
    # find class definitions
    $matches = [regex]::Matches($content, 'class\s+([A-Za-z0-9_]+)\s*(?::\s*(?:public|protected|private)\s+([A-Za-z0-9_]+))?\s*\{')
    foreach ($m in $matches) {
        $className = $m.Groups[1].Value
        $baseName = $m.Groups[2].Value
        $classes += [PSCustomObject]@{
            Name = $className
            Base = $baseName
            File = $file.Name
            Path = $file.FullName
        }
    }
}

Write-Output "=== CLASSES COUNT: $($classes.Count) ==="

# 2. Exceptions
$exceptionClasses = $classes | Where-Object { 
    $_.Base -match "Exception|exception" -or $_.Name -match "Exception" -or $_.File -match "Exception"
}
Write-Output "=== EXCEPTIONS COUNT: $($exceptionClasses.Count) ==="
foreach ($e in $exceptionClasses) {
    Write-Output "  - $($e.Name) (Base: $($e.Base))"
}

# 3. Fields
# A field is a member variable in classes. Let's count private/protected fields in classes.
$fieldCount = 0
$fields = @()
$relations = @()
$basicTypes = @('int', 'double', 'float', 'bool', 'char', 'size_t', 'long', 'short', 'std::string', 'string', 'Date', 'Money', 'Id')

foreach ($file in $headerFiles) {
    $lines = Get-Content $file.FullName
    $inClass = $false
    $access = "private"
    $currentClass = ""
    foreach ($line in $lines) {
        $trimmed = $line.Trim()
        if ($trimmed -match '^class\s+([A-Za-z0-9_]+)') {
            $inClass = $true
            $currentClass = $matches[1]
            $access = "private"
            continue
        }
        if ($trimmed -match '^(public|protected|private):') {
            $access = $matches[1]
            continue
        }
        if ($trimmed -match '^\};') {
            $inClass = $false
            continue
        }
        if ($inClass -and ($access -eq "private" -or $access -eq "protected")) {
            # Check if it's a field declaration: Type varName; or Type varName{...};
            if ($trimmed -match '^([A-Za-z0-9_:<>\*&]+)\s+([A-Za-z0-9_]+)\s*(?:=\s*[^;]+|\{[^;]*\})?;' -and $trimmed -notmatch '\(' -and $trimmed -notmatch '^typedef' -and $trimmed -notmatch '^using' -and $trimmed -notmatch '^friend') {
                $type = $matches[1]
                $var = $matches[2]
                $fields += [PSCustomObject]@{
                    Class = $currentClass
                    Type = $type
                    Name = $var
                    File = $file.Name
                }
                $fieldCount++
                # Check for association: pointer, reference, shared_ptr, vector<Class*>, or domain class field
                if ($type -match '\*|shared_ptr|unique_ptr|vector|map|list' -or ($type -notmatch 'int|double|float|bool|char|size_t|std::string|string|long|short' -and $type -notmatch 'Status|Type|Category|Season|Gender|Currency')) {
                    $relations += [PSCustomObject]@{
                        From = $currentClass
                        ToType = $type
                        Name = $var
                        File = $file.Name
                    }
                }
            }
        }
    }
}

Write-Output "=== FIELDS COUNT: $fieldCount ==="
Write-Output "=== RELATIONS / ASSOCIATIONS COUNT: $($relations.Count) ==="

# 4. Methods / Behaviors in src/
$srcFiles = Get-ChildItem -Path $srcPath -Recurse -Filter *.cpp
$methods = @()
$longMethods = @()
$deepNesting = @()

foreach ($file in $srcFiles) {
    $lines = Get-Content $file.FullName
    $i = 0
    while ($i -lt $lines.Count) {
        $line = $lines[$i]
        # Match function definition: ReturnType ClassName::methodName(...)
        if ($line -match '^([A-Za-z0-9_:<>\*&\s]+?)\s*([A-Za-z0-9_]+)::([A-Za-z0-9_~]+)\s*\([^;]*\)\s*(?:const)?\s*(?:noexcept)?\s*(?::\s*.*)?$') {
            $className = $matches[2]
            $methodName = $matches[3]
            # Now find the opening brace and count lines until matching closing brace
            $startLine = $i + 1
            $braceDepth = 0
            $foundOpen = $false
            $methodLineCount = 0
            $maxIndent = 0
            $j = $i
            while ($j -lt $lines.Count) {
                $cur = $lines[$j]
                $openCount = ([regex]::Matches($cur, '\{')).Count
                $closeCount = ([regex]::Matches($cur, '\}')).Count
                if ($openCount -gt 0 -or $foundOpen) {
                    $foundOpen = $true
                    $braceDepth += ($openCount - $closeCount)
                    # Count indent depth
                    $indent = 0
                    if ($cur -match '^(\s+)') {
                        $indent = $matches[1].Length / 4 # assuming 4 spaces or tab
                    }
                    if ($braceDepth -gt $maxIndent) {
                        $maxIndent = $braceDepth
                    }
                    if ($braceDepth -le 0 -and $foundOpen) {
                        $methodLineCount = $j - $i + 1
                        break
                    }
                }
                $j++
            }
            # Record method
            # Check if it's substantive (not simple 1-line getter/setter)
            $isGetterSetter = ($methodName -match '^(get|set)[A-Z]' -and $methodLineCount -le 4)
            $methods += [PSCustomObject]@{
                Class = $className
                Method = $methodName
                Lines = $methodLineCount
                MaxDepth = $maxIndent
                File = $file.Name
                IsSubstantive = -not $isGetterSetter
            }
            if ($methodLineCount -gt 20) {
                $longMethods += [PSCustomObject]@{
                    Class = $className
                    Method = $methodName
                    Lines = $methodLineCount
                    File = $file.Name
                }
            }
            if ($maxIndent -gt 3) {
                $deepNesting += [PSCustomObject]@{
                    Class = $className
                    Method = $methodName
                    Depth = $maxIndent
                    File = $file.Name
                }
            }
            $i = $j
        }
        $i++
    }
}

$substantiveMethods = $methods | Where-Object { $_.IsSubstantive -eq $true }
Write-Output "=== TOTAL METHODS IN SRC: $($methods.Count) ==="
Write-Output "=== SUBSTANTIVE METHODS: $($substantiveMethods.Count) ==="
Write-Output "=== METHODS > 20 LINES: $($longMethods.Count) ==="
foreach ($lm in $longMethods) {
    Write-Output "  - $($lm.Class)::$($lm.Method) in $($lm.File) ($($lm.Lines) lines)"
}
Write-Output "=== METHODS WITH NESTING > 3: $($deepNesting.Count) ==="
foreach ($dn in $deepNesting) {
    Write-Output "  - $($dn.Class)::$($dn.Method) in $($dn.File) (depth: $($dn.Depth))"
}
