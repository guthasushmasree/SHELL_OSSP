#include <stdio.h>
#include <unistd.h>
int main()
{
char buf[100];
int n;
while (1)
{
printf("myshell> ");
n = read(0, buf, 99);
buf[n - 1] = '\0';
if (buf[0] == 'e' && buf[1] == 'x' && buf[2] == 'i' && buf[3] == 't')
{
break;
}
printf("You entered: %s\n", buf);
}
printf("Shell exited\n");
return 0;
}
