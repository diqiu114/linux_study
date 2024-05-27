#include "unistd.h"
#include "stdio.h"


int main()
{
    __pid_t i;
    printf("before fork\r\n");
    i = fork();
    if(i!=0) {
        sleep(1);
    }
    return 0;
}



