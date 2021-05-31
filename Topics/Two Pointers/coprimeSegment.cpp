#include <bits/stdc++.h>
using namespace std;


struct sta{
    vector<long long> s, gcd = {0};
    long long last;
    void push(long long x){
        s.push_back(x);
        gcd.push_back(__gcd(x, gcd.back()));
        return;
    }

    long long pop(){
        long long res = s.back();
        s.pop_back();
        last = res;
        gcd.pop_back();
        return res;
    }

    bool empty(){
        return s.empty();
    }

    long long _gcd(){
        return gcd.back();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    sta s1, s2;
    int l = 0;
    int res = n+1;
    for(int r=0; r<n; r++){
        s2.push(a[r]);
        while(__gcd(s1._gcd(), s2._gcd()) == 1){
            if(s1.empty())
                while(!s2.empty())
                    s1.push(s2.pop());
            s1.pop();
            if(__gcd(s1._gcd(), s2._gcd()) != 1){
                s1.push(s1.last);
                break;
            }
            l++;
        }
        if(__gcd(s1._gcd(), s2._gcd()) == 1)
            res = min(res, r-l+1);
    }
    if(res!=n+1)
        cout << res;
    else    cout << -1;

    return 0;
}