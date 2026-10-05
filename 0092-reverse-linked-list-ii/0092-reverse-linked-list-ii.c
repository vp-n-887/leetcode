/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

   struct ListNode dummy;
   dummy.next=head;

   struct ListNode* prev=&dummy;

   for(int i=1;i<left;i++)
   {
    prev=prev->next;
   }

   struct ListNode* curr=prev->next;
   struct ListNode* next=NULL;

   for(int i=left;i<right;i++)
   {
    next=curr->next;
    curr->next=next->next;
    next->next=prev->next;
    prev->next=next;
   }

   return dummy.next;

}