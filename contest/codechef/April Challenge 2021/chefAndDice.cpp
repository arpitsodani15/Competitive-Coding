#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int i=0; i<T; i++){
        int N;
        cin >> N;
        int layers = N/4, top = N%4;
        int sum = 0;
        sum += (layers)*(44);
        if (top==0)
            sum += 16;
        else if(top==1)
            sum += 20;
        else if(top==2)
            sum += 36;
        else if(top==3)
            sum += 53;
        cout << sum << "\n";

    }
    return 0;
}
