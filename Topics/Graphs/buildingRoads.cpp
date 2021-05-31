#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    bool vis[n+1] = {false};
    int s;
    vector<int> nodes;
    for(int t=1; t<=n; t++){
        if(!vis[t]){
            nodes.push_back(t);
            s = t;
            vis[s] = true;
            stack<int> stck;
            stck.push(s);
            while(!stck.empty()){
                int v = stck.top();
                stck.pop();
                for(int i : a[v]){
                    if(!vis[i]){
                        vis[i] = true;
                        stck.push(i);
                    }
                }
            }
        }
    }
    cout << nodes.size() - 1 << "\n";
    for(int i=0; i<nodes.size()-1; i++)
        cout << nodes[i] << " " << nodes[i+1] << "\n";
    return 0;
}
