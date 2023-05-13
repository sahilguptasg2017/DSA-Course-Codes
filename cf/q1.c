#include <stdio.h>
#include <stdlib.h>
#define N 10000000

int max_1(int *arr){
    int key=arr[0];
    for(int i=1;i<N;i++){
        if(arr[i]>key){
            key=arr[i];
        }
    }
    return key;
}



void f(int m,int n){
    int *arr1=malloc(sizeof(int)*N);
    if(m>n){
        printf("NO");
        return;
    }
    else{
        if(n==3*m/2 || n==3*m || n==m){
            printf("YES");
            return;
        }
        else{
            arr1[0]=n;
            while(max_1(arr1)>m){
                int *arr2=malloc(sizeof(int)*N);
                
                
            
            
            
            
            }





        }
    }


}




int main(){


    return 0;
}