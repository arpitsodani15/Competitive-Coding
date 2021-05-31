#include <iostream>
#define INFI 1000000000
using namespace std;

int main() {
    long long int n, m, xc, yc;
    cin >> n >> m;
    cin >> xc >> yc;
    long long int k, count=0;
    cin >> k;
    long long int dx, dy;
    for (int i=0; i<k; i++){
        cin >> dx >> dy;
        int q, r;
        if (dx>0)
            q = (n-xc)/dx;
        if (dy>0)
            r = (m-yc)/dy;
        if (dx<0)
            q = (1-xc)/dx;
        if (dy<0)
            r = (1-yc)/dy;
        if (dx!=0 && dy!=0) {
            int p = min(q,r);
            xc += (p*dx);
            yc += (p*dy);
            count += p;
        }
        else if(dx!=0 && dy==0){
            xc += q*dx;
            count += q;
        }
        else if(dx==0 && dy!=0){
            yc += r*dy;
            count += r;
        }
    }
    cout << count;
    return 0;
}
