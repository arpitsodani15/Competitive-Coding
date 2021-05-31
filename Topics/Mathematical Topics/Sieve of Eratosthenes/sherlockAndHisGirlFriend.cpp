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
    int n = 1e6, nsqrt = sqrt(n);
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
    if(t==1)    cout << 1 << "\n" << 1;
    else if(t==2)   cout << 1 << "\n" << 1 << " " << 1;
    else{
        cout << 2 << "\n";
        for(int i=1; i<t+1; i++){
            if(isPrime[i+1])    cout << 1 << " ";
            else    cout << 2 << " ";
        }
    }
    return 0;
}
