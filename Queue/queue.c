#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define QUEUE_SIZE 11 //只能使用10个位置，留一个空位置用来判断队满

int queue[QUEUE_SIZE] = {};

uint32_t rear, front = 0;

bool is_filled(void)
{
	return ((rear + 1) % QUEUE_SIZE == front);//队列最后一个元素不存数据，用来判断是否堆满
}

bool is_empty(void)
{
	return (rear == front);
}

void push(int element)
{
	if(!is_filled())//队不满
	{
		rear = (rear + 1) % QUEUE_SIZE;

		queue[rear] = element;
	}
	else
	{
		printf("%s\n", "Queue is filled!");
	}
}

int pop(void)
{
	if(!is_empty())
	{
		front = (front + 1) % QUEUE_SIZE;

		return queue[front];
	}
	else
	{
		printf("%s\n", "Queue is empty!");
	}
}

void main(void)
{
	for(uint8_t i = 0; i < QUEUE_SIZE; i++)
	{
		push(i+1);
	}

	pop();

	pop();

	push(11);

	push(12);

	push(13);

	pop();

	pop();

	pop();

	push(20);

	uint8_t num = 0;

	while((front + num) % QUEUE_SIZE != rear)
	{
		printf("%d->" ,queue[(front + num) % QUEUE_SIZE]);

		num++;
	}
	printf("%d\r\n", queue[(front + num) % QUEUE_SIZE]);

	printf("front: %d, rear:%d \r\n", front, rear);
}