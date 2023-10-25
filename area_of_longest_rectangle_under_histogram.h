#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector < int > & heights) {
      int n = heights.size();
      int smallLeft[n],smallRight[n];
      stack<int>st;

      for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i])st.pop();

        if(st.empty())smallLeft[i] = 0;
        else smallLeft[i] = st.top() + 1;

        st.push(i);
      }

      while(!st.empty())st.pop();

      for(int i = n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i])st.pop();

        if(st.empty())smallRight[i] = n-1;
        else smallRight[i] = st.top() - 1;

        st.push(i);
      }

      int maxA = 0;
      for (int i = 0; i < n; i++) {
        maxA = max(maxA, heights[i] * (smallRight[i] - smallLeft[i] + 1));
      }
      return maxA;

    }


    int largestRectangleAreaOptimal(vector < int > & heights) {
      int n = heights.size();
      
      stack<int>st;
      int maxa = 0;
      for(int i=0;i<=n;i++){
        while(!st.empty() && (i==n || heights[st.top()] > heights[i])){
          int height = heights[st.top()];
          st.pop();
          int width;
          if(st.empty())width = i;
          else width = i - st.top() - 1;

          maxa = max(maxa,height * width);

        }
        st.push(i);
      }
      return maxa;
    }
};