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

void add_kth_node(LinkedList* t, int k, int data) {
    if (t->head == NULL) {
        printf("-1\n");
        return;
    }
    Node* curr = t->head;
    int count = 1;
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
    if (curr == NULL || count < k) {
        printf("-1\n");
        return;
    }
    curr->data += data;
}

void sub_kth_node(LinkedList* t, int k, int data) {
    if (t->head == NULL) {
        printf("-1\n");
        return;
    }
    Node* curr = t->head;
    int count = 1;
    while (curr != NULL && count < k) {
        curr = curr->next;
        count++;
    }
    if (curr == NULL || count < k) {
        printf("-1\n");
        return;
    }
    curr->data -= data;
}

void xor_kth_node(LinkedList* t, int k) {
    if (t->head == NULL) {
        printf("-1\n");
        return;
    }
    Node* curr = t->head;
    int count = 0;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    if (k > count) {
        printf("-1\n");
        return;
    }
    int xor_res = 0;
    curr = t->head;
    for (int i = 0; i < count - k; i++) {
        curr = curr->next;
    }
    while (curr != NULL) {
        xor_res ^= curr->data;
        curr = curr->next;
    }
    printf("%d\n", xor_res);
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

void delete_node_K(LinkedList* t, int k) {
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
    int n, q, num, k,data;
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
        if (strcmp(query, "Delete") == 0) {
            scanf("%d", &k);
            delete_node_K(&t,k);;
        } else if (strcmp(query, "Xor") == 0) {
            
            scanf("%d", &k);
            xor_kth_node(&t,k);
        } else if (strcmp(query, "Subtract") == 0) {
            scanf("%d %d", &k,&data);
            sub_kth_node(&t,k,data);
        } else if (strcmp(query, "KthNode") == 0) {
            scanf("%d", &k);
            kth_node(&t, k);
        } else if (strcmp(query, "Add") == 0) {
            scanf("%d %d",&k,&data);
            add_kth_node(&t,k,data);
    }
    }

}