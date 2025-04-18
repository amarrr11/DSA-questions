/* A troutr is a person who trust nobdy and everyone trust him find it.*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout << "Enter number of people (n): ";
    cin >> n;

    cout << "Enter number of trust pairs (m): ";
    cin >> m;

    vector<pair<int, int>> trust;
    cout << "Enter the trust pairs (a b means a trusts b):" << endl;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        trust.push_back({a, b});
    }

    // vector<pair<int, int>> v = {
    //     {0,1},{0,2},{0,3},
    //     {2,1},{2,3},
    //     {3,1},{3,2},
    //     {4,0},{4,1}
    // };
    // int n=5;
    
    vector<int> indegree(5,0);

    for(auto it:trust){
        indegree[it.first]--;
        indegree[it.second]++;
    }

    for(int i=0;i<n;i++){
        if(indegree[i]==n-1) {
            cout<<i<<endl;
        }
    }

}