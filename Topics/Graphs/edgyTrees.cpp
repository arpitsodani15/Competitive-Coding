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
    cin >> n >> k;
    vector<vector<int>> a(n+1);
    for(int i=1; i<=n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if(z==0){
            a[x].push_back(y);
            a[y].push_back(x);
        }
    }
    bool vis[n+1] = {false};
    vector<int> redNodes; //stores number of nodes in each part of graph which have no black edges
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            int node = 0;
            queue<int> q;
            q.push(i);
            node++;
            vis[i] = true;
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
            redNodes.push_back(node);
        }
    }
    long long totalRed = 0;
    for(int i : redNodes){
        totalRed += binpow(i, k);
    }
    totalRed = totalRed % mod;
    long long total = binpow(n, k);
    if(total - totalRed < 0)
        cout << (total - totalRed + mod);
    else 
        cout << (total - totalRed);
    return 0;
}