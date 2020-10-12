//
// Created on 2020/10/10.
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
    int h,w;
    cin>>h>>w;
    vector<vector<int>>grid(h,vector<int>(w,0));//0-. 1=#
    for (int i = 0; i < h; ++i) {
        string s;
        cin>>s;
        for (int j = 0; j < s.size(); ++j) {
            if(s[j] == '#'){
                grid[i][j] = 1;
            }
        }
    }

    vector<pair<int,int>> move = {
                {0,  1},
                {1,  0},
        };
    ll ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(grid[i][j] == 1)continue;
            for (int k = 0; k < 2; ++k) {
                int next_cell_h = i + move[k].first;
                int next_cell_w = j + move[k].second;
                if(0 <= next_cell_h && next_cell_h < h && 0 <= next_cell_w && next_cell_w < w){
                    if(grid[next_cell_h][next_cell_w] == 0){
                        ans ++;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
