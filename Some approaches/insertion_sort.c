#include <stdio.h>
void Insertionsort(int arr[],int n){
    int i,element,j;
    for(i=0;i<n-1;i++){
        element=arr[i];
        if (arr[i+1]<arr[i]){
            arr[i]=arr[i+1];
            arr[i+1]=element;
            for(int j=i-1;j>=0;j--){
                int key=arr[j];
                if(arr[j]>arr[j+1]){
                    arr[j]=arr[j+1];
                    arr[j+1]=key;
                }        
            }
        }
    }
}    
int main(){
    int arr[]={1,2,3,4,5,6,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    Insertionsort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}