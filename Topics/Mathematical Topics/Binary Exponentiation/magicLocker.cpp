#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1, n =1e9 + 7;
    a = a%n;
    while (b > 0) {
        if (b & 1)  
            res = res * a % n;  
        a = a * a % n; 
        b >>= 1;   
    }
    return res % n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long c;
    cin >> c;

    while(c>0){
        long long x;
        cin >> x;
        long long a = x/3, b = x - (a*3);
        if (x%3==1){
            res *= 
        }
        long long res = binpow(3, a) * b, n=1e9 + 7;
        cout << res % n;
        c--;
    }
    return 0;
}

