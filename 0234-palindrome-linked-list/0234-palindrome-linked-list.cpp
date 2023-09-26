/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* previous=NULL;
        ListNode* curr=head;
        ListNode* Next;

        while(curr!=NULL) 
        {
            Next=curr->next; //Storing next to break arrow
            curr->next=previous; //Changing the direction of arrow

            previous=curr; //increment previous
            curr=Next; //increment current
        }

        head=previous; //when curr ==NULL, previous will be head;
        return head;    
    }

    bool isPalindrome(ListNode* head) {
    //Edge case
    if(head==NULL || head->next==NULL)return true;

    ListNode *slow=head;
    ListNode *fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next=reverse(slow->next);
    slow=slow->next;

    ListNode *ptr=head;

    while(slow!=NULL)
    {
        if(slow->val!=ptr->val)return false;
        slow=slow->next;
        ptr=ptr->next;
    }
    return true;
    }
};