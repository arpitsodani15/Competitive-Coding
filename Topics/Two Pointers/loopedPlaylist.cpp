#include <bits/stdc++.h>
using namespace std;
 
long long p;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    long long mood = 0;
    int l = 0, r=0, res = INT_MAX, length = 0, minl=0;
    for(l = 0; l<n; ){
        if(mood >= p){
            if(res>length){
                res = length;
                minl = l;
            }
            mood -= a[l];
            l++;
            length--;
        }
        while(mood < p){
            if(r==n-1)
                r = 0;
            mood += a[r];
            r++;
            length++;
        }

    }
    cout << l << " " << res;
    return 0;
}