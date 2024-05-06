/ Task Creation
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<FreeRTOS.h>
#include<task.h>
void vTask1(void*);
void vTask2(void*);
void vApplicationIdleHook(void);
int main(void)
{
xTaskCreate(vTask1,"Task1",1000,NULL,1,NULL);
xTaskCreate(vTask2,"Task2",1000,NULL,1,NULL);
vTaskStartScheduler();
return 0;
}
21
void vAssertCalled( unsigned long ulLine, const char * const pcFileName )
{
taskENTER_CRITICAL();
{
printf("[ASSERT] %s:%lu\n", pcFileName, ulLine);
flush(stdout);
}
taskEXIT_CRITICAL();
exit(-1);
}
void vTask1(void* parameter)
{
while(1)
{
printf("Task1\n");
sleep(500);
}
}
void vTask2(void* parameter)
{
while(1)
{
printf("Task2\n");
sleep(500);
}
}
void vApplicationIdleHook(void)
{
//printf("Idle\r\n");
}