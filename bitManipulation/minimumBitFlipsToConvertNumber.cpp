/*2220. Minimum Bit Flips to Convert Number

A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and
flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth
bit from the right (a leading zero) to get 10111, etc.
Given two integers start and goal, return the minimum number of bit flips to convert start to goal.


Example 1:

Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.
Example 2:

Input: start = 3, goal = 4
Output: 3
Explanation: The binary representation of 3 and 4 are 011 and 100 respectively. We can convert 3 to 4 in 3 steps:
- Flip the first bit from the right: 011 -> 010.
- Flip the second bit from the right: 010 -> 000.
- Flip the third bit from the right: 000 -> 100.
It can be shown we cannot convert 3 to 4 in less than 3 steps. Hence, we return 3.*/

//Approach-1 (Bit by Bit check)
//T.C : O(1) , maximum we will have 30 bits(as per constraint) to represent the numbers - O(30) ~ O(1)
//S.C : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;

        while(start > 0 || goal > 0) {

            //check right most bit of both if they are equal or not
            if((start & 1) != (goal & 1)) {
                count++;
            }

            //rule out the right most bit
            start = (start >> 1);
            goal  = (goal >> 1);
        }

        return count;
    }
};


//Approach-2 (Using XOR)
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR can easily help with that

        int XOR   = start ^ goal;
        int count = 0;

        //XOR now contains 1 bit set in positions
        //where both bits were different in start and goal
        //So, simply count those
        while(XOR) {
            count += (XOR & 1); //If the right most bit is 1

            //shift right to rule out the right most bit
            XOR = (XOR >> 1);
        }
        return count;
    }
};


//Approach-3 (Count bits in XOR using Brian Kernighan’s Algorithm)
//T.C : O(1) 
//S.C : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR can easily help with that

        int XOR   = start ^ goal;
        int count = 0;

        //XOR now contains 1 bit set in positions
        //where both bits were different in start and goal
        //So, simply count those using Brian Kernighan’s Algorithm
        while(XOR) {
            XOR = XOR & (XOR-1);
            //shift right to rule out the right most bit
            count++;
        }
        return count;
    }
};


//Approach-3 (count bits in XOR using __builtin_popcount())
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int minBitFlips(int start, int goal) {
        //Basically we only have to count the bit positions where they both differ
        //XOR can easily help with that

        int XOR   = start ^ goal;
        return __builtin_popcount(XOR); //simply count bits
    }
};