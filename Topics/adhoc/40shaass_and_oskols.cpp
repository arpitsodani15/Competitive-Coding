#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++)
        cin >> a[i];
    cin >> m;
    int bird[m], wire[m];
    for (int i=0; i<m; i++)
        cin >> wire[i] >> bird[i];
    for (int i=0; i<m; i++){
        if (wire[i]>1 && wire[i]<n) {
            a[wire[i]-2] += bird[i]-1;
            a[wire[i]] += a[wire[i]-1] - bird[i];
        }
        else if (wire[i]==1)
            a[wire[i]] += a[wire[i]-1] - bird[i];
        else if (wire[i]==n)
            a[wire[i]-2] += bird[i]-1;
        a[wire[i]-1] = 0;
    }
    for (int i=0; i<n; i++) {
        cout << a[i] << "\n";
    }
    return 0;
}
