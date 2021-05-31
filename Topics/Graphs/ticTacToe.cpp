#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        vector<string> s(3);
        cin >> s[0];
        cin >> s[1];
        cin >> s[2];
        // if((s[0][0]==s[0][1] && s[0][1]==s[0][2]) || (s[1][0]==s[0][1] && s[1][1]==s[1][2]) 
        // || (s[2][0]==s[2][1] && s[2][1]==s[2][2]) || (s[0][0]==s[1][1] && s[1][1]==s[2][2]) 
        // || (s[0][2]==s[1][1] && s[1][1]==s[2][0]) || (s[0][0]==s[1][0] && s[1][0]==s[2][0])
        // || (s[0][1]==s[1][1] && s[1][1]==s[2][1]) || (s[0][2]==s[1][2] && s[1][2]==s[2][2])){
        //     cout << "no\n";
        //     continue;
        // }
        int x=0, o=0;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(s[i][j]=='X')    x++;
                else if(s[i][j]=='O')   o++;
            }
        }
        if(o>x || (x-o) > 1){
            cout << "no\n";
        }
        else
            cout << "yes\n";
    }
    
    
    return 0;
}
