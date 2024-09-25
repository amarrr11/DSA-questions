// // Online C++ compiler to run C++ program online
// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main() {

//     long long n;
//     cin>>n;
    
//     vector<long long> v;
//     for(long long i=1;i<=n;i++){
//         v.push_back(i);
//     }

//     long long sum = 1LL * n * (n + 1) / 2;
    
//     if(sum%2!=0){
//         cout<<"NO"<<endl;
//         return 0;
//     }
    
//     cout<<"YES"<<endl;
    
//     vector<long long > arr;
//     vector<long long> arr2;
    
//     long long num=sum/2;
    
//     long long s=0;
   
//     for(long long i=n-1;i>=0;i--){
//         if(s+v[i]>num){
//             i--;
//         }else{
//             s+=v[i];
//             arr.push_back(v[i]);
//             v[i]=-1;
//         }
//     }

//     for(long long i=0;i<n;i++){
//         if(v[i]!=-1){
//             arr2.push_back(v[i]);
//         }
//     }

//        cout<<arr.size()<<endl;
//        for(long long i=0;i<arr.size();i++){
//            cout<<arr[i]<<" ";
//        }
//        cout<<endl;
//        cout<<arr2.size()<<endl;
//        for(long long i:arr2){
//            cout<<i<<" ";
//        }
//        cout<<endl;

    

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num; 
    cin >> num;

    // Calculate the total sum of first `num` natural numbers
    long long total_sum = 1LL * num * (num + 1) / 2;

    // If the total sum is odd, it is impossible to split it into two equal parts
    if (total_sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        long long half_sum = total_sum / 2;
        vector<int> mark(num + 1, 0);  // To mark the elements in the first subset

        int idx = num;
        long long size = 0;

        // Fill the first subset greedily from the largest element down to 1
        while (half_sum > 0) {
            if (half_sum >= idx) {
                half_sum -= idx;
                mark[idx] = 1;  // Mark the element as part of the first subset
                ++size;  // Increment size of the first subset
            }
            --idx;
        }

        // Output the size of the first subset
        cout << size << endl;

        // Output the elements of the first subset
        for (int i = 1; i <= num; ++i) {
            if (mark[i]) cout << i << " ";
        }
        cout << endl;

        // Output the size of the second subset
        cout << num - size << endl;

        // Output the elements of the second subset
        for (int i = 1; i <= num; ++i) {
            if (!mark[i]) cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}