#include <bits/stdc++.h>
using namespace std;

int n, m;

int d(pair<int, int> a, pair<int, int> b){
    return abs(a.first-b.first) + abs(a.second-b.second);
}

bool isValid(int x, int y){
    return (x>=0 && x<n && y>=0 && y<=m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> a[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, n+m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j]==1){
                    ans[i][j] = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    dist[i][j] = 0;
                    vector<int> dx{1, 0, -1, 0}, dy{0, 1, 0, -1};
                    while(!q.empty()){
                        pair<int, int> v= q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            int x = v.first+dx[k], y = v.second+dy[k];
                            if(isValid(x, y) && dist[x][y] > dist[v.first][v.second]+d({x, y}, v)){
                                dist[x][y] = dist[v.first][v.second]+d({x, y}, v);
                                q.push({x, y});
                            }
                        }
                    }
                }

            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << dist[i][j];
            }

        }
    }
    
    return 0;
}
