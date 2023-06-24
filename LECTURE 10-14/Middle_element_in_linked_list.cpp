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
    ListNode* middleNode(ListNode* head) {
        ListNode *pro = head;
        ListNode *nobb = head;
        while(pro != NULL)
        {
            if(pro->next == NULL)
            {
                break;
            }
            pro = pro->next->next;
            nobb = nobb->next;
        }
        return nobb;
    }
};