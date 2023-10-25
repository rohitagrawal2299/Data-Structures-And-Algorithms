#include<bits/stdc++.h>
#include <cstdio>
#include "rotten_oranges.h"
using namespace std;

void solve(){
    vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
    Solution obj;
    int rotting = obj.orangesRotting(v);
    cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	freopen("output.txt", "w", stdout);

    int t=1;
    //int t;
    //cin>>t;
    while(t--){
        solve();
    }
}