#include<bits/stdc++.h>
using namespace std;

double solve(double x, int n)
{
    if(n==0)
    {
        return 1;
    }
    if(n == 1)
    {
        return x;
    }
    return x * solve(x, n-1);
}

double myPow(double x, int n) {
    
    if(n>=0) return solve(x, n);
    else return 1.0/solve(x, abs(n));

}

int main()
{
    double x;
    int n;
    cout<<"x = ";
    cin>>x;
    cout<<"n = ";
    cin>>n;
    double ans = myPow(x, n);
    cout<<"power(x, n) = "<<ans;
}