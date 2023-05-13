#include <stdio.h>
#include <stdlib.h>
#define N 10000
void stackempty(int);
void pop(int [],int);
void push(int [],int);
void show(int [],int);

int main(){
    int arr[N]={1,2,3,4,5,6,7};
    int top=sizeof(arr)/sizeof(arr[0]);
    return 0;
}
void stackempty(int n)
{
    if(n==0){
        printf("%d",1) ;
        return;
    }
    printf("%d",0);
    return;
}
void pop(int arr[],int x){
    

}
void push(int arr[],int y){
    if(y==(sizeof(arr)/sizeof(arr[0]))){
        printf("stack overflow");
    }
    else{
        s[y]=s[]
    }
}