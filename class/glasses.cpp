/*
Some glasses are arranged 
*/
double[][] arr=new double[][];
arr[0][0]=k;
for(int i=0;i<arr.size();i++){
    for(int j=0;j<=i;j++){
        if(arr[i][j]>1.0){
            double spare=arr[i][j]-1.0;
            arr[i][j]=1.0;
            arr[i+1][j]=spare/2.0;
            arr[i+1][j+1]=spare/2.0;
        }
    }
}