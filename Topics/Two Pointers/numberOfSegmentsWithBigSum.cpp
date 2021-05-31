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
    int l = 0;
    long long currSum = 0, res = 0;
    for(int r=0; r<n; r++){
        currSum += a[r];
        while(currSum - a[l] >= s){
            currSum -= a[l];
            l++;
        }
        if(currSum >= s)
            res += l+1;
    }
    cout << res;
    return 0;
}