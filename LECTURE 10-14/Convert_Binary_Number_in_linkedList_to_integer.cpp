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
    int getDecimalValue(ListNode* head) {
        string num="";

        while(head !=NULL)
        {
            num = num + to_string(head->val);
            head = head->next;
        }
        int k=0;
        int ans = 0;
        for(int i=num.length()-1; i>=0; i--)
        {
            int rem = int(num[i]) - '0';
            ans = ans + (rem * pow(2,k));
            k++;
            
        }
        return ans;
    }
};