#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define M 150
#define N 100000
 
struct Node{
    char name[M];
    struct Node* child[20];
    struct Node* parent;
};
 
typedef struct Node Node;
 
Node* root;
Node* root1;
 
 
void Sorting(){
    int n = 0;
    while(n < 20 && root1->child[n] != NULL)
    {
        ++n;
    }
 
    for(int i = 1; i < n; ++i){
        for(int j = i-1; j >= 0; --j){
            if(strcmp(root1->child[j]->name,root1->child[j+1]->name) > 0){
                Node* new1 = root1->child[j];
                root1->child[j] = root1->child[j+1];
                root1->child[j+1] = new1;
            }
        }
    }
}
 
void pw(Node* new){
    if(new->parent == NULL){
        printf("%s",new->name);
        return;
    }
    pw(new->parent);
    printf("/%s", new->name);
}
 
void rm(){
    char name[M];
    scanf("%s",name);
    scanf("%s",name);
    
    for(int i = 0; i < 20; ++i){
        if(root1->child[i] == NULL){
            printf("-1\n");
            return;
        }
        if(strcmp(name, root1->child[i]->name)==0){
            free(root1->child[i]->name);
            for(int j = i; j + 1 < 20; ++j){
                root1->child[j] = root1->child[j+1];
            }
            root1->child[19] = NULL;
            return;
        }
    }
 
    printf("-1\n");
}
 
void ls(){
    Sorting();
    int i;
    for(i = 0; i < 20; ++i){
        if(root1->child[i] == NULL) 
            break;
        printf("%s ", root1->child[i]->name);
    }
 
    printf("\n");
}
 
void cd(){
    char name[M];
    scanf("%s",name);
 
    if(strcmp(name,"..")==0){
        if(root1->parent != NULL)
            root1 = root1->parent;
        else
            printf("-1\n");
        return;
    }
 
    int i = 0;
    while(i < 20 && root1->child[i] != NULL){
        if(strcmp(name, root1->child[i]->name)==0){
            root1 = root1->child[i];
            return;
        }
        ++i;
    }
 
    printf("-1\n");
}
 
void mk(){
 
    char name[M];
    scanf("%s",name);
    Node* new = (Node*) malloc(sizeof(Node));
 
    strncpy(new->name, name, M);
    new->parent = root1;
    for(int i = 0; i < 20; ++i)
        new->child[i] = NULL;
 
    int i = 0;
    while(i < 20 && root1->child[i] != NULL){
        if(strcmp(name, root1->child[i]->name)==0){
            free(new);
            printf("-1\n");
            return;
        }
        ++i;
    }
 
    if(i == 20){
        free(new);
        printf("-1\n");
        return;
    }
 
    root1->child[i] = new;
}
 

int main(){
    root = (Node*) malloc(sizeof(Node));
    strcpy(root->name, "root");
    root->parent = NULL;
    for(int i = 0; i < 20; ++i){
        root->child[i] = NULL;
    }
    root1 = root;
    int n;
    scanf("%d", &n);
 
    char s1[M];
 
    for(int i = 0; i < n; ++i){
        if(n<=N)
            scanf("%s",s1); 
        scanf("%s",s1);
        if(strncmp(s1,"mkdir",M) == 0){
            mk();
        }
        else if(strncmp(s1,"cd",M) == 0){
            cd();
        }
        else if(strncmp(s1,"rm",M) == 0){
            rm();
        }
        else if(strncmp(s1,"pwd",M) == 0){
            pw(root1);
            printf("\n");
        }
        else if(strncmp(s1,"ls",M) == 0){
            ls();
        }
        else {
            return 1;
            }
        }
    }