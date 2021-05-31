#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[2*n];
        for(int i=0; i<2*n; i++){
            cin >> a[i];
        }
        long long l = 0, r = 2*n-1, m = (r+l)/2;
        sort(a, a+2*n);
        while(l<m){
            int temp = a[l];
            a[l] = a[m];
            a[m] = temp;
            l++;
            m = (r+l)/2;
        }
        for(int i=0; i<2*n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
