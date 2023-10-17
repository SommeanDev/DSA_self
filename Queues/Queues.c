#include<stdio.h>
#include<stdlib.h>

#define QUEUE_SIZE 5

int current_queue_size = 0, isFull = 0, isEmpty = 0;

typedef struct
{
    int *q;
    int front;
    int rear;
}Queue;

void initQueue(Queue *queue)
{
    queue->q = (int *)malloc(sizeof(int)*QUEUE_SIZE);
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(Queue *queue, int element) 
{
    if (queue->rear == -1 && queue->front == -1)
    {
        queue->front = 0;
        queue->rear = 0;

        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
        queue->q[queue->rear] = element;
        current_queue_size++;
    }
    else if ((queue->rear + 1) % QUEUE_SIZE == queue->front)
    {
        isFull = 1;
        printf("Queue is full\n");
    }
    else
    {
        queue->rear = (queue->rear + 1) % QUEUE_SIZE;
        queue->q[queue->rear] = element;
        current_queue_size++;
    }   
}

int dequeue(Queue *queue)
{
    if (queue->front == queue->rear)
    {
        queue->front = -1; 
        queue->rear = -1;
    }
    if (queue->front == -1 && queue->rear == -1)   
    {
        isEmpty = 1;
        printf("Queue is empty\n");
    }
    else 
    {
        queue->front = (queue->front + 1) % QUEUE_SIZE;
        int element = queue->q[queue->front];
        current_queue_size--;
        return element;
    }
}

int front(Queue *queue)
{
    int front_index = 0;
    if (isEmpty != 1 && queue->front != queue->rear)
    {
        front_index = (queue->front + 1) % QUEUE_SIZE;
        return queue->q[front_index];
    }
    else
    {
        printf("Queue is empty\n");
        return;
    }
}

void display_queue(Queue *queue){
    printf("Queue: [");
    for (int i = 0; i < QUEUE_SIZE; i++)
    {
        printf("%d ", queue->q[i]);
    }
    printf("]\n");
}

void menu_queue(Queue *queue)
{
    int break_loop = 0;
    while (break_loop != 1){
    printf("\nWhat operation do you want to do?\n");
    printf("1 - Enqueue\n");
    printf("2 - Dequeue\n");
    printf("3 - Check size\n");
    printf("4 - Check front\n");

    int reply, element;
    printf("You: ");
    scanf("%d", &reply);
    
    switch (reply)  
    {
    case 1:
        printf("Enter Element: ");
        scanf("%d", &element);
        enqueue(queue, element);
        display_queue(queue);
        break;
        
    case 2:
        element = dequeue(queue);
        printf("Dequeued element: %d\n", element);
        display_queue(queue);
        break;
    
    case 3:
        printf("Current size of queue: %d\n", current_queue_size);
        display_queue(queue);
        break;

    case 4:
        printf("%d\n", queue->front);
        printf("Front element of queue: %d\n", front(queue));
        display_queue(queue);
        break;
    default:
        break_loop = 1;
        break;
    }
    }
}

int main(int argc, char const *argv[])
{
    Queue testQueue;
    initQueue(&testQueue);
    menu_queue(&testQueue);

    return 0;
}
