#include <bits/stdc++.h>
using namespace std;

int k, n;
vector<int> a;
bool f(){
    int check = 0;
    for(int i=0; i<n; i++){
        if(a[i]==0)
            check++;
    }
    if(n - check < k)
        return false;
    else 
        return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    a.resize(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    int count = 0;
    while(f()){
        sort(a.begin(), a.end(), greater<>());
        int sub = ceil((float)a[k-1]/2);
        for(int i=0; i<k; i++){
            a[i] -= sub;
        }
        count += sub;
    }
    cout << count;
    return 0;
}
