#include "unistd.h"
#include "stdio.h"
#include "my_log.h"
#include <stdlib.h>
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
// ========== execl 部分
#if 0
    // execl("/bin/ls", "ls", "-l", NULL);
    // execlp("ls", "ls", "-l", NULL);
#endif

// ==========  exit部分
#if 1
    LOG_I("测试 _exit(0), LOG_I 不会刷新缓冲区");
    printf("测试 _exit(0) printf 不会刷新缓冲区\r\n");
    // printf(CONSOLE_COLOR_GREEN("%s: " "sdfsdf" " \r\n"), __FUNCTION__);
    _exit(0);
#endif

#if 0
    LOG_I("测试exit(0), 会刷新缓冲区");
    exit(0);
#endif
    return 0;
}



    