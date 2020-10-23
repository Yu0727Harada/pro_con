//
// Created on 2020/10/22.
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
    int n;
    cin>>n;
    vector<vector<int>>ans(h,vector<int>(w,0));
    int cnt_h = 0;
    int cnt_w = 0;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin>>a;
        for (int j = 0; j < a; ++j) {
            ans[cnt_h][cnt_w] = i;
            cnt_w ++;
            if(cnt_w == w){
                cnt_w = 0;
                cnt_h ++;
            }
        }
    }

    for (int k = 0; k < h; ++k) {
        if(k % 2 == 0){
            for (int i = 0; i < w; ++i) {
                cout<<ans[k][i]<<endl;
            }
        }else{
            for (int i = w - 1; 0 <= i ; --i) {
                cout<<ans[k][i]<<endl;
            }
        }
    }

    return 0;
}

