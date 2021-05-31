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
    int n, k;
    cin >> n >> k;
    int nsqrt = sqrt(n);
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
    vector<int> ans;
    int first, second;
    for(int j=2; j<n; ){
        first = j;
        j++;
        while(!isPrime[j])  j++;
        second = j;
        if(isPrime[first + second + 1] && first + second + 1 <= n){
            ans.push_back(first + second + 1);
        }
    }
    if(ans.size() >= k) cout << "YES";
    else cout << "NO";
    return 0;
}
