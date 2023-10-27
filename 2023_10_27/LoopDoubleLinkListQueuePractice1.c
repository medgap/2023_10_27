#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 5

typedef struct Queue{
    int front;
    int rear;
    int data[MAXSIZE];
}Queue;

Queue* initQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

int isFull(Queue* q){
    if((q->rear + 1) % MAXSIZE == 0)
        return 1;
    return 0;
}

int isEmpty(Queue* q){
    if(q->rear == q->front)
        return 1;
    return 0;
}

void enQueue(Queue* q,int data){
    if(isFull(q)){
        return;
    }
    else{
        q->data[q->rear] = data;
        q->rear = (q->rear + 1) % MAXSIZE;
    }
}

int deQueue(Queue* q){
    if(isEmpty(q)){
        return -1;
    }
    else{
        int res = q->data[q->front];
        q->front = (q->front + 1) % MAXSIZE;
        return res;
    }
}

void PrintQueue(Queue* q){
    int len = (q->rear - q->front + MAXSIZE) % MAXSIZE;
    int index = q->front;
    for(int i = 0; i < len; i++){
        printf(i == 0 ? "%d" : "->%d",q->data[index]);
        index = (index + 1) % MAXSIZE;
    }
    printf("\n");
}

int main(){
    Queue* q = initQueue();
    enQueue(q,1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    deQueue(q);
    PrintQueue(q);
    return 0;
}