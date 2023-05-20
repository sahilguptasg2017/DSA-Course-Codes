#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->key=data;
    temp->left=temp->right=NULL;
    return temp;

}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root!=NULL){
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}

struct node* insert(struct node* root,int data){
    if(root==NULL){
        return newnode(data);
    }

    if (data<root->key){
        root->left=insert(root->left,data);
    }
    else if(data>root->key){
        root->right=insert(root->right,data);
    }
    return root;
}

/*int searchtree(struct node* root,int target){
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

struct node* minValueNode(struct node* root){
    struct node* current=root;
    
    while(current && current->left!=NULL){
        current=current->left;
    }

    return current;

}
*/
/*struct node* deletion(struct node* root,int target){
    if(root==NULL){
        return root;
    }    

    if(target<root->key){

        root->left=deletion(root->left,target);

    }
    else if(target>root->key){

        root->right=deletion(root->right,target);

    }

    else{
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        
        struct node* temp=minValueNode(root->right);
        
        root->key=temp->key;
        
        root->right=deletion(root->right,temp->key);

    }

    return root;

}
*/
 

int main(int argc,char** argv){
    struct node* root=NULL;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int j=0;j<n;j++){
        root=insert(root,arr[j]);
    }
    preorder(root);
    return 0;
}