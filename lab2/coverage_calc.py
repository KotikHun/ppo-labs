import os
import subprocess
import glob
import re

build_cov = r"d:\study\ppois\ppo-labs\lab2\build_cov"
src_dir = r"d:\study\ppois\ppo-labs\lab2\src"

# Find all gcda files under CMakeFiles/lab2_lib.dir
gcda_files = glob.glob(os.path.join(build_cov, "CMakeFiles", "lab2_lib.dir", "**", "*.gcda"), recursive=True)
print(f"Found {len(gcda_files)} gcda files for lab2_lib")

# Clean old .gcov files in build_cov
for g in glob.glob(os.path.join(build_cov, "*.gcov")):
    try:
        os.remove(g)
    except:
        pass

# Run gcov
for gcda in gcda_files:
    obj_dir = os.path.dirname(gcda)
    # gcov -o <obj_dir> <gcda>
    cmd = ["gcov", "-o", obj_dir, "-p", gcda]
    subprocess.run(cmd, cwd=build_cov, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)

# Now read all .gcov files
gcov_files = glob.glob(os.path.join(build_cov, "*.gcov"))
print(f"Generated {len(gcov_files)} .gcov files")

file_stats = {}
total_executable = 0
total_executed = 0

for gf in gcov_files:
    basename = os.path.basename(gf)
    # We only care about src files
    # The -p flag makes names like #study#ppois#ppo-labs#lab2#src#core#Date.cpp.gcov
    with open(gf, "r", encoding="utf-8", errors="ignore") as f:
        first_line = f.readline()
        # format: -: 0:Source:D:/study/ppois/ppo-labs/lab2/src/core/Date.cpp
        m = re.search(r"Source:(.*)", first_line)
        if not m:
            continue
        source_path = m.group(1).strip()
        # Normalize
        source_path_norm = os.path.normpath(source_path).lower()
        src_dir_norm = os.path.normpath(src_dir).lower()
        if not source_path_norm.startswith(src_dir_norm):
            continue
        
        # Now count lines
        f.seek(0)
        file_exec = 0
        file_total = 0
        for line in f:
            parts = line.split(":", 2)
            if len(parts) >= 2:
                count_str = parts[0].strip()
                if count_str == "-":
                    continue
                elif count_str == "#####":
                    file_total += 1
                elif count_str.isdigit():
                    cnt = int(count_str)
                    file_total += 1
                    if cnt > 0:
                        file_exec += 1
        
        rel_path = os.path.relpath(source_path, os.path.dirname(src_dir))
        pct = (file_exec / file_total * 100) if file_total > 0 else 100.0
        file_stats[rel_path] = (file_exec, file_total, pct)
        total_executable += file_total
        total_executed += file_exec

print("\n=== COVERAGE PER FILE IN SRC ===")
for path, (ex, tot, pct) in sorted(file_stats.items()):
    print(f"{path:45} : {pct:6.2f}% ({ex:3}/{tot:3})")

total_pct = (total_executed / total_executable * 100) if total_executable > 0 else 0
print(f"\n==========================================")
print(f"TOTAL SRC LINE COVERAGE: {total_pct:.2f}% ({total_executed} / {total_executable} lines)")
print(f"==========================================")
