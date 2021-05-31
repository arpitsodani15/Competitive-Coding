#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        bool check = true;
        while(k--){
            string s;
            cin >> s;
            bool first = false, second = false;
            if((s[0] >= 'a' && s[0] <= 'm'))
                first = true;
            else if((s[0] >= 'N' && s[0] <= 'Z'))
                second = true;
            else{
                check = false;
            }
            for(char c : s){
                if(first && (c < 'a' || c > 'm')){
                    check = false;
                    break;
                }
                else if(second && (c < 'N' || c > 'Z')){
                    check = false;
                    break;
                }
            }
        }
        if(check)   cout << "YES\n";
        else    cout << "NO\n";
    }
    return 0;
}
