#include <stdio.h>
void add_at_pos(int arr[],int arr2[],int size,int data,int pos){
    int i=0;
    for(i;i<pos-1;i++){
        arr2[i]=arr[i];
    }
    
    arr2[i]=data;

    int j;
    for(i=pos,j=pos-1;i<size+1,j<size;i++,j++){
        arr2[i]=arr[j];
        
    }
}
int main(){
    int arr[]={2,34,21,6,7,8,90,67,23,39};
    int pos=5,data=78,i;
    int size=sizeof(arr)/sizeof(arr[0]);
    int arr2[size+1];
    add_at_pos(arr,arr2,size,data,pos);
    for(i=0;i<size+1;i++){
        printf("%d ",arr2[i]);
    }
    return 0;
}