#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, r, m;
        cin >> n >> r >> m;
        vector<vector<int>> a(n);
        for(int i=0; i<r; i++){
            int x, y;
            cin >> x >> y;
            a[x-1].push_back(y-1);
            a[y-1].push_back(x-1);
        }
        vector<pair<int, int>> soldiers(m);
        for(int i=0; i<m; i++){
            int k, s;
            cin >> k >> s;
            soldiers[i] = make_pair(k, s);
        }
        
    }
    return 0;
}
