//
// Created by 原田 on 2022/05/10.
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
    int h,w;
    cin>>h>>w;
    vvi grid(h,vi(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin>>grid[i][j];
        }
    }
    ll ans = 0;
    //n個の要素のbit全探索する
    for (int bit = 0; bit < (1<<h); ++bit) {
            vi cnt(h*w+5);
        for (int j = 0; j < w; ++j) {
            int v = -1;
            bool ok = true;
            int c = 0;
            for (int i = 0; i < h; ++i) {
                if(bit & (1<<i)){
                    //i個目の要素にフラグが立っていた時の処理
                    c++;
                    if(v != grid[i][j]){
                        if(v == -1)v = grid[i][j];
                        else ok = false;
                    }else{

                    }
                }
            }
            if(ok)cnt[v] += c;
        }
        ll max_v = *max_element(all(cnt));
        chmax(ans,max_v);
    }

    cout<<ans<<endl;

    return 0;
}
