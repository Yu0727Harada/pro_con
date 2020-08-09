//
// Created on 2020/06/19.
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

int bit_count(int i){
    //数字iを二進数表記にした際の1の数を調べる
    if (i==0) return 0;
    return bit_count(i>>1) + (i & 1);
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<bool>>relation(n,vector<bool>(n,false));
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        relation[x][y] = true;
        relation[y][x] = true;
    }
    int ans = 0;
    //n個の要素のbit全探索する
    for (int bit = 0; bit < (1<<n); ++bit) {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if(bit & (1<<i)){
                //i個目の要素にフラグが立っていた時の処理
                for (int j = i + 1; j < n && ok; ++j) {
                    if (bit & (1<<j)) {
                        if(!relation[i][j]){
                            ok = false;
                        }
                    }
                }
            }
        }
        if(ok){
            ans = max(ans,bit_count(bit));
        }
    }
    cout<<ans<<endl;

    return 0;
}
