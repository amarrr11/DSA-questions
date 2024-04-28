//  Fahrenheit to Celsius

// Problem statement
// Ninja has been assigned to convert temperature from Fahrenheit to Celsius. He has been given a starting Fahrenheit Value (S),
// ending Fahrenheit value (E), and step size (W). Unfortunately, he does not know how to convert from Fahrenheit to Celsius.
// Please help him to find the result.
// Sample Input 1:
// 2
// 0 100 20
// 25 50 25
// Sample Output 1:
// 0 -17
// 20 -6
// 40 4
// 60 15
// 80 26
// 100 37
// 25 -3
// 50 10
// Explanation Of Sample Input 1:
// Test case 1:
// For the first test case of sample output 1, we start from Fahrenheit temperature 0 and move up to 100 with a step size of 20 
// units. For every temperature, we have a corresponding celsius temperature present in the output table.

// Test case 2:   
// For the second test case of sample output 1, we start from Fahrenheit temperature 25 and move up to 50 with a step size of 25 
// units. For every temperature, we have a corresponding celsius temperature present in the output table.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int farh) {
    return (farh - 32) * (5.0 / 9);
}

vector<vector<int>> fahrenheitToCelsius(int s, int e, int w) {
    int row = ((e - s) / w) + 1;
    int col = 2;
    vector<vector<int>> ans(row, vector<int>(2));
    int l = 0;
    while (s <= e) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int k = func(s);
                ans[i][0] = s;
                ans[i][1] = k;
            }
            s += w;
        }
    }
    return ans;
}

int main() {
    int start, end, step;
    cout << "Enter the starting temperature: ";
    cin >> start;
    cout << "Enter the ending temperature: ";
    cin >> end;
    cout << "Enter the step size: ";
    cin >> step;

    vector<vector<int>> result = fahrenheitToCelsius(start, end, step);

    cout << "Fahrenheit\tCelsius" << endl;
    for (const auto &row : result) {
        for (const auto &elem : row) {
            cout << elem << "\t\t";
        }
        cout << endl;
    }

    return 0;
}
