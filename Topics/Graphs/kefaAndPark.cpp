#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> cats(n+1);
    for(int i=1; i<n+1; i++){
        cin >> cats[i];
    }
    vector<vector<int>> a(n+1);
    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int s = 1;
    queue<int> q;
    int count[n+1] = {0};
    q.push(s);
    if(cats[s]==1)  count[s]++;
    int paths = 0, check=0;
    bool vis[n+1] = {false};
    vis[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(a[v].size()==1 && v!=1){
            paths++;
        }
        for(int i: a[v]){
            if(!vis[i]){
                if(cats[v]==1 && cats[i]==1){
                    count[i] = count[v]+1;
                }
                else if(cats[i]==1){
                    count[i] = 1;
                }
                else{
                    count[i]=0;
                }
                if(count[i] <=m)
                    q.push(i);
                vis[i] = true;
            }
        }
        
    }
    cout << paths;
    return 0;
}
