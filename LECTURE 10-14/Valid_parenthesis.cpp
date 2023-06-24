#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        if(s[0] == ']' || s[0] == ')' || s[0] == '}')
        return false;
        for(char c:s)
        {
            if((brackets.empty() && c == ']') || brackets.empty() && c == ')' || brackets.empty() && c == '}')
            {
                return false;
            }
            if(c == '(' || c=='{' || c=='[')
            {
                brackets.push(c);
            }
            else if(c == ')' && brackets.top() == '(')
            {
                brackets.pop();
            }
            else if(c == '}' && brackets.top() == '{')
            {
                brackets.pop();
            }
            else if(c == ']' && brackets.top() == '[')
            {
                brackets.pop();
            }
            else if((brackets.empty()==false && c == ']') || brackets.empty()==false && c == ')' || brackets.empty()==false && c == '}')
            brackets.push(c);
        }
        if(brackets.empty()==true)
        {
            return true;
        }
        return false;

    }
};
 