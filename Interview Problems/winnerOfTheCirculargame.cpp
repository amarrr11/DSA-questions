/*1823. Find the Winner of the Circular Game

There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise 
order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving
 clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle 
and may count some friends more than once.
The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the
friend who just lost and repeat.
Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        // Using queue implementation
        queue<int> que;
        for(int i = 1; i <= n; i++) {
            que.push(i);
        }
        while(n > 1) {
            for(int i = 0; i < k - 1; i++) {
                que.push(que.front());
                que.pop();
            }
            que.pop();
            n--;
        }
        return que.front();
        
        // Using vector implementation
        // vector<int> arr;
        // for(int i = 1; i <= n; i++) {
        //     arr.push_back(i);
        // }
        // int i = 0;
        // while(true) {
        //     if(n == 1) return arr[0];
        //     int index = (i + k - 1) % n;
        //     arr.erase(arr.begin() + index);
        //     i = index;
        //     n--;
        // }
        // return 0;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    int n1 = 5;
    int k1 = 2;
    cout << "Winner for n = " << n1 << ", k = " << k1 << " is: " << solution.findTheWinner(n1, k1) << endl;

    // Test case 2
    int n2 = 6;
    int k2 = 5;
    cout << "Winner for n = " << n2 << ", k = " << k2 << " is: " << solution.findTheWinner(n2, k2) << endl;

    // Test case 3
    int n3 = 10;
    int k3 = 3;
    cout << "Winner for n = " << n3 << ", k = " << k3 << " is: " << solution.findTheWinner(n3, k3) << endl;

    return 0;
}
