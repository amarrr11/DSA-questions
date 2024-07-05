#include <bits/stdc++.h> 

int factors(int n)
{
    int totalDivisors = 0;
    for (int i = 1; i <= n; i++) {
        totalDivisors += n / i;
    }

    return totalDivisors % 2;
}
/*
2.int  cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                cnt++;
                if((i/j)!=j){
                    cnt++;
                }
            }
        }
    }
       
    return cnt%2;
*/
/*
3.vector<int> fac(n+1,0);
for(int i=1;i<=n;i++){
        for(int j=i;j*j<=n;j+=i){
            fac[j]++;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=fac[i];
    }

    return sum%2;

*/

int main() {
    // Example usage:
    int number = 12;
    int result = factors(number);
    std::cout << "Result for " << number << ": " << result << std::endl;
    
    return 0;
}
