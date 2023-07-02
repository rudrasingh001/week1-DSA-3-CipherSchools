
// 20. Valid Parentheses

class Solution {
public:
    bool isMatching(char open, char close){
        return ((open=='(' && close == ')') ||
                (open=='{' && close=='}') ||
                (open =='[' && close==']'));
    }
    bool isOpen(char ch){
        return (ch=='(' || ch=='{' || ch=='[');
    }
    bool isValid(string str) {
        if(str.size()==0)return true;
        else if(str.size() & 1){
            return false;
        }
        else {
            stack<char> S;
            for(int i=0;i<str.size();i++){
                if(isOpen(str[i])){
                    S.push(str[i]);
                }
                else{
                    if(S.empty())   return false;
                    if(!isMatching(S.top(),str[i])) return false;
                    S.pop();
                }
            }
            return (S.empty());
        }
    }
};

// 1963. Minimum Number of Swaps to Make the String Balanced
class Solution {
public:
    int minSwaps(string s) {
        stack<char> unbalanced;
        for(char ch:s){
            if(ch=='['){
                unbalanced.push(ch);
            }
            else{
                if(!unbalanced.empty() && unbalanced.top() == '['){
                    unbalanced.pop();
                }
                else{
                    unbalanced.push(ch);
                }
            }
        }
        // what's left is unbalanced string
        return (((unbalanced.size() /2)+1)/2);
    }
};