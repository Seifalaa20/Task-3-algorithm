
#include <stdio.h>
#include <stdlib.h>
 
struct Node {
	
    int key;
    struct Node* next;
    
};
 
struct Queue {
	
    struct Node *front, *rear;
    
};
 
struct Node* newNode(int N)
{
	
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = N;
    temp->next = NULL;
    
    return temp;
    
}
 
 struct Queue* createQueue()
{
	
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    
    return q;
    
}
 
void enQueue(struct Queue* q, int N)
{
	
    struct Node* temp = newNode(N);
 
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        
        return;
        
    }
 
    q->rear->next = temp;
    q->rear = temp;
    
}
 
void deQueue(struct Queue* q)
{
    if (q->front == NULL)
        return;
 
    struct Node* temp = q->front;
 
    q->front = q->front->next;
 
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
    
}
 
int main()
{
    struct Queue* q = createQueue();
    enQueue(q, 0);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 6);
    enQueue(q, 7);
    deQueue(q);
    
    printf("Front in queue : %d \n", q->front->key);
    printf("Rear in queue : %d", q->rear->key);
    
    return 0;
}

