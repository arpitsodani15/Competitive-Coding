#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> elements;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        elements.push_back(temp);
    }
    for(int i=0; i<k; i++){
        int temp;
        cin >> temp;
        bool ans=false;
        int l=0, r=n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(elements[m]==temp){
                ans = true;
                break;
            }
            else if(elements[m]>temp)
                r = m-1;
            else
                l = m+1;
        }
        if(ans)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
