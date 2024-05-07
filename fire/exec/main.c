#include "unistd.h"
#include "stdio.h"
#include "my_log.h"

/*
// execlp会在环境变量PATH指定的路径列表中搜索可执行文件。
execl("/bin/ls", "ls", "-l", NULL);
execlp("test", "ls", "-l", NULL)
*/

int main()
{
    LOG_I("start run");
    __pid_t i;
    i = fork();
    if(i <= 0) {
        return 0;
    }
    // execl("/bin/ls", "ls", "-l", NULL);
    execlp("ls", "ls", "-l", NULL);
    return 0;
}



    