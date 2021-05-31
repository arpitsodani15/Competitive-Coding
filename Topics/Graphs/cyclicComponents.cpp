#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector <int>> a(n+1);
    for(int i=1; i<=m; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    vector<bool> vis(n+1, false);
    int cycle = 0;
    for(int t=1; t<=n; t++){
        int check = 1;
        if(!vis[t]){
            int s = t;
            vis[s] = true;
            queue<int> q;
            q.push(s);
            if(a[s].size() != 2)  check=0;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(int i: a[v]){
                    if(!vis[i]){
                        vis[i] = true;
                        q.push(i);
                        if(a[i].size() != 2)
                            check=0;
                    }
                }
            }
            if(check == 1){
                cycle++;
            }
        }
    }
    cout << cycle;
    return 0;
}
