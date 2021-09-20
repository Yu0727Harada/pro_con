//
// Created by 原田 on 2021/09/15.
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
    int n;
    cin>>n;

    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    int ans = -INF;
    for (int i = 0; i < n; ++i) {
        int aoki_best = -INF;
        int temp_ans = -INF;
        for (int j = 0; j < n; ++j) {
            if(i == j)continue;
            int r = j;
            int l = i;
            if(r < l)swap(r,l);

            int takahashi = 0;
            int aoki = 0;
            int p = 1;
            for (int k = l; k <= r ;++k) {
                if(p % 2 == 1)takahashi += a[k];
                else aoki += a[k];
                p++;
            }
            if(aoki_best < aoki){
                temp_ans = takahashi;
                aoki_best = aoki;
            }
        }
        chmax(ans,temp_ans);
    }
    cout<<ans<<endl;

    return 0;
}

