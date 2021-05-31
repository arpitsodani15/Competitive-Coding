#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N, K;
        cin >> N >> K;
        string S;
        cin >> S;
        int consecutive=0, check=0;
        for(int j=0; j<N; j++){
            if(S[j] == '*')
                consecutive++;
            else
                consecutive=0;
            if (consecutive>=K){
                cout << "YES" << "\n";
                check = 1;
                break;
            }
        }
        if (check==0)
            cout << "NO" << "\n";
    }
    return 0;
}
