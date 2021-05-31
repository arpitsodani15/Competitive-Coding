#include <iostream>
using namespace std;

int main() {
    string keys = "qwertyuiopasdfghjkl;zxcvbnm,./", code;
    char c;
    cin >> c;
    cin >> code;
    if (c=='L'){
        for (int i=0; i<code.length(); i++) {
            int ix = keys.find(code[i]);
            cout << keys[ix+1];
        }
    }
    else if (c=='R'){
        for (int i=0; i<code.length(); i++) {
            int ix = keys.find(code[i]);
            cout << keys[ix-1];
        }
    }
    return 0;
}
