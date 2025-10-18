#include<stdio.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue(int x){
    if(rear==N-1)
    printf("Queue Overflow\n");
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear++;
        queue[rear]=x;
    }
    printf("Inserted %d\n",x);
}

void display(){
    if(front==-1 && rear==-1)
    printf("Queue is empty\n");
    else{
        printf("Queue elements: ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void peek(){
    if(front==-1 && rear==-1)
    printf("Queue is empty\n");
    else
    printf("Front element is: %d\n",queue[front]);
}

void dequeue(){
    if(front==-1 && rear==-1)
    printf("Queue Underflow\n");
    else if(front==rear){
        printf("Deleted %d\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted %d\n",queue[front]);
        front++;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    enqueue(40);
    enqueue(50);
    enqueue(60); // This should show overflow
    display();
    dequeue();
    display();
    peek();
    return 0;
}