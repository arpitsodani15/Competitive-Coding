#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    string s, check = "bear";
    getline(cin, s);
    int curr = s.find(check), next, prev=-1, first = curr;
    int count = 0, l = s.length();
    while(curr != string::npos){
        next = s.find(check, curr+1);
        if (prev==-1){
            count += (curr+1)*(l-curr-3);
            prev = curr;
            curr = next;
        }
        else {
            count += (curr-prev)*(l-curr-3);
            prev = curr;
            curr = next;
        }
    }
    cout << count;
    return 0;
}
