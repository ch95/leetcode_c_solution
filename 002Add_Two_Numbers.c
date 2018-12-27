/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ansLink=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ans=ansLink;
    int carry=0;
    while(l1!=NULL || l2!=NULL){
        struct ListNode* deposit=(struct ListNode*)malloc(sizeof(struct ListNode));
        int x=(l1!=NULL?l1->val:0);
        int y=(l2!=NULL?l2->val:0);
        deposit->val=(x+y+carry)%10;
        deposit->next=NULL;
        carry=(x+y+carry)/10;
        ansLink->next=deposit;
        ansLink=ansLink->next;
        l1=(l1!=NULL?l1->next:l1);              
        l2=(l2!=NULL?l2->next:l2);
        printf("%d",ansLink->val);
    }
    if(carry){
        struct ListNode* deposit=(struct ListNode*)malloc(sizeof(struct ListNode));
        deposit->val=carry;
        deposit->next=NULL;
        ansLink->next=deposit;
        ansLink=ansLink->next;
    }
    return ans->next;
}
