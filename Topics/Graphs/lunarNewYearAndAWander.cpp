#include <bits/stdc++.h>
using namespace std;
 
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    bool vis[n+1] = {false};
    vector<vector<int>> a(n+1);
    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        int v = q.top();
        cout << v << " ";
        q.pop();
        for(int t : a[v]){
            if(!vis[t]){
                q.push(t);
                vis[t] = true;
            }
        }
    }
    return 0;
}