#include<bits/stdc++.h>
#include <iostream>

using namespace std;
void toh(int n, char source, char aux, char dest)
{
    if(n == 0) return;
    if(n==1)
    {
        cout<<source<<" -> "<<dest<<endl;
        return ;
    }
    toh(n-1, source, dest, aux);
    toh(1, source, aux, dest);
    toh(n-1, aux, source, dest);
}

int main()
{
    int n = 3; 
    toh(n, 'A', 'B', 'C');
    return 0;
}
