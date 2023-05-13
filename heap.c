#include <stdio.h>
#include <stdlib.h>



struct heap{
    int *arr;
    int capacity;
    int heap_size;

};

void swap(int* a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void max_heapify(struct heap *heap,int i){
    int l=2*i;
    int r=2*i+1;
    int largest;
    if(l<=heap->heap_size && heap->arr[l]>heap->arr[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<=heap->heap_size && heap->arr[r]>heap->arr[i]){
        largest=r;
    }
    if(largest!=i){
        swap(heap->arr[i],heap->arr[largest]);
        max_heapify(heap,largest);
    }
}





void max_heap_insert(struct heap *heap,int x){
    if(heap->heap_size==heap->capacity){
        printf("heap overflow");
    }
    heap->heap_size++;
    heap->arr[heap->heap_size]=x;
    int i=heap->heap_size;
    int parent=i/2;
    while(i>1 && heap->arr[parent]<heap->arr[i]){
        swap(heap->arr[i],heap->arr[parent]);
        i=parent;
    }
}

int max_heap_max(struct heap *heap){
    if(heap->heap_size==0){
        printf("underflow");
    }    
    return heap->arr[1];
}

int max_heap_extract(struct heap *heap){
    int max=max_heap_max(heap);
    heap->arr[1]=heap->arr[heap->heap_size];
    heap->heap_size=heap->heap_size-1;
    max_heapify(heap,1);
    return max;
}









int main(){

    return 0;


}