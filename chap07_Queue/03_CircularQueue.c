#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue* pq)	//ť�� �� �� ��� ����ϴ� �Լ� ::  front�� rear�� ������ ��ġ�� ����Ŵ
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear)	//ť�� �� �� ���
		return True;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)		//�迭�� ������ ����� �ε��� ���̶��
		return 0;
	else
		return pos + 1;
}

void Enqueue(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front) //ť�� �� ���ٸ�
	{
		pritnf
	}
}



