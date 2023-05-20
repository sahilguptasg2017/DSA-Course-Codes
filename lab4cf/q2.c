#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a > b) ? a : b;
}

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

int getBalance(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return height(node->left) - height(node->right);
    }
}

int isAVLTree(struct Node* node) {
    if (node == NULL) {
        return 1; 
    } else {
        int balance = getBalance(node);
        if (balance > 1 || balance < -1) {
            return 0; 
        } else {
            return isAVLTree(node->left) && isAVLTree(node->right);
        }
    }
}

int diff(int arr[], int n) {
    struct Node* queue[n];
    int front = 0, rear = 0;
    
    struct Node* root = newNode(arr[1]);
    queue[rear++] = root;
    
    for (int i = 2; i < 2 * n + 1; i += 2) {
        struct Node* parent = queue[front++];
        
        if (arr[i] != -1) {
            parent->left = newNode(arr[i]);
            queue[rear++] = parent->left;
        }
        
        if (arr[i + 1] != -1) {
            parent->right = newNode(arr[i + 1]);
            queue[rear++] = parent->right;
        }
    }
    
    if (isAVLTree(root)) {
        return 1; 
    } else {
        return 0; 
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[2 * n + 1];
    for (int i = 1; i < 2 * n + 1; i++) {
        scanf("%d", &arr[i]);
    }
    
    int isAVL = diff(arr, n);
    
    if (isAVL) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
