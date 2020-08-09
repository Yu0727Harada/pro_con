//
// Created on 2020/07/05.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int h,w,k;
    cin>>h>>w>>k;
    vector<vector<bool>>grid(h,vector<bool>(w));
    for (int i = 0; i < h; ++i) {
        string tmp;
        cin>>tmp;
        for (int j = 0; j < w; ++j) {
            if(tmp[j] == '.') grid[i][j] = false;
            if(tmp[j] == '#') grid[i][j] = true;
        }
    }
    //n個の要素のbit全探索する
    int ans = 0;
    int n = h+w;
    for (int bit = 0; bit < (1<<n); ++bit) {
        auto n_grid = grid;
            for (int i = 0; i < h; ++i) {
                if(bit & (1<<i)){
                    //i個目の要素にフラグが立っていた時の処理
                    for (int j = 0; j < w; ++j) {
                        n_grid[i][j] = false;
                    }
                }
            }
        for (int i = h; i < h+w; ++i) {
            if(bit & (1<<i)){
                //i個目の要素にフラグが立っていた時の処理
                for (int j = 0; j < h; ++j) {
                    n_grid[j][i-h] = false;
                }
            }
        }
        int t_ans = 0;
        for (int l = 0; l < h; ++l) {
            for (int i = 0; i < w; ++i) {
                if(n_grid[l][i])t_ans ++;
            }
        }
        if(t_ans == k)ans++;
    }
    cout<<ans<<endl;
    return 0;
}

