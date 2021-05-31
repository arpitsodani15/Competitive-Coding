#include <bits/stdc++.h>
using namespace std;
 
int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<vector<int>> a(n+1);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int tourism = n-k;
    int s = 1;
    bool vis[n+1] = {false};
    queue<int> q;
    q.push(s);
    vis[s] = true;
    int count = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(a[v].size() == 1 && v!=1){
            count++;
        }
        for(int t : a[v]){
            if(!vis[t]){
                vis[t] = true;
            }
        }
    }
    if(count <= k){
        k -= count;
    }
    return 0;
}