/* 연결리스트로 구현한 큐 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char element;

typedef struct node		//큐 노드 생성
{
	struct node* link;
	element data;

}Node;

typedef struct			//큐 위치
{
	Node* rear;			//큐 노드를 가리키는 멤버(입구)
	Node* front;		//큐 노드를 가리키는 멤버(출구)

}Qlink;

Qlink* create()			//큐링크 생성 함수
{
	Qlink* ql = (Qlink*)malloc(sizeof(Qlink));
	if (ql == NULL)exit(1); //return : return뒤에 선언된 값을 반환. exit : 그냥 프로그램 종료
	
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
		if (aql->front == NULL)// 삭제할 내용이 없다/
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