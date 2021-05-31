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
    for(int i = 2; i<=nsqrt; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = false;
            }
        }
    }
    vector<int> afraid;
    for(int i=2; i<n; i++){
        int check = 1;
        if(isPrime[i]){
            string s = to_string(i);
            for(int j=0; j<s.size(); j++){
                if(s[j]=='0'){
                    check = 0;
                    break;
                }
                string sub = s.substr(j, s.size()-j);
                int x = stoi(sub);
                if(!isPrime[x]){
                    check = 0; 
                    break;
                }
            }
            if (check == 1){
                afraid.push_back(i);
            }
        }
    }

    while(t>0){
        cin >> n;
        t--;
        cout <<binSearch(afraid, n)+1 << "\n";
    }
    
    return 0;
}
