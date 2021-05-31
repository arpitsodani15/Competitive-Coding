#include <bits/stdc++.h>
using namespace std;

int n;

bool f(int h, int i, int *pots){
    int sum1=h+pots[i], sum2=h;
    for(int j=i+1; i<n; i++){
        if(pots[j]>=0)  sum1+=pots[j];
        else{
            if(f(sum1, j, pots))
                sum1+=pots[j];
        }
    }
    for(int j=i+1; i<n; i++){
        if(pots[j]>=0)  sum2+=pots[j];
        else{
            if(f(sum2, j, pots))
                sum2+=pots[j];
        }
    }
    return sum1>sum2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    int health=0, count=0;
    int pots[n];
    for(int i=0; i<n; i++){
        cin >> pots[i];
    }
    // int l = 0, r = n+1, m;
    //     while(r>l+1){
    //         m = (l+r)/2;
    //         if(f(m, pots))
    //             l=m;
    //         else
    //             r=m;
    //     }
    //     cout << l;
    for(int i=0; i<n; i++){
        if(pots[i]>=0)  health+=pots[i];
        else{
            if(f(health, i, pots))
                health+=pots[i];
        }
    }
    return 0;
}
