#include <bits/stdc++.h>
using namespace std;

int n, k;
long long mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    
    long long res = 1;
    a = a % mod;
    while (b > 0) {
        if (b & 1)  // if checks if current power in sequence is even or odd
            res = res * a % mod;  // multiplying result with power of a
        a = a * a % mod;  // finding next power of a as a result of squaring with itsef
        b >>= 1;    // right shifting bits of b each time to finally result in 
    }
    return res % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    if(n%2!=0){
        cout << -1;
        return 0;
    }
    
    vector<vector<int>> a(n+1);
    for(int i=1; i<=n-1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool vis[n+1] = {false};
    int count = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            stack<int> q;
            q.push(i);
            vis[i];
            while(!q.empty()){
                int v = q.top();
                q.pop();
                for(int t : a[v]){
                    if(!vis[t]){
                        vis[t] = true;
                        q.push(t);
                        if(a[t].size()%2==0 && a[v].size()%2==0){
                            a[t].erase(remove(a[t].begin(), a[t].end(), v));
                            a[v].erase(remove(a[v].begin(), a[v].end(), t));
                            count++;
                        }
                    }
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            int node = 0;
            queue<int> q;
            q.push(i);
            vis[i];
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(int t : a[v]){
                    if(!vis[t]){
                        vis[t] = true;
                        q.push(t);
                        node++;
                    }
                }
            }
            if(node%2!=0){
                cout << -1;
                return 0;
            }
        }
    }
    if(count>0)
        cout << count;
    else cout << 0;
    
    return 0;
}