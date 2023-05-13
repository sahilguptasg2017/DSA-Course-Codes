#include <stdio.h>
#define N 2000
void Merge(int arr1[],int arr2[],int m,int n,int arr3[N]){
    int i=0,j=0,k=0;
    while(i<=n && j<=m ){
        if(arr1[i]<arr2[j]){
            arr3[k++]=arr1[i++];
        }   
        else{
            arr3[k++]=arr2[j++];
        }
    }
    for(;i<=m;i++){
        arr3[k++]=arr1[i];
    }
    for(;j<=n;j++){
        arr3[k++]=arr2[j];
    }
}
int main(){
    int arr1[]={2,3,6,7,10,13,15};
    int arr2[]={5,8,9,11,12,16,17};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int n=sizeof(arr2)/sizeof(arr2[0]);
    int arr3[m+n];
    Merge(arr1,arr2,m,n,arr3);
    for(int i=0; i<m+n;i++){
        printf("%d ",arr3[i]);
    }
    return 0;
}