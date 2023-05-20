#include <stdio.h>
#include <stdlib.h>
#define int long long 
int counter=0;
struct node
{  
    int key;
    struct node *left;
    struct node *right;
    int height;
 
};
// to get height of tree
int height(struct node* N){
    if(N==NULL){
        return 0;
    }
    return N->height;
}
 
int max(int a,int b){
    return (a>b)?a:b;
}
    
struct node* newnode(int key){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return node;
 
}    
struct node *allocate_node(int key){
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->key=key;
    root->height=0;
    root->left=NULL;
    root->right=NULL;
    return root;
}
/*
struct node* rightrotate(struct node* y){
    
    struct node* x=y->left;
    struct node* T2=x->right;
//rotation
    x->right=y;
    y->left=T2;
//channging height
    y->height=max(height(y->left),height(y->right))+1;
    x->height=max(height(x->left),height(x->left))+1;
//returning node
    return x;
 
}
*/
 
int getbalance(struct node *N){
    int l_height=N->left?N->left->height:-1;
    int r_height=N->right?N->right->height:-1;
    return l_height-r_height;
}
 
 
void set_height(struct node* node)  
{
    int l_height=(node->left)?node->left->height:-1;
    
    int r_height=(node->right)?node->right->height:-1;
    
    node->height=l_height>r_height?l_height+1:r_height+1;
 
}
 
struct node* LL(struct node* x){
    struct node* new=x->left;
    x->left=new->right;
    new->right=x;
    set_height(x);
    set_height(new);
    printf("0 1\n");
    return new;
}
 
struct node* RR(struct node* x){
    struct node* new=x->right;
    x->right=new->left;
    new->left=x;
    set_height(x);
    set_height(new);
    printf("1 0\n");
    return new;
}
 
struct node* LR(struct node* x){
    struct node *mid=x->left;
    struct node *new=mid->right;
    x->left=new->right;
    mid->right=new->left;
    new->left=mid;
    new->right=x;
    set_height(x);
    set_height(mid);
    set_height(new);
    printf("1 1\n");
    return new;
}
 
struct node* RL(struct node *x){
    struct node *mid=x->right;
    struct node *new=mid->left;
    x->right=new->left;
    mid->left=new->right;
    new->left=x;
    new->right=mid;
    set_height(x);
    set_height(mid);
    set_height(new);
    printf("1 1\n");
    return new;
}
 
 
struct node* try_rotate(struct node *x ){
    int bal=getbalance(x);
    if(bal<-1){
        bal=getbalance(x->right);
        if(bal>0){
            x=RL(x);
           // printf("1 1\n");
        }
        else{
            x=RR(x);
            //printf("1 0\n");
        }
        counter++;
    }
    
    else if(bal>1){
        bal=getbalance(x->left);
        if(bal<0){
            x=LR(x);
           // printf("1 1\n");
        }
        else{
            x=LL(x);
         //   printf("0 1\n");
        }
        counter++;
    }
    return x;
}
 
 
 
struct node* insert(struct node* root,int key){
    struct node *n;
    if ( root == NULL){
        root=allocate_node(key);
        //printf("0 0\n");
        return root;
    }
    if(key>=root->key){
        root->right=insert(root->right,key);
    }
    else{
        root->left=insert(root->left,key);
    }
    //int counter=0;
    set_height(root);
    n=try_rotate(root);
 
    return n;
}
 
 
 
 
 
struct node* search_avl(struct node* root ,int key)
{
 
  if(root==NULL){
    return NULL;
  }
  
 
  if(root->key==key){
    return root;
  }
  else if(root->key<key){
    search_avl(root->right,key);
  }
  else{
    search_avl(root->left,key);
    }
}
 
int sumSubtree(struct  node* node) {
    if (node == NULL)
        return 0;
 
    return node->key + sumSubtree(node->left) + sumSubtree(node->right);
}
 
 
 
signed main() {    
 
    struct node* root = NULL;
    int n;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        char input[10];
        scanf("%s",input);
        if(input[0]=='i'){
            int x;
            scanf("%lld",&x);
            //int leftRotations, rightRotations;
    
            //leftRotations = 0;
            //rightRotations = 0;
            if(root==NULL){
                printf("0 0\n");
                root = insert(root, x);
            }
        
            else{
                root = insert(root, x);
                if(counter==0){
                    printf("0 0\n");
                }
            }
            counter=0;
            //printf("%lld %lld\n", leftRotations, rightRotations);
        }
        else if(input[0]=='s'){
            int x;
            scanf("%lld",&x);
            struct node* node_found=search_avl(root,x);
            if(node_found!=NULL){
                printf("%lld\n",sumSubtree(node_found));
            }
            else{
                printf("NA\n");
            }
        }
    }
    return 0;
}
