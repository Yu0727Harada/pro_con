//
// Created by yuha2114 on 2024/05/09.
//

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
//#include <atcoder/all>


#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int h,w,m;
    cin>>h>>w>>m;
    set<int> h_st;
    set<int> w_st;
    map<int,ll>mp;
    
    stack<vi>q;
    for (int i = 0; i < m; ++i) {
        int t,a,x;
        cin>>t>>a>>x;
        a--;
        q.push({t,a,x});
    }
    int zero_cnt = w*h;
    while(!q.empty()){
        int t,a,x;
        t = q.top()[0];
        a = q.top()[1];
        x = q.top()[2];
        q.pop();

        if(t == 1){
            //row ->h
            if(h_st.count(a) == 1)continue;
            if(w - w_st.size()){
                h_st.insert(a);
                zero_cnt -= w - w_st.size();
                mp[x] += w - w_st.size();
            }
        }else{
            //col ->w
            if(w_st.count(a) == 1) continue;
            if(h - h_st.size()){
                w_st.insert(a);
                zero_cnt -= h - h_st.size();
                mp[x] += h - h_st.size();
            }
        }
    }
    mp[0] = mp[0] + zero_cnt;
    if(mp[0] == 0){
        mp.erase(0);
    }
    cout<<mp.size()<<endl;
    for(auto item:mp){
        cout<<item.first<<" "<<item.second<<endl;
    }

    return 0;
}
