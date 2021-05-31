#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long n) {
    long long res = 1;
    a = a%n;
    while (b > 0) {
        if (b & 1)  // if checks if current power in sequence is even or odd
            res = res * a % n;  // multiplying result with power of a
        a = a * a % n;  // finding next power of a as a result of squaring with itsef
        b >>= 1;    // right shifting bits of b each time to finally result in 
    }
    return res % n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long B, P, M;
    cin >> B >> P >> M;
    cout << binpow(B, P, M);   // a^b
    return 0;
}

