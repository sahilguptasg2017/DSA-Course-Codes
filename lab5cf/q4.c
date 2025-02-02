#include <stdio.h>
#include <stdlib.h>

#define int long long 

struct node {
    int key;
    struct node* left;
    struct node* right;
    int height;
    int sum;
    int numNodes;
};

int height(struct node* N) {
    if (N == NULL) {
        return 0;
    }
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct node* newnode(int key) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->sum = key;
    node->numNodes = 1;
    return node;
}

struct node* allocate_node(int key) {
    struct node* root = (struct node*)malloc(sizeof(struct node));
    root->key = key;
    root->height = 0;
    root->left = NULL;
    root->right = NULL;
    root->sum = key;
    root->numNodes = 1;
    return root;
}

int getbalance(struct node* N) {
    int l_height = N->left ? N->left->height : -1;
    int r_height = N->right ? N->right->height : -1;
    return l_height - r_height;
}

void set_height(struct node* node) {
    int l_height = (node->left) ? node->left->height : -1;
    int r_height = (node->right) ? node->right->height : -1;
    node->height = max(l_height, r_height) + 1;
}

void set_sum(struct node* node) {
    int left_sum = (node->left) ? node->left->sum : 0;
    int right_sum = (node->right) ? node->right->sum : 0;
    node->sum = node->key + left_sum + right_sum;
}

void set_numNodes(struct node* node) {
    int left_nodes = (node->left) ? node->left->numNodes : 0;
    int right_nodes = (node->right) ? node->right->numNodes : 0;
    node->numNodes = 1 + left_nodes + right_nodes;
}

struct node* LL(struct node* x) {
    struct node* new = x->left;
    x->left = new->right;
    new->right = x;
    set_height(x);
    set_height(new);
    set_sum(x);
    set_sum(new);
    set_numNodes(x);
    set_numNodes(new);
    return new;
}

struct node* RR(struct node* x) {
    struct node* new = x->right;
    x->right = new->left;
    new->left = x;
    set_height(x);
    set_height(new);
    set_sum(x);
    set_sum(new);
    set_numNodes(x);
    set_numNodes(new);
    return new;
}

struct node* LR(struct node* x) {
    struct node* mid = x->left;
    struct node* new = mid->right;
    x->left = new->right;
    mid->right = new->left;
    new->left = mid;
    new->right = x;
    set_height(x);
    set_height(mid);
    set_height(new);
    set_sum(x);
    set_sum(mid);
    set_sum(new);
    set_numNodes(x);
    set_numNodes(mid);
    set_numNodes(new);
    return new;
}

struct node* RL(struct node* x) {
    struct node* mid = x->right;
    struct node* new = mid->left;
    x->right = new->left;
    mid->left = new->right;
    new->left = x;
    new->right = mid;
    set_height(x);
    set_height(mid);
    set_height(new);
    set_sum(x);
    set_sum(mid);
    set_sum(new);
    set_numNodes(x);
    set_numNodes(mid);
    set_numNodes(new);
    return new;
}

struct node* try_rotate(struct node* x) {
    int bal = getbalance(x);
    if (bal < -1) {
        bal = getbalance(x->right);
        if (bal > 0) {
            x = RL(x);
        } else {
            x = RR(x);
        }
    } else if (bal > 1) {
        bal = getbalance(x->left);
        if (bal < 0) {
            x = LR(x);
        } else {
            x = LL(x);
        }
    }
    return x;
}

struct node* insert(struct node* root, int key) {
    struct node* n;
    if (root == NULL) {
        root = allocate_node(key);
        return root;
    }
    if (key >= root->key) {
        root->right = insert(root->right, key);
    } else {
        root->left = insert(root->left, key);
    }
    set_height(root);
    set_sum(root);
    set_numNodes(root);
    n = try_rotate(root);
    return n;
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%lld ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node* minValueNode(struct node* root) {
    struct node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct node* delete(struct node* root, int key) {
    struct node* n;
    if (root == NULL) {
        return NULL;
    }
    if (root->key == key) {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        } else if (root->right != NULL && root->left != NULL) {
            struct node* min_node = minValueNode(root->right);
            root->key = min_node->key;
            root->right = delete(root->right, min_node->key);
        }
    } else if (root->key > key) {
        root->left = delete(root->left, key);
    } else {
        root->right = delete(root->right, key);
    }
    set_height(root);
    set_sum(root);
    set_numNodes(root);
    struct node* x = try_rotate(root);
    return x;
}

struct node* maxValueNode(struct node* root) {
    struct node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

int getSum(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->sum;
}

int getNumNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->numNodes;
}

signed main() {
    int n;
    scanf("%lld", &n);
    struct node* root = NULL;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int q;
        scanf("%lld",&q);
        root=insert(root,q);
    }

    while (getNumNodes(root) >= 2) {
        int x = minValueNode(root)->key;
        int y = maxValueNode(root)->key;
        int z = y - x;
        root = delete(root, x);
        root = delete(root, y);
        root = insert(root, z);
        printf("%lld\n", getSum(root));
    }
    return 0;
}
