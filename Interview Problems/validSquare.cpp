/*
593. Valid Square

Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
A valid square has four equal sides with positive length and four equal angles (90-degree angles).

Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getSum(vector<int> &p,vector<int> &q){
        return ((p[0]-q[0])*(p[0]*q[0]) + (p[1]-q[1])*(p[1]-q[1]));
        //get the distance of the two points
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> st; //store all the distance in the set.There must be only two equal distances those of disgonal and sides

        s.insert(getSum(p1,p2));
        s.insert(getSum(p1,p3));
        s.insert(getSum(p1,p4));
        s.insert(getSum(p2,p3));
        s.insert(getSum(p2,p4));
        s.insert(getSum(p3,p4));
       
        if(s.size()==2 && !s.count(0)){ //2 unique length and no distance is 0(it means points are intersecting) nd count of 0 is negative
            return true;
        }
        return false;

    }
};

int main() {
    vector<int> p1(2), p2(2), p3(2), p4(2);

    cout << "Enter coordinates for point 1 (x1 y1): ";
    cin >> p1[0] >> p1[1];

    cout << "Enter coordinates for point 2 (x2 y2): ";
    cin >> p2[0] >> p2[1];

    cout << "Enter coordinates for point 3 (x3 y3): ";
    cin >> p3[0] >> p3[1];

    cout << "Enter coordinates for point 4 (x4 y4): ";
    cin >> p4[0] >> p4[1];

    Solution solution;
    if (solution.validSquare(p1, p2, p3, p4)) {
        cout << "The points form a valid square." << endl;
    } else {
        cout << "The points do not form a valid square." << endl;
    }

    return 0;
}