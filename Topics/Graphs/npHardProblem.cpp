#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n+1);
    int s;
    for(int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool vis[n+1] = {false};
    int colors[n+1] = {0};
    queue<int> q;
    for(int s=0; s<n; s++){
        if(!vis[s]){
            q.push(s);
            vis[s] = true;
            colors[s] = 1;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(int i : a[v]){
                    if(colors[i]==colors[v]){
                        cout << -1;
                        return 0;
                    }
                    if(!vis[i]){
                    if(colors[v]==1)
                        colors[i] = 2;
                    else  colors[i] = 1;
                    q.push(i);
                    vis[i] = true;
                    }
                }
            }
        }
    }
    int x = 0, y = 0;
    for(int i=1; i<=n; i++){
      if(colors[i]==1) x++;
      else if(colors[i]==2)  y++;
    }
    cout << x << "\n";
    for(int i=1; i<=n; i++){
      if(colors[i]==1) cout << i << " ";
    }
    cout << "\n" << y << "\n";
    for(int i=1; i<=n; i++){
      if(colors[i]==2) cout << i << " ";
    }
    return 0;
}
