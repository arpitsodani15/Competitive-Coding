#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        map<int, int> attempt;
        while(k--){
            int i;
            cin >> i;
            attempt[i]++;
        }
        int count=0;
        vector<int> user;
        for(map<int, int>::iterator itr = attempt.begin(); itr!=attempt.end(); itr++){
            if(itr->second > 1 && itr->first >= 1 && itr->first <= n){
                count++;
                user.push_back(itr->first);
            }
        }
        cout << count << " ";
        for(int i : user)
            cout << i << " ";

        cout << "\n";
    }
    return 0;
}
