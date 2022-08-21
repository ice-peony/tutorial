 // make by liupengbin
 // date is (2022年8月21日)
// 这是一个日志管理的练习，但不同的错误问题出现的时候，使用不同的方式打印，在出
// 发行版的时候可以更好的管理日志

#include <stdio.h>
#include "Zlog.h"

int main(){
    int a = 1, b = 3;
    EMLOG(LOG_DEBUG, "app start");
    EMLOG(LOG_WARN, "app LOG_WARN");
    EMLOG(LOG_ERROR, "b is %d.", b);
    EMLOG(LOG_INFO, "a is %d.", a);
    
    return 0;
}
