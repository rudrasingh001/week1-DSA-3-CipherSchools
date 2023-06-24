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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }

        ListNode *forward = NULL;
        ListNode *prev = NULL;
        ListNode *curr = head;

        int count = 0;
        while(curr!=NULL && count<2)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count++;
        }
        if(forward!=NULL)
        {
            head->next = swapPairs(forward);
        }
        return prev;
    }
};