fork() is a system call used to create a new child process.
After fork(), both the parent and child processes continue their execution separately.

PID – Unique ID of a process.
PPID – ID of the parent process.
getpid() – Returns the Process ID (PID) of the current process.
getppid() – Returns the Parent Process ID (PPID) of the current process.

1) Ready – Process is ready to run and waiting for CPU time.

2) Running – Process is currently using the CPU.

3) Waiting – Process is waiting for an event or resource.

4) Terminated – Process has finished execution.

Linux monitoring tools :
ps – Shows process information and its current state.
top – Shows running processes and their resource usage in real time.
/proc – Provides detailed information about processes maintained by the Linux kernel.
