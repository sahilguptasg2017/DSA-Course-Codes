#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
} *front=NULL, *rear=NULL;

void enqueue(int);
int dequeue();
int peek();
void print();
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
int peek(){
    if (isEmpty()){
        printf("queue underflow\n");
        exit(1);
    }
    return front->data;
}   

void enqueue(int n){

    struct node* temp;
    temp=malloc(sizeof(struct node));
    if(temp==NULL){
        printf("no space\n");
        exit(1);
    }
    temp->data = n;
    temp->link=NULL;
    if (rear == NULL){
        front=rear=temp;
    }
    else{
        rear->link=temp;
        rear = temp;
    }

}
int isEmpty(){

    if(front==NULL){
        return 1;
    }
    else
        return 0;
}

int dequeue(){

    int data;
    struct node* temp;
    if(isEmpty()){
        printf("queue underflow\n");
        exit(1);
    }
    if(front==NULL){
        rear=NULL;
    }
    temp=front;
    data=temp->data;
    front=front->link;
    free(temp);
    temp=NULL;
    return data;

}
void print(){

    struct node* temp;
    temp=front;
    if (isEmpty()){
        printf("queue underflow\n");
        exit(1);    
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");

}   