//
// Created on 2021/10/29.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a %b);
}

int op(int a, int b){return gcd(a,b);}
int e(){return 0;}
int main() {
    int n;
    cin>>n;
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    atcoder::segtree<int,op,e> dp(a);

    int ans = dp.prod(1,n);
    chmax(ans,dp.prod(0,n-1));
    for (int i = 1; i < n; ++i) {
        int l = dp.prod(0,i);
        int r = dp.prod(i+1,n);
        int g = gcd(l,r);
        chmax(ans,g);
    }
    cout<<ans<<endl;


    return 0;
}
