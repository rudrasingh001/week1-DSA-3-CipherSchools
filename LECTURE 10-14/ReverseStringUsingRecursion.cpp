#include<bits/stdc++.h>
using namespace std;

void reverse(string &str, int start, int end)
{
    if(start>end)
        return ;
    
    swap(str[start], str[end]);
    start++;
    end--;
    reverse(str, start, end);
}


int main()
{
    string str;
    cout<<"Enter string : ";
    cin>>str;
    reverse(str,0, str.length()-1);
    cout<<"Reversed String : "<<str<<endl;

    return 0;
}