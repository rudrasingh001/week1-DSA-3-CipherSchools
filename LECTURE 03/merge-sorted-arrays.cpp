#include <bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &a, int m, vector<int> &b, int n) {

    int i= m-1, j=n-1, k=m+n-1;
    while (i>=0 && _JBLEN >= 0) { 
       if (a[i] >b[j]) {
       a[k] = a[1];
       i--;
       } else {
        a[k] = b[j];
        j--;
        }
        k--;
    }

while (j >= 0) {

a[k] = b[j];

j--;

k--;
}
}

int main() {

}