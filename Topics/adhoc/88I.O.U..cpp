#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int person[n];
    fill_n(person, n, 0);
    for (int i=0; i<m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        person[a-1] -= c;
        person[b-1] += c;
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        if(person[i] > 0)
            sum += person[i];
    }
    printf("%d", sum);
    return 0;
}
