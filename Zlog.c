 // make by pengb
 // date is (2022年8月21日)
#include "Zlog.h"

char * EMLOGLevelGet(const int level){
    switch (level)
    {
    case LOG_DEBUG/* constant-expression */:
        return "LOG_DEBUG";/* code */
        break;
    case LOG_INFO/* constant-expression */:
        return "LOG_INFO";/* code */
        break;
    case LOG_WARN/* constant-expression */:
        return "LOG_WARN";/* code */
        break;
    case LOG_ERROR/* constant-expression */:
        return "LOG_ERROR";/* code */
        break;
    default:
        break;
    }
}

void EM_LOG(const int level, const char * fun, const int line, const char * fmt, ...){
    #ifdef TEST_LOG
    va_list arg;
    va_start(arg, fmt);
    char buf[1 + vsnprintf(NULL, 0, fmt, arg)];  // have problems about vsnprintf in vscode
    vsnprintf(buf, sizeof(buf), fmt, arg);
    va_end(arg);
    if(level >= LOG_LEVEL){
        printf("[%s][%s:%d] %s\n",EMLOGLevelGet(level),fun, line, buf);
    }
    #endif // TEST_LOG
}
