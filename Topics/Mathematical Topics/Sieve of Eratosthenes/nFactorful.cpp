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
    int n = 1e6;
    vector<int> lp(n+1, 0), pr;
    lp[1]= 1;
    for(int i = 2; i<=n; i++){
        if(!lp[i]){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=n; j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    
    int t;
    cin >> t;
    while(t){
        t--;
        int a, b, n;
        cin >> a >> b >> n;
        vector<int> spNum;
        if(n==0 && a==1){
            cout << 1 << "\n";
            return 0;
        }
        for(int i = a; i<=b; i++){
            int curr = lp[i], count = 1, num = i;
            while(num/curr > 1){
                num = num/curr;
                curr = lp[num];
                count++;
            }
            if(count == n && lp[sqrt(i)] != sqrt(i))  spNum.push_back(i);
        }
        cout << spNum.size() << "\n";
        for(int i=0; i<spNum.size(); i++){
            cout << spNum[i] << " ";
        }
        cout << "\n";

    }
    return 0;
}

