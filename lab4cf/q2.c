#include <stdio.h>
#include <stdlib.h>
 
 
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
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
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}
 
int diameter(struct Node* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        int leftDiameter = diameter(node->left);
        int rightDiameter = diameter(node->right);
        return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
    }
}
 
int diff(int arr[], int n) {
    struct Node* queue[n];
    int front = 0, rear = 0;
    
    struct Node* root = newNode(arr[1]);
    queue[rear++] = root;
    
    for (int i = 2; i < 2*n+1; i += 2) {
        struct Node* parent = queue[front++];
        
        if (arr[i] != -1) {
            parent->left = newNode(arr[i]);
            queue[rear++] = parent->left;
        }
        
        if (arr[i+1] != -1) {
            parent->right = newNode(arr[i+1]);
            queue[rear++] = parent->right;
        }
    }
    
    int h = height(root);
    int d = diameter(root);
    
    return abs(h - d);
}
 
int main() {
    int n;
    scanf("%d", &n);
    int arr[2*n+1];
    for (int i = 1; i < 2*n+1; i++) {
        scanf("%d", &arr[i]);
    }
    
    int differ = diff(arr, n);
    
    printf("%d", differ);
    
    return 0;
}