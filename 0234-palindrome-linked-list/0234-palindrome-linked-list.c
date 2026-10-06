/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    
    struct ListNode* slow=head;
    struct ListNode* fast=head;

    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    //slow is the middle we have to reverse it

    struct ListNode* prev=NULL;
    struct ListNode* curr=slow;
    struct ListNode* next=NULL;

    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    //prev is the head of the reverse linked list 
    //we have to compare the prev w head

    struct ListNode* left=head;
    struct ListNode* right=prev;


    while(right!=NULL)
    {
        if(right->val!=left->val){return false;}
        left=left->next;
        right=right->next;
    }
    return true;
    
}