#include <bits/stdc++.h>
using namespace std;
 
long long s;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    int res = INT_MAX, l = 0;
    long long currSum = 0;
    for(int r=0; r<n; r++){
        currSum += a[r];
        while(currSum - a[l] >= s){
            currSum -= a[l];
            l++;
        }
        if(currSum >= s)
            res = min(res, r-l+1);
    }
    if(res != INT_MAX)
        cout << res;
    else    cout << -1;

    return 0;
}