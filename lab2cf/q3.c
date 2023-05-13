#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define MAX_STACK 1000
#define MAX_QUEUE 1000
 
typedef struct Queue {
    int front, rear, size;
    int *arr;
} Queue;
 
Queue *create_queue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->rear = -1;
    queue->size = MAX_QUEUE;
    queue->arr = (int *)malloc(MAX_QUEUE * sizeof(int));
    return queue;
}
 
int is_empty(Queue *queue) {
    return queue->front == -1 && queue->rear == -1; 
}
 
 
void enqueue(Queue *queue, int k) {
    if (queue->rear == queue->size - 1) { 
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = k;
}
 
void dequeue(Queue *queue) {
    if (is_empty(queue)) {
        return;
    }
    else{
    //int k = queue->arr[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    }
}
 
int dequeue_operation(Queue *queue) {
    if (is_empty(queue)) {
        printf("-1\n");
    } else {
        dequeue(queue);
        return dequeue_operation(queue); 
    }
}
 
 
int max_sum_pairs(Queue *queue, int k) {    
    int max_pairs = 0, current_pairs = 0, current_sum = 0;
    int front = queue->front, rear = queue->rear;
    while (front <= rear) {
        if (current_sum + queue->arr[front] < k) {
            current_sum += queue->arr[front++];
            current_pairs = 0;
        } else {
            current_sum -= queue->arr[rear--];
            current_pairs++;
            if (current_pairs >= max_pairs) {
                max_pairs = current_pairs;
            }
        }
    }
    return max_pairs;
}
 
int main() {
    Queue *queue;
    Queue *tmp;
    int stack_top = -1;
    Queue *stack[MAX_STACK];
    int Q;
    scanf("%d",&Q);
    for(int i=0;i<Q;i++){
        char input[MAX];
        char command[MAX];
        int value;
 
        scanf(" %[^\n]", input); 
 
        char *token = strtok(input, " "); 
        strcpy(command, token); 
        token = strtok(NULL, " "); 
        value = atoi(token); 
 
        if(strcmp(command,"Push")==0){
            queue = create_queue();
            enqueue(queue, value);
            stack[++stack_top] = queue;
 
        } else if (strcmp(command,"Enqueue")==0){
            if (stack_top == -1) {
                queue = create_queue();
                enqueue(queue, value);
                stack[++stack_top] = queue;
            } else {
                enqueue(stack[stack_top], value);
            }
                
        } else if (strcmp(command,"MaxSumPairs")==0){
            if (stack_top == -1) {
                printf("-1\n");
            } else {
                int max_pairs = max_sum_pairs(stack[stack_top], value);
                printf("%d\n", max_pairs);
            }
        } 
         else if (strcmp(command,"Dequeue")==0) {
            if (stack_top == -1) {
                printf("-1\n");
            } else {
                int k = dequeue_operation(stack[stack_top]);
                if (k == -1) {
                    stack_top--;
                    if (stack_top == -1) {
                        printf("-1\n");
                    } else {
                        k = dequeue_operation(stack[stack_top]);
                        if (k == -1) {
                            stack_top--;
                            free(stack[stack_top+1]); 
                            printf("-1\n");
                        } else {
                            printf("%d\n", k);
                        }
                    }
                
                }
            }
        }
 
        else if (strcmp(command,"Pop")==0) {
            if (stack_top != -1 && is_empty(stack[stack_top])) {
                tmp = stack[stack_top--];
                free(tmp);
            }
            else{
                free(tmp);
            }
        }
    }
    return 0;
}