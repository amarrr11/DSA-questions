/*f(n)=100f(n-3)+29f(n-1)+11f(n-2)+26

*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int *matrixPow(int *matrix,int pow){
        int *res=getIdentityMatrix();
        while(pow){
            if(pow&1){
                res=matrixMult(res,matrix,4);
            }
            pow=pow>>1;
            matrix=matrixMulti(matrix,matrix,4);
        }
        return res;
    }
    int f(int n{
        if(n==0) return 2;
        if(n==1) return 1;
        if(n==2) return 1;
        int *M=getInitialMatrix();
        M=matrixPow(m,n-2);

        return (*get(M,4,0,0))*(*get(M,4,0,1))*(*get(M.4.0,2)*(*get(M,)))
    })
}