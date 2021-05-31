#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector <int>> a(n);
    for(int i = 0; i < n-1;++i){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
    int x;
    cin >> x;
    int s = 0;
    vector<int> level(n);
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(s);
    level[s] = 0;
    vis[s] = true;
    int count = 0;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0; i<a[p].size(); i++){
            if(!vis[a[p][i]]){
                level[a[p][i]] = level[p] + 1;
                q.push(a[p][i]);
                vis[a[p][i]] = true;
            }
        }

    }
    for(int i=0; i<n; i++)
        if(level[i]==x-1) count++;
    cout << count;

    return 0;
}
