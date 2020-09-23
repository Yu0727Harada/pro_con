//
// Created on 2020/09/21.
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
    ll k,v;
    cin>>h>>w>>k>>v;
    vector<vector<ll>>g(h+1,vector<ll>(w+1,0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ll a;
            cin>>a;
            g[i][j] = g[i][j-1]+a;
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            g[i][j] = g[i-1][j]+g[i][j];
        }
    }

    ll ans = 0;

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w ; ++j) {
            for (int l = 1; l <= h ; ++l) {
                for (int m = 1; m <= w; ++m) {
                    ll s = (l-(i-1))*(m-(j-1));
                    ll value = (g[l][m] + g[i-1][j-1]) - g[l][j-1] - g[i-1][m]+(s*k);
                    if(value <= v){
                        chmax(ans,s);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    

    return 0;
}
