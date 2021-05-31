#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    map<pair<int, int>, bool> vis;
    for(int i=0; i<n; i++){
        cin >> a[i];
        for(int j=0; j<m; j++){
            vis.insert(make_pair(make_pair(i, j), false));
        }
    }
    int finalsheep = 0, finalwolf = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int sheep=0, wolf=0;
            if((a[i][j]=='.' || a[i][j]=='k' || a[i][j]=='v') && !vis[make_pair(i, j)]){
                pair<int, int> start = make_pair(i, j);
                queue<pair<int, int>> q;
                q.push(start);
                vis[start] = true;
                if(a[i][j]=='k')    sheep++;
                else if(a[i][j]=='v')   wolf++;
                while(!q.empty()){
                    pair<int, int> v = q.front();
                    q.pop();
                    vector<pair<int, int>> close{make_pair(v.first, v.second)};
                    if(v.first-1>=0) close.push_back(make_pair(v.first-1, v.second));
                    if(v.first+1<n) close.push_back(make_pair(v.first+1, v.second));
                    if(v.second-1>=0) close.push_back(make_pair(v.first, v.second-1));
                    if(v.second+1<m) close.push_back(make_pair(v.first, v.second+1));
                    for(pair<int, int> k : close){
                        if(!vis[k] && (a[k.first][k.second]=='.' || a[k.first][k.second]=='k' || a[k.first][k.second]=='v')){
                            vis[k] = true;
                            q.push(k);
                            if(a[k.first][k.second]=='k')   sheep++;
                            else if(a[k.first][k.second]=='v')  wolf++;
                        }
                    }
                }
            }
            if(wolf<sheep)
                wolf = 0;
            else
                sheep = 0;
            finalsheep += sheep;
            finalwolf += wolf;
        }
    }
    cout << finalsheep << " " << finalwolf << "\n";
    
    return 0;
}
