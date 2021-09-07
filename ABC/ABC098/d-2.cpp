//
// Created by 原田 on 2021/08/26.
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

    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    ll now = 0;
    ll now_xor = 0;

    ll ans = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while(now + a[r] == (now ^ a[r]) && r < n){
            now += a[r];
            r ++;
        }
        ans += r - l;
        if(l == r) r++;
        else{
            now -= a[l];
        }
    }


    cout<<ans<<endl;
    return 0;
}

//
//しゃくとり法
//長さ n
//n
// の正の整数列 a1,a2,…,an
//a
//1
//,
//a
//2
//,
//…
//,
//a
//n
// が与えられる。整数列の連続する部分列のうち、「xor 和と加算和とが等しい」という条件を満たすものを数え上げよ。