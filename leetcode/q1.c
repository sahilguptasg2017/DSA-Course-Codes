#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
   };

int  count_of_ListNodes(struct ListNode *head){
    int count=0;
    if(head==NULL){
        return 0;
    }
    struct ListNode *ptr=NULL;
    ptr=head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->next;
    }
    return count;
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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    head=del_particular_position(head,count_of_ListNodes(head)-n);
    return head;
}    