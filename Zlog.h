#ifndef _ZLOG_H_
#define _ZLOG_H_

#include <stdio.h> // .c 文件中使用了printf
#include <stdarg.h> // 使用不定参数的方法需要包含 stdarg 头文件 va_list

#define TEST_LOG 1 // 总的打开/关闭日志的开关
#define LOG_LEVEL LOG_WARN // 设置需要打印日志的等级

typedef enum{
    LOG_DEBUG = 0,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
}E_LOGLEVEL;
// 枚举型，定义了就直接用，不需要像结构体那样，定义完后还需要再声明一个变量再使用。
// 有些像全局变量

char * EMLOGLevelGet(const int level);
void EM_LOG(const int level, const char * fun, const int line, const char * fmt, ...);

#define EMLOG(level, fmt...)  EM_LOG(level, __FUNCTION__, __LINE__, fmt) 
    // 使用emlog替代em_log，注意  __FUNCTION__, __LINE__ 这两个可以显示函数名和行号
    // 此处宏定义me_log最后一个参数直接写fmt，不用加...

#endif
