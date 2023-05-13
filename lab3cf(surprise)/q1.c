#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linkedlist {
    Node* head;
} LinkedList;

void reverse(LinkedList* t) {
    Node* prev = NULL;
    Node* curr = t->head;
    while (curr != NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    t->head = prev;
}
void print(LinkedList* t){  
    if (t->head == NULL){
        printf("the linked list is empty");
    }
    else{
        Node* ptr = t->head;
        while (ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }

        printf("\n");
    }
} 

void count_of_nodes(LinkedList* t) {
    int count = 0;
    Node* curr = t->head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    printf("%d\n", count);
}

void kth_node(LinkedList* t, int k) {
    if (t->head == NULL) {
        printf("-1\n");
    } else {
        int count = 0;
        Node* curr = t->head;
        while (curr != NULL) {
            count++;
            if (count == k) {
                printf("%d\n", curr->data);
                return;
            }
            curr = curr->next;
        }
        printf("-1\n");
    }
}

void delete_node(LinkedList* t, int k) {
    if (t->head == NULL) {
        printf("-1\n");
    } else if (k == 1) {
        t->head = t->head->next;
    } else {
        int count = 1;
        Node* curr = t->head;
        while (curr->next != NULL) {
            count++;
            if (count == k) {
                curr->next = curr->next->next;
                return;
            }
            curr = curr->next;
        }
        printf("-1\n");
    }
}

int main() {
    int n, q, num, k;
    char query[10];

    LinkedList t;
    t.head = NULL;

    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        Node* node = (Node*) malloc(sizeof(Node));
        node->data = num;
        node->next = NULL;
        if (t.head == NULL) {
            t.head = node;
        } else {
            Node* curr = t.head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%s", query);
        if (strcmp(query, "Reverse") == 0) {
            reverse(&t);
        } else if (strcmp(query, "Print") == 0) {
            print(&t);
        } else if (strcmp(query, "Length") == 0) {
            count_of_nodes(&t);
        } else if (strcmp(query, "KthNode") == 0) {
            scanf("%d", &k);
            kth_node(&t, k);
        } else if (strcmp(query, "Delete") == 0) {
            scanf("%d",&k);
            delete_node(&t,k);
    }
    }

}