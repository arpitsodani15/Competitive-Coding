#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int j=0; j<m; j++){
        cin >> b[j];
    }
    int i=0, j=0;
    long long c1 = 1, c2 = 1, count = 0;
    while(i<n || j<m){
        if(a[i]==b[j]){
            while(i+c1<n && a[i+c1]==b[j]){
                c1++;
            }
            while(j+c2<m && a[i]==b[j+c2]){
                c2++;
            }
            j += c2;
            i += c1;
            count += c1*c2;
            c1 = 1, c2 = 1;
        }
        else if(j == m || i<n && a[i] < b[j])  i++;
        else    j++;
        
    }
    cout << count;
    return 0;
}
