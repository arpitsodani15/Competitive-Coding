#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        for(int i=0; i<n-1; i++){
            int mi;
            cin >> mi;
            while (mi--){
                int temp;
                cin >> temp;
                a[i].push_back(temp-1);
            }
            sort(a[i].begin(), a[i].end());
        }
        int s=0;
        vector<int> vis(n, false);
        queue<int> q;
        q.push(s);
        vis[s] = true;
        vector<int> ans;
        int k=n-1;
        vector<int> parent(n);
        parent[s] = -1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            int check = 0;
            for(int i=0; i<a[v].size(); i++){
                if(!vis[a[v][i]]){
                    q.push(a[v][i]);
                    vis[a[v][i]] = true;
                    parent[a[v][i]] = v;
                }
                if(a[v][i]==k){
                    check = 1;
                    break;
                }
            }
            if(check == 1)
                break;
        }
        for(int u=parent[k]; u!=-1; u=parent[u])
            ans.push_back(u);
        if(vis[n-1]){
            cout << ans.size() << "\n";
            for(int i=ans.size()-1; i>=0; i--){
                cout << ans[i]+1 << " ";
            }
            cout << "\n";
        }
        else cout << -1 << "\n";
        cout << "\n";
    }
    return 0;
}
