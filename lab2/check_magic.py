import os
import re
import glob

src_dir = r"d:\study\ppois\ppo-labs\lab2\src"

magic_number_pattern = re.compile(r'(?<![A-Za-z0-9_])(\d+\.?\d*)(?![A-Za-z0-9_])')
# Exclude standard constants like 0, 1, -1, 2 in common loops/init
ignore_numbers = {'0', '1', '2', '0.0', '1.0', '-1'}

findings = []

for root, _, files in os.walk(src_dir):
    for f in files:
        if not f.endswith(".cpp"):
            continue
        path = os.path.join(root, f)
        with open(path, "r", encoding="utf-8", errors="ignore") as file:
            for idx, line in enumerate(file, 1):
                clean_line = line.strip()
                # Skip comments, includes, output streams
                if clean_line.startswith("//") or clean_line.startswith("/*") or clean_line.startswith("#"):
                    continue
                if "<<" in clean_line or ">>" in clean_line:
                    continue
                # Find all numbers
                matches = magic_number_pattern.findall(clean_line)
                for m in matches:
                    if m not in ignore_numbers and not clean_line.startswith("const") and not "constexpr" in clean_line:
                        # Check context
                        findings.append((f, idx, clean_line, m))

print(f"Total potential magic number lines: {len(findings)}")
for f, idx, line, m in findings:
    print(f"{f}:{idx} [found {m}] -> {line}")
