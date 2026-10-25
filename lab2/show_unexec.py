import glob
import os
import re

build_cov = r"d:\study\ppois\ppo-labs\lab2\build_cov"
src_dir = r"d:\study\ppois\ppo-labs\lab2\src"

gcov_files = glob.glob(os.path.join(build_cov, "*.gcov"))
for gf in sorted(gcov_files):
    with open(gf, "r", encoding="utf-8", errors="ignore") as f:
        first_line = f.readline()
        m = re.search(r"Source:(.*)", first_line)
        if not m:
            continue
        source_path = m.group(1).strip()
        source_path_norm = os.path.normpath(source_path).lower()
        src_dir_norm = os.path.normpath(src_dir).lower()
        if not source_path_norm.startswith(src_dir_norm):
            continue
        
        f.seek(0)
        unexec_lines = []
        for line in f:
            parts = line.split(":", 2)
            if len(parts) >= 3:
                count_str = parts[0].strip()
                line_num = parts[1].strip()
                code = parts[2].rstrip()
                if count_str == "#####":
                    unexec_lines.append((line_num, code.strip()))
        
        rel_path = os.path.relpath(source_path, os.path.dirname(src_dir))
        if unexec_lines:
            print(f"\n--- {rel_path} ({len(unexec_lines)} unexecuted lines) ---")
            for num, code in unexec_lines[:10]:
                print(f"  L{num}: {code}")
