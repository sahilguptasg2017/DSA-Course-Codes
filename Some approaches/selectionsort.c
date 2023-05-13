#include <stdio.h>
void selection_sort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int key=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                arr[i]=arr[j];
                arr[j]=key;
                key=arr[i];
            }
        }
    }
}
int main(){
    int arr[]={11,25,12,22,64};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
