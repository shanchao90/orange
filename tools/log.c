#include "log.h"

//初始化日志器
Logger* logger_init(const char* file_path,LogTarget target,LogLevel min_level){
    Logger* logger = (Logger*)malloc(sizeof(Logger));
    if (logger == NULL){
        perror("Failed to allocate logger");
        return NULL;
    }
    //初始化成员
    logger->target =target;
    logger->min_level = min_level;
    strncpy_s(logger->file_path,file_path,255);
    logger->file_path[255] = '\0';

    // 如果需要输出到文件，打开文件（追加模式）
    if (target == LOG_TO_FILE || target == LOG_TO_BOTH){
        fopen_s(&logger->log_file,file_path,"a");
        if (logger->log_file == NULL){
            perror("Failed to open log file");
            free(logger);
            return NULL;
        }
    }
    else{
        logger->log_file = NULL;
    }
    return logger;
}

//销毁日志器
void logger_destroy(Logger* logger) {
    if (logger == NULL) return;

    //关闭文件
    if (logger->log_file != NULL){
        fclose(logger->log_file);
    }

    free(logger);
}

//转换日志级别为字符串
static const char* level_to_string(LogLevel level){
	switch (level) {
		case LOG_INFO:return "INFO";
		case LOG_WARN:return "WARN";
		case LOG_ERROR:return "ERROR";
		default:return "UNKNOWN";
	}
}

//获取当前时间（格式：YYYY-MM-DD HH:MM:SS）
static void get_current_time(char* time_str,size_t max_len){
	time_t now = time(NULL);
	struct tm tm_info;
	localtime_s(&tm_info,&now);
	strftime(time_str,max_len,"%Y-%m-%d %H:%M:%S",&tm_info);
}

//打印日志
void logger_log(Logger* logger,LogLevel level,const char* format,...){
	//检查日志器有效性和级别过滤
	if (logger == NULL || level < logger->min_level){
		return;
	}

	//获取时间和级别字符串
	char time_[32];
	get_current_time(time_str,sizeof(time_str));
	const char* level_str = level_to_string(level);

	//构建日志前缀（时间+级别）
	char log_prefix[128];
	snprintf(log_prefix,sizeof(log_prefix),
		"[%s] [%s]",time_str,level_str);

	//处理可变参数（格式化日志内容）
	var_list args;
	va_start(args,format);

	// 根据目标输出日志
	if (logger->target == LOG_TO_CONSOLE || logger->target == LOG_TO_BOTH){
		//输出到控制台
		printf("%s",log_prefix);
		vprintf(format,args);
		printf("\n");
	}

	if (logger->target == LOG_TO_FILE || logger->target == LOG_TO_BOTH) {
		//输出到文件（需检查文件是否打开）
		if (logger->log_file !=NULL) {
			fprintf(logger->log_file,"%s",log_prefix);
			vfprintf(logger->log_file,format,args);
			fprintf(logger->log_file,"\n");
			fflush(logger->log_file);
		}
	}

	va_end(args);
}

