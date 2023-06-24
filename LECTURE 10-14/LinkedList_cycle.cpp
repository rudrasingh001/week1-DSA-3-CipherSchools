#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
        {
            return false;
        }
        
        ListNode *faster = head;
        ListNode *slower = head;
        // ListNode *temp = head;
        while(slower!=NULL && faster!=NULL && faster->next!=NULL)
        {
            faster = faster->next->next;
            slower = slower->next;
            if(faster == slower)
            {
                return true;
            }
        }
        return false;
    }
};