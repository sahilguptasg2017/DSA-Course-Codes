#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node* add_to_empty(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* add_at_front(struct node *head,int data){
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return head;
}
struct node *add_at_end(struct node *head,int data){
    struct node *tp=head;
    struct node *temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->data=data;
    while(tp->next != NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}

struct node *add_at_a_position1(struct node *head,int position,int data){
    struct node *temp=head;
    struct node *temp2=head;
    struct node *newp=malloc(sizeof(struct node));
    newp->prev=NULL;
    newp->data=data;
    newp->next=NULL;
    while(position!=1){
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL){
        temp->next=newp;
        newp->prev=temp;
    }
    else{
    temp2=temp->next;
    temp->next=newp;
    temp2->prev=newp;
    newp->prev=temp;
    newp->next=temp2;
    }
    return head;
}

struct node *add_at_a_position2(struct node *head,int position,int data){
    struct node *temp=head;
    struct node *temp2=head;
    struct node *newp=malloc(sizeof(struct node));
    newp->prev=NULL;
    newp->data=data;
    newp->next=NULL;
    while(position>2){
        temp=temp->next;
        position--;
    }
    if(temp->prev==NULL){
        temp->prev=newp;
        newp->next=temp;    
    }
    else{
    temp2=temp->next;
    temp->next=newp;
    temp2->prev=newp;
    newp->prev=temp;
    newp->next=temp2;
    }
    return head;
}
struct node* creatinglist(struct node *head){
    int n,data, i;
    scanf("%d",&n);

    if(n==0){
        return head;
    }
    scanf("%d",&data);
    head=add_to_empty(head,data);

    for(i=1;i<n;i++){
        scanf("%d",&data);
        head=add_at_end(head,data);
    }

    return head;

}
struct node* del_first(struct node *head){
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}

struct node* del_last(struct node *head){
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node *temp2=temp->prev;

    temp2->next=NULL;

    free(temp);

    temp=NULL;
    return head;
}

struct node* del_intem(struct node *head,int pos){
    struct node *temp=head;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    struct node *temp2=temp->prev;
    temp2->next=temp->next;
    free(temp);
    temp=NULL;
    return head;
}

void print_data(struct node *head){
    if(head==NULL){
        printf("the list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }

}

struct node* rev(struct node *head){
    struct node *ptr1=head;
    struct node *ptr2=ptr1->next;
    ptr1->next=NULL;
    ptr1->prev=ptr2;
    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    head=ptr1;
    return head;
}


int main()
{
    struct node* head=NULL;
    /*struct node *head=malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=10;
    head->next=NULL;    
    
   struct node *head=NULL;
   struct node *ptr;
   head=add_to_empty(head,45);
   head=add_at_front(head,34);
   head=add_at_end(head,9);
   head=add_at_a_position2(head,3,3);
   ptr=head;
   */
   head=creatinglist(head);
   head=rev(head); 
   print_data(head);
   return 0;
}