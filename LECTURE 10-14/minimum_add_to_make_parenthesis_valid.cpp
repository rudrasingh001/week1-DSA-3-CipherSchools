#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        for(int i=0; i<s.length(); i++)
        {
            char ch = s[i];
            if(ch == '(')
            {
                stack.push(ch);
            }
            else if(stack.empty() || stack.top()== ch)
            {
                stack.push(ch);
            }
            else
            {
                stack.pop();
            }
        }
        if(stack.empty())
    {
        return 0;
    }
    int count =0;
    while(!stack.empty())
    {
        count++;
        stack.pop();
    }
    return count;
    }
    
};