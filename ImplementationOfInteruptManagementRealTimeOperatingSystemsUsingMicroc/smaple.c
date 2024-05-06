#include <stdio.h>
#include <stdlib.h>
#include <FreeRTOS.h>
#include <task.h>
#include <timers.h>
#define TASKSCHEDULER
#ifdef TASKSCHEDULER
void vTask1(void*);
void vTask2(void*);
void vTask3(void*);
void vTask4(void*);
#endif
void vApplicationIdleHook(void);
int main(void)
{
#ifdef TASKSCHEDULER
xTaskCreate( vTask1, "Task 1", 1000, NULL, 1, NULL );
xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, NULL );
xTaskCreate( vTask3, "Task 3", 1000, NULL, 1, NULL );
xTaskCreate( vTask4, "Task 4", 1000, NULL, 1, NULL );
#endif
vTaskStartScheduler();
return 0;
}
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
#ifdef TASKSCHEDULER
void vTask1(void* parameter)
{
while(1)
{
printf("Task 1\n");
vTaskDelay(pdMS_TO_TICKS(250));
}
}
26
void vTask2(void* parameter)
{
while(1)
{
printf("Task 2\n");
vTaskDelay(pdMS_TO_TICKS(250));
}
}
void vTask3(void* parameter)
{
TickType_t xLastWaketime = xTaskGetTickCount(); while(1)
{
printf("Task 3 with 250ms\n");
vTaskDelayUntil(&xLastWaketime, pdMS_TO_TICKS(250));
}
}
void vTask4(void* parameter)
{
TickType_t xLastWaketime = xTaskGetTickCount();
while(1)
{
printf("Task 4 with 500ms\n");
vTaskDelayUntil(&xLastWaketime, pdMS_TO_TICKS(500));
}
}
#endif
void vApplicationIdleHook(void)
{
// printf("Idle\r\n");
}