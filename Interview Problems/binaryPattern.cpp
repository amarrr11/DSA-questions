/*Problem statement
You have been given an input integer 'N'. Your task is to print the following binary pattern for it.

Example

Pattern for 'N' = 4

1111
000
11
0
The first line contains 'N' 1s. The next line contains 'N' - 1 0s. Then the next line contains 'N' - 2 1s and so on.*/

#include <bits/stdc++.h>
using namespace std;

void printPatt(int n) {
  bool flag = true;
  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (flag == true) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    flag = !flag;
    cout << endl;
  }
}

int main() {
  int n;
  cout << "Enter the value of n: ";
  cin >> n;
  printPatt(n);
  return 0;
}
