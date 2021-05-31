#include <bits/stdc++.h>
using namespace std;

struct sta{
    vector<long long> s, smin = {LONG_LONG_MAX}, smax = {LONG_LONG_MIN};

    void push(long long x){
        s.push_back(x);
        smax.push_back(::max(x, smax.back()));
        smin.push_back(::min(x, smin.back()));
        return;
    }

    long long pop(){
        long long res = s.back();
        s.pop_back();
        smin.pop_back();
        smax.pop_back();
        return res;
    }

    bool empty(){
        return s.empty();
    }

    long long min(){
        return smin.back();
    }

    long long max(){
        return smax.back();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    int n;
    sta s1, s2;

    cin >> n >> k;
    long long a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    int l = 0;
    long long res = 0;
    for(int r=0; r<n; r++){
        long long x = a[r];
        s2.push(x);
        
        while(max(s1.max(), s2.max()) - min(s1.min(), s2.min()) > k){
            if(s1.empty())
                while(!s2.empty()){
                    s1.push(s2.pop());
                }
            s1.pop();
            l++;
        }
        
        res += r-l+1;
    }
    cout << res;

    return 0;
}