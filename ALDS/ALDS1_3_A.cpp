//
// Created on 2020/04/07.
//

//#include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int ans;
    string S;
    getline(cin,S);

    int temp = 0;

    stack<int>st;
    for (int i = 0; i < S.size(); ++i) {
        if(S[i] == ' ') {
            st.push(temp);
            temp = 0;
        }else if(S[i]=='+'){
            int s = st.top();
            st.pop();
            int f = st.top();
            st.pop();
            st.push(f+s);
            i++;
        }else if(S[i]=='-'){
            int s= st.top();
            st.pop();
            int f = st.top();
            st.pop();
            st.push(f-s);
            i++;
        }else if(S[i]=='*'){
            int s = st.top();
            st.pop();
            int f = st.top();
            st.pop();
            st.push(f*s);
            i++;
        }else{
            temp *= 10;
            temp += S[i]-'0';
        }
    }
    ans = st.top();
    cout<<ans<<endl;
}
