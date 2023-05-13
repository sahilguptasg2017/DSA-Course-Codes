#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
//prototypes
void enqueue(int);
int dequeue();
int peek();
void print();
int isFull();
int isEmpty();

int main(){
    int choice,data;
    while(1){
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            scanf("%d",&data);
            enqueue(data);
            break;
        case 2:
            data=dequeue();
            printf("%d",data);
            printf("\n");
            break;

        case 3:
            printf("%d",peek());
            printf("\n");
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);    
        } 
    }
}
void enqueue(int data){
    if(isFull()){
        exit(1);
    }
    if(front==-1){
        front=0;
    }           
    rear++;
    queue[rear]=data;
}
int dequeue(){
    int data;
    if(isEmpty()){
        exit(1);
    }
    data=queue[front];
    front++;
    return data;
}
int isEmpty(){
    if(front==-1 || front==rear+1){
        return 1;
    }        
    else{
        return  0;
    }
}
int isFull(){
    if(rear==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int peek(){
    if(isEmpty()){
        exit(1);
    }
    return queue[front];
}
void print(){
    int i;
    if(isEmpty()){
        exit(1);
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}