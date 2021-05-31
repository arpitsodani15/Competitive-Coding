#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cin >> line;
    if (line.length()<=1){
        cout << 0;
        return 0;
    }
    int sum=0;
    for (int i=0; i<line.length(); i++){
        sum += line[i] - '0';
    }
    if(sum/10 == 0){
        cout << 1;
        return 0;
    }
    int count = 1;
    int n = sum;
    while(1){
        count++;
        int a = n/100000;
        n -= a*100000;
        int b = n/10000;
        n -= b*10000;
        int c = n/1000;
        n -= c*1000;
        int d = n/100;
        n -= d*100;
        int e = n/10;
        n -= e*10;
        n = a+b+c+d+e+n;
        if(n/10==0){
            break;
        }
    }
    cout << count;
    return 0;
}
