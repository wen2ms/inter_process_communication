### 🧵 1. **Pipes (匿名管道)**
- One-way communication.
- Only works between **related processes** (e.g., parent and child).
- Example: `pipe()` in C, or `ls | grep txt` in shell.

---

### 🧾 2. **Named Pipes (FIFOs / 命名管道)**
- Allows communication between **unrelated processes**.
- Still one-way (need two FIFOs for bidirectional).

---

### 💬 3. **Message Queues (消息队列)**
- Messages are passed with identifiers.
- More structured than pipes.
- Persistent until explicitly removed.

---

### 🧠 4. **Shared Memory (共享内存)**
- Fastest method (memory is shared directly).
- Requires synchronization (e.g., semaphores).

---

### 🚦 5. **Semaphores (信号量)**
- Mainly used for **synchronization**, not data transfer.
- Often used alongside shared memory.

---

### 🔔 6. **Signals (信号)**
- No data is transferred, only control messages.

---

### 🌐 7. **Sockets (套接字)**
- Powerful and flexible: support **inter-machine** communication.
- Can be:
  - **UNIX domain sockets** (local IPC),
  - **INET sockets** (TCP/IP over network).
- Use: `socket()`, `bind()`, `listen()`, `accept()`, `send()`, `recv()`.

---

### 🗂 8. **Memory-Mapped Files (mmap 文件映射)**
- Multiple processes map the same file into memory.
- Efficient for large data sharing.

---