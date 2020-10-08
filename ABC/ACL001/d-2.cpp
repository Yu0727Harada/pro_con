//
// Created on 2020/10/08.
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
#include <atcoder/all>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;

const int MAX_A = 300005;

int op(int a, int b){return max(a,b);}
int e(){return 0;}
int main() {
    int n,k;
    cin>>n>>k;

    vector<int>line(n);
    for (int i = 0; i < n; ++i) {
        cin>>line[i];

    }
    atcoder::segtree<int,op,e> dp(MAX_A);

    for (int i = 0; i < n; ++i) {
        int a = line[i];
        int l = max(0,a-k);
        int r = min(MAX_A,a+k+1);
        int now = dp.prod(l,r)+1;//半開区間
        dp.set(a, now);
    }
    int ans = dp.prod(0,MAX_A);
    cout<<ans<<endl;
    return 0;
}
