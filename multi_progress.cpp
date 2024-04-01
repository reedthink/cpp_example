#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdio>

int main()
{
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0)
    {
        printf("child pid\n");
        exit(0);
    }
    else{
        printf("father pid\n");
        sleep(60);
    }

    return 0;
}