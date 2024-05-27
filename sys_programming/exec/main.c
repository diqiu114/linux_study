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
        LOG_I("mian progress return");
        return 0;
    }
// ========== execl 部分
#if 1
    LOG_I("test execl");
    execl("/bin/ls", "ls", "-l", NULL);
    // execlp("ls", "ls", "-l", NULL);
    // 调用execl后线程被替换
    LOG_I("execl end");
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

// ================= C语言调用线程 =================
/*
system()函数使用 shell 调用命令，
它受到系统shell自身的功能特性和安全缺陷的限制，
因此，并不推荐使用这种方法去启动一个进程。
*/
// #include <sys/types.h>
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     pid_t result;

//     printf("This is a system demo!\n\n");

//     /*调用 system()函数*/
//     result = system("ls -l");

//     printf("Done!\n\n");

//     return result;
// }

    