#include <bits/stdc++.h>
using namespace std;

int n, m;

bool isValid(int x, int y){
    if(x>=n || x<0 || y>=m || y<0)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while(n!=0 || m!=0){
        vector<vector <int>> a(n, vector<int>(m));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> a[i][j];
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int s, count = 0;
        vector<int> dx{-1, 0, 1, 0}, dy{0, -1, 0, 1};
        map<int, int> slicks;
        int total=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && a[i][j]==1){
                    count = 1;
                    stack<pair<int, int>> stck;
                    stck.push({i, j});
                    vis[i][j] = true;
                    while(!stck.empty()){
                        pair<int, int> v = stck.top();
                        stck.pop();
                        for(int t=0; t<4; t++){
                            int x = v.first+dx[t], y=v.second+dy[t];
                            if(isValid(x, y) && a[x][y]==1 && !vis[x][y]){
                                stck.push({x, y});
                                vis[x][y] = true;
                                count++;
                            }
                        }
                    }
                    slicks[count]++;
                    total++;
                }
            }
        }
        cout << total << "\n";
        for(map<int, int>::iterator itr = slicks.begin(); itr!=slicks.end(); itr++){
            cout << itr->first << " " << itr->second << "\n";
        }


        cin >> n >> m;
    }
    return 0;
}
