#include <bits/stdc++.h>
using namespace std;

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
    
    cin >> n;
    while(n){
        long long G = 0;
        for(int i=1; i<n; i++){
            if(lp[i] == i){
                G += (((n-i)/i)*i) + ((n-i)-(n-i)/i);
            }
            else{
                for (int j = i+1; j <= n; j++) {
                    if(lp[j]==j)
                        G += 1;
                    else{
                        int temp = i;
                        while(temp!=1){
                            if(j%lp[temp]==0){
                                G+=lp[temp];
                                temp /= lp[temp];
                            }
                        }
                    }
                }
                
            }
        }
        cout << G << "\n";
        cin >> n;
    }
    
    return 0;
}
