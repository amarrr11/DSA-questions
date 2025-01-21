#include <bits/stdc++.h>
using namespace std;

// Recursive function to calculate the number of ways to tile a 4xN grid
int tiling4x1(int n) {
    // Base cases
    if (n < 4) return 1;  // For n < 4, only one way (place tiles vertically)
    if (n == 4) return 2;  // For n = 4, two ways (all vertical or one horizontal row)

    // Recursion: two possibilities
    // 1. Place the last tile vertically (remaining grid is 4x(n-1))
    // 2. Place one row of tiles horizontally (remaining grid is 4x(n-4))
    return tiling4x1(n - 1) + tiling4x1(n - 4);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Number of ways to tile a 4x" << n << " grid: " << tiling4x1(n) << endl;
    return 0;
}
