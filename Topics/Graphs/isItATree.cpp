#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector <int>> a(n);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }

    vector<bool> vis(n, false);
    int s, count = 0;
    for(int t=0; t<n; t++){
        if(!vis[t]){
            s = t;
            vis[s] = true;
            stack<int> stck;
            stck.push(s);
            while(!stck.empty()){
                int v = stck.top();
                stck.pop();
                for(int i=0; i<a[v].size(); i++){
                    if(!vis[a[v][i]]){
                        vis[a[v][i]] = true;
                        stck.push(a[v][i]);
                    }
                }
            }
            count++;
        }
    }
    if(count == 1 && m==n-1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
