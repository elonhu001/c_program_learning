/*1本段例程为经典栈的实现方法*/
/*2使用结构体将数据结构与代码块进行分离，这样可以实现面向对象中的多态
**在创建多个栈的时候就不会出现push1、push2这样的情况,在push的时候就可以指定哪个栈
*/
/*3带检查功能的栈（0——9），最简单的就是重新写一个带检查功能的push，但是这样需要传
**入大量参数，并且会有多个不同的push，改进的方法就是在生成栈的时候就将条件传到结
**构体中去
*/
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int top;
    const size_t size;
    int * const pBuf;//这样的const使得指针pBuf本身不会变化，即只能指向对应地址，不会变化
    
    const bool need_range_check;
    const int min;
    const int max;
}stack_t;

/*在创建栈的时候就指定栈的属性*/
#define new_stack(buf){                  \
    0, sizeof(buf) / sizeof(int), (buf), \
    false, 0, 0                          \
}

#define new_stack_with_range_check(buf, min, max){   \
    0, sizeof(buf) / sizeof(int), (buf),             \
    true , min, max                                  \
}

/*栈的属性函数*/
static bool is_range_ok(const stack_t *p, int val)
{
    return !p->need_range_check || (p->min <= val && val <= p->max);
}

static bool isStackFull(const stack_t *p)
{
    return p->top == p->size;
}

static bool isStackEmpty(const stack_t *p)
{
    return p->top == 0;
}

bool push(stack_t *p, int val)
{
    if(!is_range_ok(p, val) || isStackFull(p)) return false;
    p->pBuf[p->top++] = val;
    return true;
}

bool pop(stack_t *p, int *pRet)
{
    if(isStackEmpty(p)) return false;
    *pRet = p->pBuf[--p->top];
    return true;
}

/*创建两个栈，一个栈需要对应一个buf*/
#define BUF_SIZE (5)
int buf_1[BUF_SIZE];
int buf_2[BUF_SIZE];
stack_t stack_1 = new_stack(buf_1);
stack_t stack_2 = new_stack_with_range_check(buf_2, 0, 9);
/*测试数据*/
int to_push_1[BUF_SIZE] = {1,2,3,4,5};
int to_push_2[BUF_SIZE] = {6,7,8,9,10};
int to_pop_1[BUF_SIZE]  = {0};
int to_pop_2[BUF_SIZE]  = {0};

int main(void) 
{ 
	int i,j,k;
	printf("[-----测试经典栈的实现方法-----]\n\r");
/*	
	printf("[-----to_pop的原始值-----]\n\r");
	for(k = 0; k < BUF_SIZE; k++)
	{
	    printf("to_pop[%d] = %d\n\r", k, to_pop[k]);
	}
*/	printf("[-----入栈-----]\n\r");
	for(i = 0; i <5; i++)
	{
	    push(&stack_1, to_push_1[i]);
	    push(&stack_2, to_push_2[i]);
	}
	
	printf("[-----入栈后buf的值-----]\n\r");
	for(k = 0; k < BUF_SIZE; k++)
	{
	    printf("buf_1[%d] = %d     ", k, buf_1[k]);
	    printf("buf_2[%d] = %d\n\r", k, buf_2[k]);
	}
	printf("[-----出栈-----]\n\r");
	for(j = 0; j < 5; j++)
	{
	    pop(&stack_1, &to_pop_1[j]);
	    pop(&stack_2, &to_pop_2[j]);
	}
	
	printf("[-----出栈后to_pop的值-----]\n\r");
	for(k = 0; k < 5; k++)
	{
	    printf("to_pop_1[%d] = %d     ", k, to_pop_1[k]);
	    printf("to_pop_2[%d] = %d\n\r", k, to_pop_2[k]);
	}
	
	return 0;
}
