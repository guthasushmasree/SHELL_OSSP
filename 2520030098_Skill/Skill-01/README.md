Skill-01: 
Process Management and System Calls

Step 1: Install WSL
Open PowerShell as Administrator and run:
wsl --install
Restart the system after installation.

Step 2: Configure Ubuntu
Open Ubuntu and create a Linux username and password.
Enter new UNIX username: guthasushmasree
New password: ****
Retype new password: ****

Step 3: Update Ubuntu
sudo apt update

Step 4: Install GCC
sudo apt install gcc
gcc --version

Step 5: Create a C Program
Create the program using nano:
nano skill01.c
The program uses fork() to create a child process, execl() to execute the ls command, and wait() for the parent to wait for the child.

Step 6: Compile and Run
gcc skill01.c -o skill01
./skill01

Process Abstraction – A process is a running program managed by the operating system.

fork() – Creates a new child process from a parent process.

exec() Family – Replaces the current process with another program.

Parent-Child Relationship – The process that creates another process is the parent, and the newly created process is the child.

Process Tree – Shows the relationship between parent and child processes.

System Call Tracing – strace is used to observe the system calls made by a program.

