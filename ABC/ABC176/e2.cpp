//
// Created on 2020/08/22.
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

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int h,w,m;
    cin>>h>>w>>m;
    vector<int>grid(h,0);
    vector<int>grid_2(w,0);
    map<pair<int,int>,int>bom_list;
    for (int i = 0; i < m; ++i) {
        int b_h,b_w;
        cin>>b_h>>b_w;
        b_h --;
        b_w --;
        grid[b_h] ++;
        grid_2[b_w] ++;
        bom_list[{b_h,b_w}] ++;
    }
    map<int,vector<int>>h_que;
    map<int,vector<int>>w_que;
    for (int i = 0; i < h; ++i) {
        h_que[grid[i]].push_back(i);
    }
    for (int i = 0; i < w; ++i) {
        w_que[grid_2[i]].push_back(i);
    }
    int max_v = 0;
    int h_max = h_que.rbegin()->first;
    int w_max = w_que.rbegin()->first;
    for(auto th : h_que[h_max]){
        for (auto tw : w_que[w_max]) {
            chmax(max_v,h_max + w_max - bom_list[{th,tw}]);

        }
    }
    cout<<max_v<<endl;
    return 0;
}
