#include <stdio.h>
#include <stdlib.h>
 
 
 
size_t strlen(const char* str) {
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
 
int strcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] == str2[i]) {
        if (str1[i] == '\0') {
            return 0; 
        }
        i++;
    }
    return str1[i] - str2[i]; 
}
 


int strncmp(const char* str1, const char* str2, size_t n) {
    size_t i = 0;
    while ((str1[i] == str2[i]) && (i < n)) {
        if (str1[i] == '\0') {
            return 0; 
        }
        i++;
    }
    if (i == n) {
        return 0;
    } 
    else {
        return str1[i] - str2[i]; 
    }
}
 
char* strcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
 
char* strncpy(char* dest, const char* src, size_t n) {
    char* p = dest;
    size_t i;
 
    for (i = 0; i < n && src[i] != '\0'; i++) {
        *p++ = src[i];
    }
 
    for (; i < n; i++) {
        *p++ = '\0';
    }
 
    return dest;
}
 
 
 
struct BSTNode {
    char key[21];
    struct BSTNode* left;
    struct BSTNode* right;
};
 
struct BSTNode* createNode(char* key) {
    struct BSTNode* newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    strcpy(newNode->key, key);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 
struct BSTNode* insertNode(struct BSTNode* root, char* key) {
    if (root == NULL) {
        return createNode(key);
    }
    int cmp = strcmp(key, root->key);
    if (cmp < 0) {
        root->left = insertNode(root->left, key);
    }
    else if (cmp > 0) {
        root->right = insertNode(root->right, key);
    }
    return root;
}

 
struct BSTNode* deleteNode(struct BSTNode* node, char* key) {
    if (node == NULL) {
        return node;
    }
    if (strcmp(key, node->key) < 0) {
        node->left = deleteNode(node->left, key);
    } 
    else if (strcmp(key, node->key) > 0) {
        node->right = deleteNode(node->right, key);
    } 
    else {
        if (node->left == NULL) {
            struct BSTNode* temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            struct BSTNode* temp = node->left;
            free(node);
            return temp;
        }   
        struct BSTNode* temp = node->right;
        while (temp->left != NULL) {
            temp = temp->left;
            
        }
        //node->key = temp->key;
        strncpy(node->key,temp->key,20);
        node->right = deleteNode(node->right, temp->key);
    }
    return node;
}
 
int deletefunc(struct BSTNode* node, char* prefix) {
    if (node == NULL) {
        return -1;
    }
    int result = -1;
    if (strncmp(prefix, (node)->key, strlen(prefix)) < 0) {
        result = deletefunc(((node)->left), prefix);
    }
     else if (strncmp(prefix, (node)->key, strlen(prefix)) > 0) {
        result = deletefunc(((node)->right)    , prefix);
    } 
    else {
        result = 0;
        node = deleteNode(node, (node)->key);
        deletefunc(node, prefix);
    }
    return result;
}
 
 
void prefixfunc(struct BSTNode* root, char* prefix) {
    if (root == NULL) {
        return;
    }
    int cmp = strncmp(prefix, root->key, strlen(prefix));
    
    if (cmp < 0) {
        prefixfunc(root->left, prefix);
    }
                
    else if (cmp == 0) {
        prefixfunc(root->left, prefix);
        printf("%s\n", root->key);
        prefixfunc(root->right, prefix);
    }
    else {
        prefixfunc(root->right, prefix);
    }
}
 
int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    struct BSTNode* root = NULL;
    for (int i = 0; i < n; i++) {
        char key[21];
        scanf("%s", key);
        root = insertNode(root, key);
    }
    for (int i = 0; i < q; i++) {
        char op[10], pref[21];
        scanf("%s %s", op, pref);
        if (strcmp(op, "Delete") == 0) {
            struct BSTNode* temp = root;
            int result=deletefunc(root,pref);
            if(result==-1){
                printf("-1\n");
            }
        }
        else if (strcmp(op, "Find") == 0) {
            struct BSTNode* temp = root;
            int found = 0;
            while (temp != NULL) {
                int cmp = strncmp(pref, temp->key, strlen(pref));
                if (cmp == 0) {
                    found = 1;
                    break;
                }   
                else if (cmp < 0) {
                    temp = temp->left;
                }
                else {
                    temp = temp->right;
                }
            }
            if (!found) {   
                printf("-1\n");
            }
            else {
                prefixfunc(temp, pref);
            }
        }
    }
    return 0;
}
 