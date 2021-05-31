#include <bits/stdc++.h>
using namespace std;

string t, p;
vector<int> a;

bool f(int x){
    for(int i=0; i<x; i++){
        t[a[i]-1] = '*';
    }
    t.erase(remove(t.begin(), t.end(), '*'), t.end());
    for(int i=0, j=0; i<t.length(); i++){
        if (t[i]==p[j]) j++;
        if (j==p.length())  return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    cin >> p;
    a.resize(t.length());
    for(int i=0; i<t.length(); i++)
        cin >> a[i];
    int l=0, r=t.length()-p.length()+1;
    while(r>l+1){
        int m = (l+r)/2;
        if(f(m))    l=m;
        else    r=m;
    }
    cout << l;

    return 0;
}
