#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, k, f;
        cin >> n >> k >> f;
        map<int, int> vis;
        for(int i=1; i<=n; i++){
            int s, e;
            cin >> s >> e;
            for(int j=s; j<e; j++){
                vis[j]++;
            }
        }
        
        
        if(f-vis.size() >= k){
            cout << "YES\n";
        }
        else    cout << "NO\n";
    }
    return 0;
}
