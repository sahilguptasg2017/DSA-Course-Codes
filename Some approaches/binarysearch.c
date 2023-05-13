#include <stdio.h>
int binarysearch(int arr[],int l,int r,int x){
    if (r>=1){
        int mid_index=((l+(r-l)/2));
        if (arr[mid_index]==x){
            return mid_index;            
        }
        if(arr[mid_index]>x){
            return binarysearch( arr,l,mid_index-1, x);            
        }
        if(arr[mid_index]<x){
            return binarysearch(arr,mid_index+1,r,x);
        }
    }
    return -1;
}
int main(){
    int arr[]={2,5,3,4,8,41,5,54};
    int x;
    scanf("%d",&x);
    int r=sizeof(arr)/sizeof(arr[0]);
    printf("%d",binarysearch(arr,0,r,x));
    return 0;
}