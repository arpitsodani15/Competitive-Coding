#include <iostream>
#include<bits/stdc++.h> 
#include <cstring>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int l = s1.length();
    char a,b;
    for (int i=0; i<l; i++){
        a = s1[i];
        b= s2[i];
        if (a>=97 && a<=122){
            a=a-32;
        }
        if (b>=97 && b<=122){
            b=b-32;
        }
        if (a == b){
            continue;
        }
        else if (a > b){
            cout << "1";
            return 0;
        }
        else {
            cout << "-1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}
