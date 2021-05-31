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
    int n = 1e5;
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3; i<=n; i+=2){
        int check = 0;
        for(int j = 1; j<= sqrt(i); j++){
            if(i%j==0)  check = 1;
        }
        if(check==0)    primes.push_back(i);
    }
    vector<char[20]> all(primes.size());
    for(int i = 0; i<primes.size(); i++){
        itoa(primes[i], all[i], 2);
    }
    int t;
    cin >> t;
    while(t){
        t--;
        cin >> n;
        int sum = 0;
        for(int i=0; i<n/20; i++){
            int c = count(all[i], all[i]+20, '1');
            if(i)
            sum += c;
        }
        cout << sum;
    }
    return 0;
}
