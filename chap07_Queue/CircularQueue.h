#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define True 1
#define FALSE 0

#define QUE_LEN 100
typedef int Data;

typedef struct _cQueue
{
	int front;
	int rear;
	Data qurArr[QUE_LEN];
}CQueue;
typedef CQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpy(Queue* pq);

void Enqueue(Queue* pq, Data data);
DataDequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif // !__C_QUEUE_H__
