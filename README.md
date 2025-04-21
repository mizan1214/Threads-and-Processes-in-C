# Threads-and-Processes-in-C

This repository demonstrates the performance and behavior differences between **processes** and **threads** in C using `fork()` and `pthread`.

---

## 📌 Objective

Compare the time efficiency of:
- Process creation using `fork()`
- Thread creation using `pthread_create()`

---

## 🧠 Key Concepts

- Processes vs Threads
- Overhead of process creation
- Lightweight nature of threads
- Parallel execution benefits

---

## 💡 Sample Output

```bash
🔍 Comparing Fork vs Thread (sleep task)

🔹 Running with fork():
⏱️ Time (fork): 5.0012 sec

🔸 Running with pthread:
⏱️ Time (thread): 1.0011 sec
