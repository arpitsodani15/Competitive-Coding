#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++){
        scanf("%d ", &a[i]);
    }
    for(int j=0; j<m; j++){
        scanf("%d ", &b[j]);
    }
    int i=0, j=0;
    while(i<n || j<m){
        if(j == m || i<n && a[i] < b[j]){
            printf("%d ", a[i]);
            i++;
        }
        else{
            printf("%d ", b[j]);
            j++;
        }
    }
    cout << "Time Taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
