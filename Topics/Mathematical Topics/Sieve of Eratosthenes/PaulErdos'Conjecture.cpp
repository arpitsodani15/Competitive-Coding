#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int> a, int x){
    int l=-1, r=a.size();
    while(r>l+1){
        int m = (l+r)/2;
        if(a[m]<=x) l=m;
        else    r=m;
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 10000000, nsqrt = sqrt(n);
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
    vector<int> primes;
    for(int x=1; x<=nsqrt; x++){
        for(int y=1; y<=(int)sqrt(nsqrt); y++){
            long long num = (x*x)+(y*y*y*y);
            if(num <= n && isPrime[num]){
                primes.push_back(num);
            }
        }
    }
    int t;
    cin >> t;
    sort(primes.begin(), primes.end());
    vector<int>::iterator ip = unique(primes.begin(), primes.end());
    primes.resize(distance(primes.begin(), ip));
    while(t>0){
        cin >> n;
        t--;
        cout << binSearch(primes, n)+1 << "\n";
    }
    
    return 0;
}
