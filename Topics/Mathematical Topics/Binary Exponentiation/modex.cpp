#include <bits/stdc++.h>
using namespace std;

long long binPowMod(long long a, long long b, long long n) {
    long long res = 1;
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
    for(long long i=0; i<c; i++){
        long long x, y, n;
        cin >> x >> y >> n;
        cout << binPowMod(x, y, n) << "\n";
    }
    
    return 0;
}

