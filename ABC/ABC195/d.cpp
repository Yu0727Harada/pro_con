//
// Created on 2021/03/13.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {

    int n,m;
    cin>>n>>m;
    int q;
    cin>>q;
    vector<pair<int,int>>load(n);
    vector<int>box(m + 1);
    for (int i = 0; i < n; ++i) {
        int w,v;
        cin>>w>>v;
        load[i] = {w,v};
    }
    for (int i = 1; i <= m; ++i) {
        int x;
        cin>>x;
        box[i] = x;
    }
    vvi se (m,vi(n));
    for (int i = 0; i < n; ++i) {
        se[0][i] = 0;
    }
    for (int i = 0; i < q; ++i) {
        int l,r;
        cin>>l>>r;
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < n; ++k) {
                if(l <= j && j <= r){
                    se[j][k] = se[j - 1][k];
                }

            }
        }

    }

    return 0;
}
