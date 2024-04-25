// 415. Add Strings
// Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

// You must solve the problem without using any built-in library for handling large integers (such as BigInteger). 
// You must also not convert the inputs to integers directly.

// Approach
// Here we will first take the smaller string and run a while loop,then we will start adding from the right side cause
// thats how we do addition.We will also take a int carry bit to store the carry part.Now w will begin from the right 
// side of both the string and convert them into integers so as to add them and then we will separate the part to be 
// added to the answer string, by dividing it by 10 and doing modulo(%) gives us the carry part.Then will will continue
// moving to the left part until the storter string exist.Then we will run a loop for the rest of the longer string by
// the same method.Then it might happen that carry will be there if the string length is 0 then we will add 1 to the 
// answer string.

#include <iostream>
#include<algorithm>
// #include "Solution.h" 

using namespace std;
class Solution {
public:
    string add(string num1,string num2){
        string ans;
        int index1=num1.size()-1;
        int index2=num2.size()-1;
        int sum=0;
        int carry=0;
        while(index2>=0){
            sum=(num1[index1]-'0')+(num2[index2]-'0')+carry;
            carry=sum/10;
            char ch='0'+sum%10;
            ans+=ch;
            index2--;
            index1--;
        }
        while(index1>=0){
            sum=(num1[index1]-'0')+carry;
            carry=sum/10;
            char ch='0'+sum%10;
            ans+=ch;
            index1--;
        }
        if(carry){
            ans+='1';

        }
        reverse(ans.begin(),ans.end());
     
        return ans;

    }
    string addStrings(string num1, string num2) {
        if(num1.size()>num2.size()){
            return add(num1,num2);
        }
        else{
            return add(num2,num1);
        }
       
    }
};

int main() {
    Solution solution;
    string num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    string result = solution.addStrings(num1, num2);

    cout << "The sum of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}