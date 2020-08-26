//
// Created on 2020/08/26.
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
    int n;
    cin>>n;
    vector<vector<ll>>g(n,vector<ll>(n,0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>g[i][j];
        }
    }
    vector<vector<int>>edge(n,vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j)continue;
            ll direct = g[i][j];
            bool add = true;
            for (int k = 0; k < n; ++k) {
                if(k == i || k == j)continue;
                ll via = g[i][k] + g[k][j];
                if(direct < via){
                }else if(direct == via){
                    add = false;
                }else if(direct > via){
                    cout<<-1<<endl;
                    return 0;
                }
            }
            if(add)edge[i].push_back(j);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < edge[i].size(); ++j) {
            if(edge[i][j] < i)continue;
            ans += g[i][edge[i][j]];
        }
    }
    cout<<ans<<endl;
    return 0;
}
