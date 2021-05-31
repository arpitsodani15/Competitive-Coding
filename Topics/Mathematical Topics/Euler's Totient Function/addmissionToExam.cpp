#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin >> k;
    for(long long j=k; j<=2*k; j++){
        long long n = j;
        long long result = n;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        }
        if (n > 1)
            result -= result / n;
        if(result == k){
            cout << j ;
            return 0;
        }
    }
    cout << 0;
    return 0;
}

