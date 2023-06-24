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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        while(temp!=NULL && temp->next!=NULL)
        {
            if(head->val == head->next->val)
            {
                int val = head->val;
                while(head->val == val)
                {
                    head = head->next;
                    if(head == NULL)
                    {
                        break;
                    }
                }
                temp = head;
            }
            else if(temp->val == temp->next->val)
            {
                int val = temp->val;
                while(temp->val == val && temp!=NULL)
                {
                    temp = temp->next;
                    if(temp==NULL)
                    {
                        break;
                    }
                    
                }
                prev->next = temp;
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};