#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 1e8, nsqrt = sqrt(n);
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i =2; i<=nsqrt; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(isPrime[i]){
            count++;
            if(count%100 == 1)
                cout << i << "\n";
        }
    }
    return 0;
}
