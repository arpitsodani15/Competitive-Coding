#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    int onesss=0, twosss=0, zerosss=0;
    for(int ii = 0; ii<N; ii++){
        int temppp;
        cin >> temppp;
        if(temppp == 0)
            zerosss++;
        else if(temppp == 1)
            onesss++;
        else if(temppp == 2)
            twosss++;
    }
    for(int i=0; i<onesss; i++)
        cout << 1 << " ";
    for(int i=0; i<zerosss; i++)
        cout << 0 << " ";
    for(int i=0; i<twosss; i++)
        cout << 2 << " ";
    
    return 0;
}
