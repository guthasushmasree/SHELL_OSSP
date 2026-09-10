wait()

wait() is used by the parent process to wait for any one of its child processes to finish.
wait(NULL);
It also collects the child's exit status and removes the child’s entry from the process table.

waitpid()

waitpid() is used by the parent process to wait for a specific child process.
waitpid(pid, NULL, 0);
Here, pid is the Process ID (PID) of the child process.

Zombie Process

A zombie process is a child process that has finished execution, but its parent has not yet collected its exit status. Therefore, it remains in the process table.
A zombie is created when:
The child process finishes execution using exit().
The parent process is still running.
The parent does not call wait() or waitpid().
Therefore, the child becomes a zombie process.

Removing a Zombie

The parent can remove the zombie by calling:
wait(NULL);

wait() or waitpid() collects the child's exit status and removes the zombie entry from the process table.
