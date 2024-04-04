// Superior Elements

// There is an integer array ‘a’ of size ‘n’.
// An element is called a Superior Element if it is greater than all the elements present to its right.
// You must return an array all Superior Elements in the array ‘a’.
// Note:

// The last element of the array is always a Superior Element. 

// Example
// Input: a = [1, 2, 3, 2], n = 4
// Output: 2 3
// Explanation: 
// a[ 2 ] = 3 is greater than a[ 3 ]. Hence it is a Superior Element. 
// a[ 3 ] = 2 is the last element. Hence it is a Superior Element.
// The final answer is in sorted order.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> superiorElements(vector<int>& a) {
    vector<int> ans;
    int n = a.size();
    int max = a[n-1];
    
    for(int i = n-1; i >= 0; i--) {
        if(a[i] > max) {
            ans.push_back(a[i]);
            max = a[i];
        }
    }
    ans.push_back(a[n-1]);
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> input;
    int size, element;
    
    cout << "Enter the size of the vector: ";
    cin >> size;
    
    cout << "Enter the elements of the vector:\n";
    for (int i = 0; i < size; ++i) {
        cin >> element;
        input.push_back(element);
    }
    
    vector<int> result = superiorElements(input);
    
    cout << "Superior elements: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
