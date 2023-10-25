#include<bits/stdc++.h>
using namespace std;


class MinStack {
    stack<int>st;
    int mn;

    public:

    MinStack(){
        while(!st.empty())st.pop();
        mn = INT_MAX;
    }

    void push(int val){
        if(st.empty()){
            st.push(val);
            mn = val;
        }
        else{
            if(mn > val){
                st.push(2*val - mn);
                mn = val;
            }
            else{
                st.push(val);
            }
        }
    }

    void pop(){
        if(st.empty())return;

        int val = st.top();
        st.pop();

        if(val < mn){
            mn = 2*mn - val;
        }
    }

    int top() {
    if (st.empty()) return -1;

    long long val = st.top();
    if (val < mn) return mn;
    return val;
  }

    int getMin(){
        return mn;
    }
};