#include <iostream>

using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
        cout << 0;
    else if (a==b && b==c && c==d)
        cout << 3;
    else if((a==b && b==c) || (a==b && b==d) || (a==c && c==d) || (b==c && c==d) || (a==b && c==d) || (a==c && b==d) || (a==d && b==c))
        cout << 2;
    else
        cout << 1;
    return 0;
}
