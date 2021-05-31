#include <algorithm>  
#include <iostream>
using namespace std;

int main() {
    long long l, r, a,b,c, count=0;
    cin >> l >> r;
    long long diff = abs(l-r), sum = l+r;
    for (long long i=l; i<=sum/2; i++) {
        for (long long j=r; j>=sum/2; j--){
            if (__gcd(i,j)!=1){
                for (long long k=i+1; k<j; k++) {
                    if (__gcd(i,k) == 1 && __gcd(k,j) == 1){
                        a=i;
                        b=k;
                        c=j;
                        count = 1;
                        break;
                    }
                }
            }
        }
    }
    if (count==1){
        cout << a << " " << b << " " << c;
    }
    else{
        cout << -1;
    }
    return 0;
}
