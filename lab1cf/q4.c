#include <stdio.h>
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + j + 1];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            arr[k++] = L[i++];

        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    int n,q;
    scanf("%d %d", &n,&q);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
merge_sort(arr,0,n-1);
    
for(int j=0;j<q;j++){
    int l,r,k;
    scanf("%d %d %d", &l,&r,&k);
    int sum=0;
 
    int arr2[r-l+1];
    arr2[0]=1;
    
    for(int i=1;i<r-l+1;i++){
        if(arr[i+l]==arr[i+l-1]){
            arr2[i]=arr2[i-1];
        }
        else{
            arr2[i]=arr2[i-1]+1;
        }
    }
    
    for(int o=l;o<r+1;o++){
        if(arr2[r-l]-arr2[o-l]<k-1){
            break;
        }
        int m=0;
        int j=k;
        while(m<k+1 && r+2>j+o){
            m=arr2[o-l+j-1]-arr2[o-l]+1;
            if(m==k){
            sum++;
        }
            j++;
        }
    }
    printf("%d\n",sum);
    }
    return 0;
}