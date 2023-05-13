#include <stdio.h>
#include <stdlib.h>
#define C 10
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* addnode(int data){
    struct node* node=malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;


    return(node);
}
void printbt(struct node* root,int space){
    if(root==NULL){
        return;
    }
    space+=C;
    printbt(root->right,space);
    printf("\n");
    for(int i=C;i<space;i++){
        printf(" ");
    }
    printf("%d\n",root->data);
    printbt(root->left,space);
    
}

void printbt1(struct node* root){
    printbt(root,0);
}

int main(){
    struct node* root=addnode(1);
    root->left=addnode(2);
    root->right=addnode(3);
    root->left->left=addnode(4);
    printbt1(root);
    return 0;
}