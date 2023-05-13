#include <stdio.h>
#include <stdlib.h>

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
    return new;
}

struct node* RR(struct node* x){
    struct node* new=x->right;
    x->right=new->left;
    new->left=x;
    set_height(x);
    set_height(new);
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
    return new;
}


struct node* try_rotate(struct node *x){
    int bal=getbalance(x);
    if(bal<-1){
        bal=getbalance(x->right);
        if(bal>0){
            x=RL(x);
        }
        else{
            x=RR(x);
        }
    }
    
    else if(bal>1){
        bal=getbalance(x->left);
        if(bal<0){
            x=LR(x);
        }
        else{
            x=LL(x);
        }
    }
    return x;
}



struct node* insert(struct node* root,int key){
    struct node *n;
    if ( root == NULL){
        root=allocate_node(key);
        return root;
    }
    if(key>=root->key){
        root->right=insert(root->right,key);
    }
    else{
        root->left=insert(root->left,key);
    }
    set_height(root);
    n=try_rotate(root);
    return n;
}

struct node* minValueNode(struct node* root){
    struct node* current=root;
    
    while(current && current->left!=NULL){
        current=current->left;
    }

    return current;

}

struct node* delete(struct node* root,int key){
    struct node *n;
    if(root==NULL){
        return NULL;
    }
    if(root->key==key){
        if(root->left==NULL){
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node *temp=root->left;
            free(root);
        }
        else if(root->right!=NULL && root->left!=NULL){
            struct node *min_node=minValueNode(root->right);
            root->key=min_node->key;
            
            root->right=delete(root->right,min_node->key);

        }

    }
    else if(root->key>key){
        root->right=delete(root->right,key);
    }

    else{
        root->left=delete(root->left,key);
    }

    set_height(root);
    struct node *x=try_rotate(root);
    return x;

}


int searchtree(struct node* root,int target){
    if(root==NULL){
        return 0;
    }
    if(root->key==target){
        return 1;
    }
    else if(root->key>target){
        return searchtree(root->left,target);
    }
    else{
        return searchtree(root->right,target);
    }

    
}




void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    root=delete(root,30);

    preorder(root);
    return 0;

}




   
    





