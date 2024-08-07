// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     //print binary representation of a number
//     /*
//     string str="";
//     int n;
//     cin>>n;
//     while(n){
//         str+=(n%2==0?"0":"1");
//         n/=2;
//     }
//     cout<<str<<endl;
//     */


//     //left shift right shift
//     // cout<<(7<<2)<<endl;


// // whether kth bit is set or not
// /*
//     int n;
//     cin>>n;
//     int k=2;
//     if(n&(1<<k)>0){
//         cout<<"set"<<endl;
//     }else{
//         cout<<"not set"<<endl;
//     }
//     */
    


// //toggle kth bit
    
//  /*   int n,n1;
//     cin>>n;
    
//     n1=n;
//     string str="";

//     while(n1){
//         str+=(n1%2==0?"0":"1");
//         n1/=2;
//     }
//     cout<<"before"<<str<<endl;

//     int k=2;
    
//     n=n^(1<<k);

//     cout<<n<<endl;
//     str="";

//     while(n){
//         str+=(n%2==0?"0":"1");
//         n/=2;
//     }
//     cout<<str<<endl;
//     */



// //toggle kth bit to 1;
// /*
//     int n;
//     cin>>n;

//     int k=2;
//     n=n|(1<<k);

//     cout<<n<<endl;
//     */


// //toggle kth bit to 0

// /*    int n;
//     cin>>n;

//     int k=2;

//     n=n&(~(1<<k));
//     cout<<n<<endl;
//     */


// //count no of set bits(n);

//  /*   cout << __builtin_popcount(4) << endl;
//     cout << __builtin_popcount(15);
//     */


// //swap 2 numbeers using bit manipulation
// /*
//     int a=4;
//     int b=12;

//     a=a^b;
//     b=a^b;
//     a=a^b;

//     cout<<a<<" "<<b<<endl;
    
// */


// //highest value of int

//   /*  cout<<INT_MAX<<endl;
//     cout<<((1<<31)-1)<<endl;
//     cout<<((1LL<<31)-1)<<endl;

// */


// //xor from a to b index in array
//     int arr[]={2,3,5,11,6,18};
    


// }

#include <iostream>
#include <vector>
using namespace std;

void dfs(int vertex, vector<int>& visited, vector<vector<int>>& graph) {
    cout << vertex << endl; 
    visited[vertex] = 1;

    for (auto child : graph[vertex]) {
        if (!visited[child]) {
            dfs(child, visited, graph);
        }
    }
}

int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, 0);

    cout << "Enter the edges (a b) where a and b are vertices connected by an edge:" << endl;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Assuming the graph is undirected
    }

    cout << "DFS Traversal starting from vertex 0:" << endl;
    dfs(1, visited, graph);

    return 0;
}
