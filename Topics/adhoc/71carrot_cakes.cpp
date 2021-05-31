#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, t, k, d, time;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    time = (n/k)*t;
    if (n%k!=0)
        time+=t;
    if (d<time-t)
        cout<<"YES";
    else 
        cout<<"NO";

    return 0;
}
