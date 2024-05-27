#ifndef __LOG_H
#define __LOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stdio.h"

#define CONSOLE_COLOR_RED(X)	"\033[31m-> " X "\033[0m"
#define CONSOLE_COLOR_GREEN(X)  "\033[32m-> " X "\033[0m"
#define CONSOLE_COLOR_YELLOW(X)  "\033[33m-> " X "\033[0m"

#define INIT_FALSE_STRING(X)	printf(CONSOLE_COLOR_RED("%s: " X " init false" " \r\n"), __FUNCTION__)
#define INIT_OK_STRING(X)	printf(CONSOLE_COLOR_GREEN("%s: "  X " init ok" " \r\n"), __FUNCTION__)
#define INIT_FALSE_STRING_ARGS(A, B, ...)	printf(CONSOLE_COLOR_RED("%s: " A " init false " B " \r\n"), __FUNCTION__, __VA_ARGS__)
#define INIT_OK_STRING_ARGS(A, B, ...)	printf(CONSOLE_COLOR_GREEN("%s: " A " init ok " B " \r\n"), __FUNCTION__, __VA_ARGS__)

#define LOG_INIT_OK(X)  printf(CONSOLE_COLOR_GREEN("%s: "  X " init ok" " \r\n"), __FUNCTION__)
#define LOG_INIT_OK_ARGS(X, ...)    printf(CONSOLE_COLOR_GREEN("%s: " A " init ok " B " \r\n"), __FUNCTION__, __VA_ARGS__)
#define LOG_INIT_FALSE(X)   printf(CONSOLE_COLOR_RED("%s: " X " init false" " \r\n"), __FUNCTION__)
#define LOG_INIT_FALSE_ARGS(X, ...) printf(CONSOLE_COLOR_RED("%s: " A " init false " B " \r\n"), __FUNCTION__, __VA_ARGS__)

#define LOG_I(X)	printf(CONSOLE_COLOR_GREEN("%s: " X " \r\n"), __FUNCTION__)
#define LOG_I_ARGS(X, ...)	printf(CONSOLE_COLOR_GREEN("%s: " X " \r\n"), __FUNCTION__, __VA_ARGS__)

#define LOG_W(X)	printf(CONSOLE_COLOR_YELLOW("%s: " X " \r\n"), __FUNCTION__)
#define LOG_W_ARGS(X, ...)  printf(CONSOLE_COLOR_YELLOW("%s: " X " \r\n"), __FUNCTION__, __VA_ARGS__)

#define LOG_E(X)	printf(CONSOLE_COLOR_RED("%s: " X " \r\n"), __FUNCTION__)
#define LOG_E_ARGS(X, ...)	printf(CONSOLE_COLOR_RED("%s: " X " \r\n"), __FUNCTION__, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif
