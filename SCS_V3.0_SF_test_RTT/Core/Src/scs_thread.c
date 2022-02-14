#include "main.h"


//ָʾ���߳�
static struct rt_thread led_thread;				//����ɨ���߳̿��ƿ�
static char led_thread_stack[512];				//�̶߳�ջ
#define LED_THREAD_PRIORITY         16			//�߳����ȼ�������ɨ��Ϊ������ȼ�
#define LED_THREAD_TIMESLICE        100			//�̵߳�ʱ��Ƭ��С


int scs_thread_init(void)					//������������߳�
{
	rt_thread_init(&led_thread,					//�߳̿��ƿ�
                   "led_thread",				//�߳̿��ƿ�����
                   led_thread_entry,			//�߳���ں���
                   RT_NULL,						//�߳���ں����Ĳ���
                   &led_thread_stack[0],		//�߳�ջ��ʼ��ַ
                   sizeof(led_thread_stack),	//�߳�ջ��С
                   LED_THREAD_PRIORITY, 		//�߳����ȼ�
									 LED_THREAD_TIMESLICE);		//�߳�ʱ��Ƭ��С
									 
	rt_thread_startup(&led_thread); 
				   
	return 0;
}


void led_thread_entry(void *par)
{
	uint16_t count = 0;
	
	while(1)
	{
		rt_thread_mdelay(20);
		count++;
		
		if(count==25)		LED_ON();
		else if(count==30)	
		{
			count=0;
			LED_OFF();
		}
	}
	
}



























