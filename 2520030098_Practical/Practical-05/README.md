Parent process acts as the Producer

Child process acts as the Consumer.

An anonymous pipe is used for communication.

Parent writes data into the pipe.

Child reads data from the pipe.

Communication efficiency is measured using the time taken for data transfer.

fork() creates child processes.

pipe() creates communication between the processes.

dup2() connects the pipe to standard input/output.

exec() executes ls and grep.

The output of ls -l is sent through the pipe to grep ".c".
