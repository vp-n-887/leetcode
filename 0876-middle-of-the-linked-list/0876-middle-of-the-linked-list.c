/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {

    struct ListNode* t1=head;
    struct ListNode* t2=head;

    while(t2!=NULL&&t2->next!=NULL)
    {
        t1=t1->next;
        t2=t2->next->next;
    }
    return t1;
    
}