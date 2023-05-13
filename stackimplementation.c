#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int stack_arr[MAX];
int top = -1 ;
int isFull(){
    if(top==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    if(isFull()){
        printf("stack overflow\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
} 
int pop(){
    if(isEmpty()){
        printf("stack underflow\n");
        exit(1);
    }
    int value;
    value=stack_arr[top];
    top=top-1;
    return value; 
} 
int peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
        exit(1);
    }
    return stack_arr[top];
}
void print(){
    if(isEmpty()){
        printf("stack underflow\n");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d ",stack_arr[i]);
    }
    printf("\n");
}
int main(){
    for(int i=0;i<sizeof(stack_arr)/sizeof(stack_arr[0]);i++){
        printf("%d ",stack_arr[i]);
    }
    int choice;
    int data;
    while(1){
        scanf("%d",&choice);    
        switch(choice)
        {
            case 1:
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                data=pop();
                printf("%d",data);
                break;
            case 3:
                print();
                break;
            case 4: 
                printf("%d",peek());   
                break;
            case 5:
                exit(0);
            default :
                printf("wrong choice");    
        }
    }
    return 0; 
}