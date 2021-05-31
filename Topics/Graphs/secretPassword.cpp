#include <bits/stdc++.h>
using namespace std;
 
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    map<char, vector<char>> a;
    map<char, bool> vis;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        if(s.size()>1){
            for(int j=0; j<s.size()-1; j++){
                a[s[j]].push_back(s[j+1]);
                a[s[j+1]].push_back(s[j]);
                vis[s[j]] = false;
                vis[s[j+1]] = false;
            }
        }
        else{
            a[s[0]].push_back(s[0]);
            vis[s[0]] = false;
        }
    }
    int count = 0;
    for(map<char, vector<char>>::iterator itr = a.begin(); itr!=a.end(); itr++){
        if(!vis[itr->first]){
            queue<char> q;
            q.push(itr->first);
            vis[itr->first] = true;
            while(!q.empty()){
                int v = q.front();
                q.pop();
                for(char c : a[v]){
                    if(!vis[c]){
                        vis[c] = true;
                        q.push(c);
                    }
                }
            }
            count++;
        }
    }
    cout << count;
    return 0;
}