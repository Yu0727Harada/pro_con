//
// Created on 2021/09/26.
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
    ll k;
    string a,b;

    cin>>k;
    cin>>a>>b;
    reverse(all(a));
    reverse(all(b));

    vector<ll> kurai(18,1);

    for (int i = 1; i < 18; ++i) {
        kurai[i] = kurai[i - 1] * k;
    }

    ll a_ten = 0;
    ll b_ten = 0;
    for (int i = 0; i < a.size(); ++i) {
        ll temp =  a[i] - '0';
        a_ten += temp * kurai[i];
    }
    for (int i = 0; i < b.size(); ++i) {
        ll temp =  b[i] - '0';
        b_ten += temp * kurai[i];
    }
    ll ans =a_ten*b_ten;
    cout<<ans<<endl;

    return 0;
}
