//
// Created on 2022/05/28.
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
    ll n,a,b;
    cin>>n>>a>>b;

    if(a > b)swap(a,b);
    ll all_sum = (n * (1 + n))/2;
    ll a_cnt = n / a;
    ll a_sum = (a_cnt *(2 * a + (a_cnt - 1) * a)) / 2;

    ll b_sum =0;

    ll ab_sum = 0;

    if(b % a != 0){
        ll b_cnt = n / b;
        b_sum = ((b_cnt *(2 * b + (b_cnt - 1) * b)) / 2);
        ll ab = lcm(a,b);
        ll ab_cnt = n / ab;
        ab_sum = (ab_cnt *(2 * ab + (ab_cnt - 1) * ab)) / 2;
    }
    all_sum -= a_sum;
    all_sum -= b_sum;
    all_sum += ab_sum;
    cout<<all_sum<<endl;

    return 0;
}
