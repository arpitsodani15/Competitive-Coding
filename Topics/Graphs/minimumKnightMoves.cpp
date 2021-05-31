#include <bits/stdc++.h>
using namespace std;
 
int n, m;
 
bool isValid(int x, int y){
    if(x>=8 || x<0 || y>=8 || y<0)
        return false;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<int> dx{2, 2, -2, -2, 1, 1, -1, -1}, dy{1, -1, 1, -1, 2, -2, 2, -2};
    while(t--){
        char a, b;
        int x, y;
        cin >> a >> x;
        cin >> b >> y;
        pair<int, int> start((int)a-'a', x-1), end((int)b-'a', y-1);
        if(start==end){
            cout << 0 << "\n";
            continue;
        }
        vector<vector<bool>> vis(8, vector<bool>(8, false));
        vector<vector<int>> dist(8, vector<int>(8, 1000));
        queue<pair<int, int>> q;
        q.push(start);
        dist[start.first][start.second] = 0;
        vis[start.first][start.second] = true;
        bool done = false;
        while(!q.empty()){
            pair<int, int> v = q.front();
            q.pop();
            for(int i=0; i<8; i++){
                int x = v.first+dx[i], y = v.second+dy[i];
                if(isValid(x,y) && !vis[x][y] && dist[x][y] > dist[v.first][v.second]+1){
                    dist[x][y] = dist[v.first][v.second]+1;
                    vis[x][y] = true;
                    q.push({x, y});
                }
                if(make_pair(x, y) == end){
                    done = true;
                    break;
                }
            }
            if(done){
                break;
            }
        }
        cout << dist[end.first][end.second] << "\n";
    }
    return 0;
}