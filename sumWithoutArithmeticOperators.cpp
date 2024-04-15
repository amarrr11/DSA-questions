#include <iostream>

// Function to calculate the sum of two integers without using the + operator
int getSum ( int a, int b) {
    while(b!=0){ //take b as carry bit and check until carry is not equal to zero
        int temp=(a&b)<<1; //get the carry bit by doing & operation and left shift by 1 so that we can xor it again
        a=a^b; 
        b=temp;        
        }
    return a;
}

int main() {
    using namespace std;
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    int sum = getSum(num1, num2);

    cout << "Sum of " << num1 << " and " << num2 << " is: " << sum << endl;

    return 0;
}
