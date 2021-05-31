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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int n = 3000, nsqrt = sqrt(n);
    vector<bool> isPrime(n+1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i<=nsqrt; i+=2){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
        if(i==2)    i--;
    }
    vector<int> almostPrime;
    for(int i=1; i<=n; i++){
        int count = 0;
        for(int j=2; j<=i/2; j+=2){
            if(isPrime[j] && i%j == 0)
                count++;
            if(count > 2)
                break;
            if(j==2)    j--;
        }
        if(count == 2){
            almostPrime.push_back(i);
        }
    }
    cout << binSearch(almostPrime, t)+1;
    return 0;
}
