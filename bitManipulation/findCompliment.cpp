/*476. Number Complement

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary 
representation.
For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        // string s;
        // while(num){
        //     int digit=num%2;
        //     if(digit==1){
        //         s+='0';
        //     }else{
        //         s+='1';
        //     }
        //     num/=2;
        // }
        // int ans=0;
        // int index=0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='1'){
        //         ans+= static_cast<int>(pow(2,index));
        //     }
        //     index++;
        // }
        // return ans;

        //to flip each bit we use xor to xor each of the bit from right side with 1 and if its 1 it means we neeed to change to 1//
        // int numBits=(int)(log2(num))+1;
        // for(int i=0;i<numBits;i++){
        //     num^=(1<<i);
        // }
        // return num;

        //Also we can directly xor by 111 at once//

        int numBits=(int)(log2(num))+1;
        int mask=(1<<numBits)-1; //if we doing for 5 (101) then we need 111 to xor with 101, so 2^3=1000 - 1 =0111;
        return num^mask;
    }
};

int main() {
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int complement = solution.findComplement(num);
    cout << "The complement of " << num << " is " << complement << endl;

    return 0;
}
