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
    int level[n+1];
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            q.push(i);
            vis[i] = true;
            level[i] = 0;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(int t : a[v]){
                    if(!vis[t]){
                        vis[t] = true;
                        level[t] = level[v]+1;
                        q.push(t);
                //if adjacent have same degree than all are friends but if degree of next node is equal to 
                //current node than they all will be friend iff level is 1 or 0 as from level 2 if degree 
                //is equal than it is possible that next person is not friend with one of the ancestors of current
                        if(a[t].size()!=a[v].size() || level[t]>=2){
                            cout << "NO";
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "YES";
    
    return 0;
}
