#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)  // if checks if current power in sequence is even or odd
            res = res * a;  // multiplying result with power of a
        a = a * a;  // finding next power of a as a result of squaring with itsef
        b >>= 1;    // right shifting bits of b each time to finally result in 
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int p = (2*n)-2;
    long long ans, x = binpow(4, n-3);
    long long res = x*((9*n) - 3);
    cout << res;
    return 0;
}

