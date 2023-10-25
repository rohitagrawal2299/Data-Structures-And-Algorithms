#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int orangesRotting(vector<vector< int >> & nums) {
        int n = nums.size();
        int m = nums[0].size();

        queue<pair<int,int>>qu;
        int tot = 0,days = 0,cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]!=0)tot++;
                if(nums[i][j]==2)qu.push({i,j});
            }
        }

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        while(!qu.empty()){
            int sz = qu.size();

            cnt += sz;

            while(sz--){
                int x = qu.front().first, y = qu.front().second;
                qu.pop();
                for(int i=0;i<4;i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if(nx < 0 || ny < 0 || nx >= m || ny >= n || nums[nx][ny] != 1) continue;
                    nums[nx][ny] = 2;
                    qu.push({nx, ny});
                }
            }
            if(!qu.empty())days++;
        }
        return cnt == tot ? days : -1;

    }
};