#include <bits/stdc++.h>
using namespace std;

void solve(int n, int from, int aux, int to) {
    if (n == 0) return;

    solve(n - 1, from, to, aux);
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    solve(n - 1, aux, from, to);
}

long long toh(int n, int from, int to, int aux) {
    solve(n, from, aux, to);
    long long a = pow(2, n) - 1;
    return a;
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;  // Take input for the number of disks

    long long moves = toh(n, 1, 3, 2); // 1: Source rod, 2: Auxiliary rod, 3: Destination rod
    cout << "Total moves required: " << moves << endl; // Output the total moves

    return 0;
}
