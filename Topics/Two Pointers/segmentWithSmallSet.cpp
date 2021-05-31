#include <bits/stdc++.h>
using namespace std;
 
int n, k;
int uni = 0;
int num[100000+1] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    int l = 0;
    long long res = 0;
    for(int r=0; r<n; r++){
        num[a[r]]++;
        if(num[a[r]] == 1)
            uni++;
        while(uni > k){
            num[a[l]]--;
            if(num[a[l]] == 0)
                uni--;
            l++;
        }
        res += r-l+1;
    }
    cout << res;

    return 0;
}