#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *link;
};

int  count_of_nodes(struct node *head){
    int count=0;
    if(head==NULL){
        printf("link list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->link;
    }
    return count;
}
/*
void add_at_end(struct node *head,int x){
    struct node *ptr , *temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node ));

    temp->data=x;
    temp->link=NULL;
    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}*/
struct node* add_at_end(struct node *ptr,int data){
    struct node *temp=malloc(sizeof(struct node ));
    temp->data=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;    
}

void print_data(struct node *head){
    if(head==NULL){
        printf("the list is empty");
    }
    struct node *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
/*
int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=98;
    current->link=NULL;
    head->link = current;

    current=malloc(sizeof(struct node));
    current->data=3;
    current->link=NULL;
    head->link->link=current;
    add_at_end(head,56);
    print_data(head);
    return 0;
}*/
struct node* insert_at_start(struct node *head,int data){
    struct node *ptr=malloc(sizeof(struct node));
    ptr -> data=data;
    ptr -> link=NULL;

    ptr->link=head;
    head=ptr;
    return head;
}

struct node* insert_at_start_2(struct node **head,int data){
    struct node *ptr=malloc(sizeof(struct node));
    ptr -> data=data;
    ptr -> link=NULL;
    //time complexity O(1)..
    ptr->link=*head;
    *head=ptr;
}

struct node* insert_at_certain_position(struct node *head,int data,int position){
    struct node *ptr=head;
    struct node *ptr2=malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;
    
    while(position!=2){
        ptr=ptr->link;
        position--;
    }
    //O(n)  
    ptr2->link=ptr->link;
    ptr->link=ptr2;

}

struct node* del_first(struct node *head){
    if(head==NULL){
        printf("list is empty");
    }
    else{
        struct node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}

void del_end(struct node *head){
    struct node *temp=head;
    while(temp->link->link!=NULL){
        temp=temp->link;
    }
    free(temp->link);
    temp->link=NULL;
}

struct ListNode* delete_pos(struct ListNode *head, int position) {
    if (head == NULL) {
        return NULL;
    }
    else if (position <= 0) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
    else {
        int count = 0;
        struct ListNode *prev = NULL;
        struct ListNode *current = head;
        while (current != NULL && count != position) {
            prev = current;
            current = current->next;
            count++;
        }
        if (current != NULL) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            current = NULL;
        }
        else {
            printf("Invalid position %d\n", position);
        }
    }
   return head;
}      
void del_max(struct node *head){
    struct node *max=head;
    struct node *temp=head;
    struct node *prev=head;
    while(temp->link!=NULL){
        if(temp->link->data>max->data){
            max=temp->link;
            prev=temp;
        }
        temp=temp->link;
    }
    prev->link=max->link;
    free(max);
    max=NULL;
}
void del_min(struct node *head){
    struct node *min=head;
    struct node *temp=head;
    struct node *prev=head;
    while(temp->link!=NULL){
        if(temp->link->data<min->data){
            min=temp->link;
            prev=temp;
        }
        temp=temp->link;
    }
    prev->link=min->link;
    free(min);
    min=NULL;
}


struct node* delete_all(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        temp=temp->link;
        free(head);
        head=temp;
    }
    return head;
}

struct node* reverse_list(struct node *head){
    struct node *prev=NULL;
    struct node *next=NULL;
    while(head != NULL){
        next=head->link;
        head->link=prev;
        prev= head;
        head=next;
    } 
    head=prev; 
    return head;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr=head;
    ptr=add_at_end(ptr,98);
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,67);
    /*ptr=head;
    int data=89;
    insert_at_start_2(&head,data);
    ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }

    insert_at_certain_position(head,56,3);
    struct node *ptr1=head;
    while(ptr1!=NULL){
        printf("%d ",ptr1->data);
        ptr1=ptr1->link;
    }
    */
    //del_end(head);
    int pos=2;
    del_particular_position(head,pos);
    //head=reverse_list(head);
    //del_min(head);
    print_data(head);
    return 0;
}


