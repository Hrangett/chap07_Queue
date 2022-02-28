/* ���Ḯ��Ʈ�� ������ ť */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char element;

typedef struct node		//ť ��� ����
{
	struct node* link;
	element data;

}Node;

typedef struct			//ť ��ġ
{
	Node* rear;			//ť ��带 ����Ű�� ���(�Ա�)
	Node* front;		//ť ��带 ����Ű�� ���(�ⱸ)

}Qlink;

Qlink* create()			//ť��ũ ���� �Լ�
{
	Qlink* ql = (Qlink*)malloc(sizeof(Qlink));
	if (ql == NULL)exit(1); //return : return�ڿ� ����� ���� ��ȯ. exit : �׳� ���α׷� ����
	
	ql->front = NULL;
	ql->rear = NULL;
	return ql;
}

bool isEmpty(Qlink* aql)
{
	if (aql->front == NULL)
	{
		printf("Queue is Empty....\n");
		return true;
	}
	else return false;
}

void enQueue(Qlink* aql, element adata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)exit(1);

	newNode->data = adata;
	newNode->link = NULL;

	if (aql->front == NULL)
		aql->front = newNode;
	else
		aql->rear->link = newNode;

	
	aql->rear = newNode;

	
}

element deQueue(Qlink* aql)
{
	Node* del = aql->front;
	element d;

	if (isEmpty(aql))return 0;
	else
	{

		d = del->data;
		//aql->front = del->link;

		aql->front = aql->front->link;
		if (aql->front == NULL)// ������ ������ ����/
			aql->rear = NULL;
		free(del);

		return d;

	}


}

void printQ(Qlink* aql)
{
	Node* curr = aql->front;
	while (curr)
	{

		printf("%c..", curr->data);

		curr = curr->link;

	}

}
int main(void)
{

	Qlink* q = create();

	enQueue(q, 'A');
	enQueue(q, 'B');
	enQueue(q, 'C');
	enQueue(q, 'D');
	enQueue(q, 'E');
	enQueue(q, 'F');
	enQueue(q, 'G');
	printf("===print===\n");
	printQ(q);

	printf("\n===del===\n");

	printf("%c\n", deQueue(q));
	printf("%c\n", deQueue(q));
	printf("%c\n", deQueue(q));
	printf("\n===print===\n");
	printQ(q);

	printf("\n===del===\n");
	printf("%c\n", deQueue(q));
	printf("%c\n", deQueue(q));
	enQueue(q, 'H');
	printf("\n===print===\n");
	printQ(q);
	printf("front : %p, rear : %p\n", q->front, q->rear);
	printf("\n%c\n", deQueue(q));
	printf("%c\n", deQueue(q));
	printf("%c\n", deQueue(q));

	printf("%c\n\n", deQueue(q));
	printf("%c\n\n", deQueue(q));
	printf("%c\n\n", deQueue(q));
	printf("front : %p, rear : %p\n", q->front, q->rear);
	enQueue(q, 'K');
	printf("\nfront : %p, rear : %p\n", q->front, q->rear);


	return 0;
}