#include <stdio.h>
int partitioning(int l,int h,int arr[]){
    register int  pivot=arr[l];
    int i=l,j=h;
    while(i<j){
        do{
            i++;
        }while(arr[i]<=pivot);
        do{
            j--;
        }while (arr[j]>pivot);
        int key=arr[i];
        if(i<j){
            arr[i]=arr[j];
            arr[j]=key;
        }
    }
    int key1=arr[l];
    arr[l]=arr[j];
    arr[j]=key1;
    return j;
}
void Quicksort(int l, int h,int arr[]){
    if(l<h){
        int j=partitioning(l,h,arr);
        Quicksort(l,j,arr);
        Quicksort(j+1,h,arr);
    }
}
int main(){
    int arr[]={5,3,6,2,8,10};
    int h =sizeof(arr)/sizeof(arr[0]);
    Quicksort(0,h,arr);
    for(int i=0;i<h;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
