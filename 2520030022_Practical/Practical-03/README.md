
fork() – Creates a new child process from an existing parent process.
After fork(), both the parent and child processes continue execution independently.

PID – A unique number used to identify each process.

PPID – The unique ID of the parent process.

getpid() – Returns the PID of the current process.

getppid() – Returns the PID of the parent process.

Ready State – The process is ready to run and waiting for CPU time.

Running State – The process is currently executing on the CPU.
Waiting and Terminated States – A waiting process waits for an event or resource, while a terminated process has finished execution.

Linux Monitoring Tools – ps shows process information, top monitors processes and resource usage in real time, and /proc provides detailed process information maintained by the Linux kernel.
