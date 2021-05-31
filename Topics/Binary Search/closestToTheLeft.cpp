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
        int l = -1, r = n, m;
        while(r>l+1){
            m = (l+r)/2;
            if(elements[m] <= temp)
                l=m;
            else
                r=m;
        }
        cout << l+1 << "\n";
        
    }
    return 0;
}
