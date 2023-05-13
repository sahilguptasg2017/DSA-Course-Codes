#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* next;
};
/*
struct node* circularSingly(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}
*/
struct node* addtoempty(int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;


} 
struct node* addatbeg(struct node* tail,int data){

    struct node *newp=malloc(sizeof(struct node));
    newp->data=data;
    newp->next=tail->next;
    tail->next=newp;
    return tail;

}

struct node* addatend(struct node* tail,int data){
    struct node* newp=malloc(sizeof(struct node));  
    newp->data=data;
    newp->next=tail->next;
    tail->next=newp;
    tail=tail->next;
    return tail;
}
struct node* atsomepos(struct node* tail,int pos,int data){
    struct node* p;
    struct node* newp=malloc(sizeof(struct node));
    p=tail->next;
    while(pos>1){
        p=p->next;
        pos--;
    }
    newp->data=data;
    /*
    newp->next=p->next;
    p->next=newp;
    */
   if(p==tail){
    newp->next=tail->next;
    tail->next=newp;
    tail=tail->next;
   }
   else{
    newp->next=p->next;
    p->next=newp;
   }
   return tail;
}
void print(struct node* tail){
    struct node* p=tail->next;
    do
    {   
        printf("%d ",p->data);
        p=p->next;
    } while (p!=tail->next);

}
struct node* del_first(struct node* tail){
    struct node* temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}
struct node* del_last(struct node* tail){
    struct node* temp=tail->next;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}
struct node* del_intm(struct node* tail,int pos,int data){
    if(tail==NULL){
        return tail;
    }
    if(tail->next=tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node *temp;
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail){
        tail=temp;
    } 
    free(temp2);
    return tail;
}
int no(struct node* tail){
    struct node* temp=tail->next;
    int count=0;
    while(temp != tail){
        count++;
        temp=temp->next;
    }
    return count;
}
int pos(int elem,struct node* tail){
    struct node* temp=tail->next;
    int ind=0;
    do{
        if(temp->data==elem){
            return ind;
        }
        temp=temp->next;
        ind++;
    }while (temp!=tail->next);
    return -1;
}
int main(){
    int data=34;
    struct node* tail;
    tail=addtoempty(45);
    tail=addatbeg(tail,34);
    tail=addatend(tail,56);
    tail=del_last(tail);
    printf("%d\n",pos(34,tail));
    printf("%d\n",no(tail));
    print(tail);

    return 0;
}

/*

struct node {
    struct node* prev;
    int data;
    struct node* next;
};


struct node *circularDoubly(int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}
int main(){
    int data=45;
    struct node *tail;
    tail=circularDoubly(data);

    printf("%d\n",tail->data);
    return 0;
}*/

