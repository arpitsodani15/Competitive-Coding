#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    if(s==g){
        cout << 0;
        return 0;
    }
    queue<int> q;
    vector<bool> vis(f+1, false);
    q.push(s);
    vis[s] = true;
    int count = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v<s && v<g || v>s && v>g)
            continue;
        int check = 1;
        if(v+u <= f && !vis[v+u]){
            q.push(v+u);
            vis[v+u] = true;
            count++;
            check = 0;
        }
        if(v-d >= 1 && !vis[v-d]){
            q.push(v-d);
            vis[v-d] = true;
            if(check!=0)
                count++;
        }
        if(vis[g]){
            cout << count;
            return 0;
        }

    }
    cout << "use the stairs";
    return 0;
}
