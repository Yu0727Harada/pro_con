//
// Created by yu on 2024/05/16.
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

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a %b);
}
//2つの自然数の最大公約数を求める関数

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
//2つの自然数の最大公約数から最小公倍数を求める関数

int main() {
    ll n,m,k;
    cin>>n>>m>>k;

    ll nm = lcm(n,m);

    ll ok = 0;
    ll ng = LINF;
    ll mid;
    while(ng - ok > 1){
        mid = (ok + ng) / 2;
        ll cnt = 0;
        cnt += mid / n - (mid / nm);
        cnt += mid / m - (mid / nm);
        if(cnt >= k){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout<<ng<<endl;

    return 0;
}
