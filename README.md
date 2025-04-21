# Threads-and-Processes-in-C

# 🧵 Thread vs 👥 Process Performance Comparison (Windows, C)

This repository contains a simple, Windows-compatible C demo that compares the performance of creating **threads** vs **processes**, using realistic CPU-bound tasks (math operations).

## 🔧 Files Included

- `process_thread_comparison.c`: The main program that:
  - Runs 5 child processes 
  - Runs 5 threads 
  - Measures and prints total execution time for both

- `child_basic.c`: The program each child process runs. Performs CPU-heavy math work.

## 🚀 How to Compile

You need a C compiler (like `gcc` via MinGW) on Windows. Open your terminal or command prompt and run:

```bash
gcc child_basic.c -o child_basic.exe -lm
gcc process_thread_comparison.c -o demo_compare.exe -lm
