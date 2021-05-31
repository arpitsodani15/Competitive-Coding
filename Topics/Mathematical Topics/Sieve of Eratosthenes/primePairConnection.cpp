#include <bits/stdc++.h>
using namespace std;

bool binSearch(vector<int> a, int x){
    int l=-1, r=a.size();
    while(r>l+1){
        int m = (l+r)/2;
        if(a[m]<=x) l=m;
        else    r=m;
    }
    if (a[l] == x)  return true;
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i<=sqrt(1e9); i+=2){
        int check = 0;
        for(int j = 1; (long long)j*j<=i; j++){
            if(i%j==0)  check = 1;
        }
        if(check==0)    primes.push_back(i);
    }
    int t;
    cin >> t;
    while(t){
        t--;
        int l, r;
        cin >> l >> r;
        int sum=0;
        for(int i=l; i<=r; i++){
            if(binSearch(primes, i)){
                int first = i
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
