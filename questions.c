#include <stdio.h>
typedef struct node
    {
    int value;
    struct node *next;
    } Node;
/*Node *move_to_front(Node *head){
    Node *p,*q;
    if((head==NULL)||(head->next==NULL))
        return head;
    q=NULL;p= head;
    while(p->next != NULL){
        q=p;
        p=p->next;
    }    
    q->next=NULL;
    p->next=head;
    head=p;
    return head;
}*/
//function to get the last number to first.
void rearrange(struct node *list){
    struct node *p, *q;
    int temp;
    if(!list|| !list->next){
        return;
    }
    p=list; q=list->next;
    while(q){
        temp=p->value; p->value=q->value;
        q->value = temp; p = q->next;
        q=p?p->next : 0;
    }
}