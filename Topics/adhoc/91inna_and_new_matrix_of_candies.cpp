#include <iostream>
#include <string>

using namespace std;

int turns(string * s, int n){
    int min = 1000, step = 1000;
    for(int i=0; i<n; i++){
        int G = s[i].find('G'), S = s[i].find('S');
        int diff = S-G;
        if (diff > 0 && min > diff){
            min = diff;
        }
        else if (diff < 0) {
            if (step > n-G)
                step = n-G;
        }
    }
    if (step > min)
        step = min;
    else 
        return 0;
    for(int i=0; i<n; i++){
        int G = s[i].find('G');
        s[i][G] = '*';
        s[i][G+min] = 'G';
    }
    return turns(s,n) + 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i=0; i<n; i++){
        cin >> s[i];
    }
    int turn = turns(s, n);
    cout << turn;
    return 0;
}
