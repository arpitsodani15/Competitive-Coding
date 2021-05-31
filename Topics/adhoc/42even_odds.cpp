#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main() {
    long long n, k, l;
    cin >> n >> k;
    if (n%2==0){
        l = n/2;
        if (k <= l)
            cout << (2*k)-1;
        else
            cout << (k-l)*2;
        }
    else {
        l = (n/2) + 1;
        if (k <= l)
            cout << (2*k)-1;
        else
            cout << (k-l)*2;
        }
    return 0;
}
