#include <iostream>
using namespace std;

int main() {
  int n, a=0, b=0;
  cin >> n;
  string str;
  cin >> str;
  for (int i=0; i<str.length(); i++){
    if (str[i]=='A'){
      a++;
    }
    else {
      b++;
    }
  }
  if (a > b){
      cout << "Anton";
  }
  else if (a < b){
      cout << "Danik";
  }
  else {
      cout << "Friendship";
  }
  return 0;
}
