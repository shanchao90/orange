#include <stdio.h>
#include<time.h>

// 日志级别
typedef enum{
    LOG_INFO, //信息
    LOG_WARN, //警告
    LOG_ERROR //错误
}LogLevel;

// 日志输出目标
typedef enum{
    LOG_TO_CONSOLE, //控制台
    LOG_TO_FILE, //警告
    LOG_TO_BOTH //两者都输出
}LogTarget;

// 日志结构体
typedef struct {
    FILE* log_file;
    char file_path[256];
    LogTarget target;
    LogLevel min_level;
}Logger;
