#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n;
    vector<int> elements;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        elements.push_back(temp);
    }
    cin >> k;
    sort(elements.begin(), elements.end());
    for(int i=0; i<k; i++){
        int leftnum, rightnum;
        cin >> leftnum >> rightnum;

        int l = -1, r = n, m;
        while(r>l+1){
            m = (l+r)/2;
            if(elements[m] < leftnum)
                l=m;
            else
                r=m;
        }
        int left = l;
        l = -1, r = n;
        while(r>l+1){
            m = (l+r)/2;
            if(elements[m] <= rightnum)
                l=m;
            else
                r=m;
        }
        int right = r;
        cout << right-left-1 << "\n";
    }

    return 0;
}
