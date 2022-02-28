/* ���� �ڷᱸ���� ť */
//������ ���Ƽ� �����Ѵ�..
//����ť�� ����

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10

typedef char element;

typedef struct
{
	element que[SIZE];		//ť �迭
	int front,rear;			//��ġ�ɹ� :: front(�ⱸ), rear(�Ա�)
}Queue;

Queue* createQ()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL)exit(1);
	
	q->front = -1;
	q->rear = -1;

	return q;
}

bool isEmpty(Queue* apq)
{
	if (apq->front == apq->rear)
	{
		printf("Queue is empty..................\n");
		return true;
	}
	else return false;
}

bool isFUll(Queue* apq)
{
	if (apq->rear >= SIZE)
	{
		printf("Queue is full...\n");
		return true;
	}
	else return false;
}

void enQueue(Queue* apq, element adata)//argunemt�ٿ��� a,,,, adata = argument data
{
	if (isFUll(apq)) return;
	
	apq->que[ ++(apq->rear) ] = adata;
}

element deQueue(Queue* apq)
{
	if (isEmpty(apq)) return;
	
	return apq->que[ ++(apq->front) ];

}

element peek(Queue* apq)
{
	if (isEmpty(apq)) return;
	printf("%d��° -> ", (apq->front) + 1);
	return apq->que[apq->front];
}

int main()
{

	
	Queue* Q = createQ();

	enQueue(Q, 'A');

	enQueue(Q, 'B');

	enQueue(Q, 'C');

	enQueue(Q, 'D');

	printf("%c\n",peek(Q));

	printf("%c ����\n", deQueue(Q));
	printf("%c\n", peek(Q));

	printf("%c ����\n", deQueue(Q));
	printf("%c\n", peek(Q));
	
	return 0;

}