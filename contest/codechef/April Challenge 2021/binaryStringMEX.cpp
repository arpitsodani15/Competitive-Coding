#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        string S, sub="";
        cin >> S;
        for(int j=S.size()-1; j>=0; j++){
            if(S[j]=='1')
                sub.insert(0, "0");
            else
                sub.insert(0, "1");
            if(S.find(sub)==string::npos)
                break;
        }
        cout << sub << "\n";
        
    }
    return 0;
}
