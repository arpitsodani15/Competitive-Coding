#include <iostream>
using namespace std;

int main() {
  int nh[2];
  for (int i=0; i<2; i++){
    cin >> nh[i];
  }
  int temp, count = 0;
  for (int i=0; i < nh[0]; i++){
    cin >> temp;
    if (temp > nh[1]){
      count += 2;
    }
    else{
      count++;
    }
  }
  cout << count;
  return 0;
}
