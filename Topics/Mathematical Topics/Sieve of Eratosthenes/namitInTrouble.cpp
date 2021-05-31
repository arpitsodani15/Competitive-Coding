#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    vector<bool> arr(100001, true);
    vector<long long> primes;
    arr[0]=false;
    arr[1]=false;
    arr[2]=true;
    primes.push_back(4);
    
    int i = 4;
    while((long long)i*i<=1e10){
        arr[i]=false;
        i+=2;
    }
    for (int j = 3; (long long)j*j <=1e10; j+=2 ){
        if (arr[j]){
            primes.push_back((long long) j*j);
            for (int k = j*j; (long long)k*k<=1e10; k=k+j){
                arr[k]=false;
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n>> k;
        long long ans=0;
        long long san =0;
        if(n<=3){
            cout << 0 << " " << 0 << "\n";
        }else{
        long long l = -1;
        long long r = primes.size();
        while (r-l>1){
            long long m = l+(r-l)/2;
            if (primes[m]<=n)
                l=m;
            else
                r=m;
        }
        ans=l+1;
        l = -1;
        r = primes.size();
        while (r-l>1){
            long long m = l+(r-l)/2;
            if (primes[m]<=k)
                l=m;
            else
                r=m;
        }
        san = l+1;
        long long sodani = ans-san;
        if (sodani<0){
            sodani =0;
        }
        cout << ans << " "<< sodani <<"\n";
        }
    }
    return 0;
}