wait() is used by the parent process to wait for any one of its child processes to finish.

wait(NULL); ----> It also collects the child's exit status.

waitpid() is used by the parent process to wait for a specific child process.

waitpid(pid, NULL, 0);  -------> Here, pid is the process ID of the child.

A zombie process is a child process that has finished execution, but its parent has not collected its exit status. It remains in the process table.

A zombie is created when:

The child process finishes using exit().
The parent is still running.
The parent does not call wait() or waitpid().

So, the child becomes a zombie.

The parent can remove the zombie by calling:

wait(NULL);

These collect the child's exit status and remove the zombie entry from the process table.


