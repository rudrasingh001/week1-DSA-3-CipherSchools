#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode *getMiddle(ListNode *head)
    {
        ListNode *slower = head;
        ListNode *faster = head->next;
        while(faster!=NULL && faster->next!=NULL)
        {
            faster = faster->next->next;
            slower = slower->next;
        }
        return slower;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        while(curr!=NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
        {
            return true;
        }
        ListNode *middle = getMiddle(head);
        ListNode *temp = middle->next;
        middle->next = reverse(temp);
        ListNode *head1 = head;
        ListNode *head2 = middle->next;
        while(head2!=NULL)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};