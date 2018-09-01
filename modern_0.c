/*1本段例程为经典栈的实现方法*/
#include <stdio.h>
#include <stdbool.h>

#define BUF_SIZE (10)
int buf[BUF_SIZE];
int top = 0;

static bool isStackFull(void)
{
    return top == sizeof(buf) / sizeof(int);
}

static bool isStackEmpty(void)
{
    return top == 0;
}

bool push(int val)
{
    if(isStackFull()) return false;
    buf[top++] = val;
    return true;
}

bool pop(int *pRet)
{
    if(isStackEmpty()) return false;
    *pRet = buf[--top];
    return true;
}

int to_push[5] = {1,2,3,4,5};
int to_pop[BUF_SIZE] = {0};


int main(void)
 { 
	int i,j,k;
	printf("[-----测试经典栈的实现方法-----]\n\r");
	printf("[-----to_pop的原始值-----]\n\r");
	for(k = 0; k < BUF_SIZE; k++)
	{
	    printf("to_pop[%d] = %d\n\r", k, to_pop[k]);
	}
	for(i = 0; i <5; i++)
	{
	    push(to_push[i]);
	}
	for(j = 0; j < 5; j++)
	{
	    pop(&to_pop[j]);
	}
	printf("[-----to_pop的后来值-----]\n\r");
	for(k = 0; k < BUF_SIZE; k++)
	{
	    printf("to_pop[%d] = %d\n\r", k, to_pop[k]);    
	}
	
	return 0;
}
