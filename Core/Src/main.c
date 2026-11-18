#include "main.h"

#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "lwprintf/lwprintf.h"

//LOG宏定义，用于打印日志信息，包含文件名和行号
#define LOG(fmt, ...)   printf("[%s:%d] " fmt "\n", __FILE__, __LINE__ __VA_OPT__(,) __VA_ARGS__)

int my_output_func(int ch, lwprintf_t* lwobj);

int main(void)
{
    lwprintf_init(my_output_func);

    sys_SHARED_init();
    sys_STATIC_init();
    
    lwprintf_printf("System initialized.\n""你好，欢迎使用本程序！\n");
    LOG("程序开始运行，当前时间: %s", ctime(&(time_t){time(NULL)}));
    lwprintf_printf("程序将运行 10 秒后自动退出...\n");

    // 记录程序开始的时间
    time_t start_time = time(NULL);

    for(;;)
    {
        // 如果当前时间减去开始时间 >= 10，就跳出死循环
        if (time(NULL) - start_time >= 10) {
            lwprintf_printf("已运行满 10 秒，程序退出。\n");
            break;
        }
        
        // 每次循环睡 1 秒，防止死循环把 CPU 占满
        sleep(1); 
    }

    LOG("程序结束运行，当前时间: %s", ctime(&(time_t){time(NULL)}));
    return 0;
}


int my_output_func(int ch, lwprintf_t* lwobj) {
    // 直接将字符输出到标准输出（终端屏幕）
    putchar(ch);
    return ch; 
}
