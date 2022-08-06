//
// Created on 2022/08/06.
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

    ll n,l,r;
    cin>>n>>l>>r;
    vl a(n);
    ll all_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        all_sum += a[i];
    }
    vl sum_a(n,0);
    sum_a[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum_a[i] += sum_a[i - 1] + a[i];
    }
    vl sum_a_r(n,0);
    sum_a_r[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        sum_a_r[i] += sum_a_r[i + 1] + a[i];
    }
    vl sub_l(n,0);
    vl small_l(n,LINF);
    ll now_l = l;
    for (int i = 0; i < n; ++i) {
        sub_l[i] = now_l - sum_a[i];
        chmin(small_l[i],min(small_l[i - 1],sub_l[i]));
        now_l += l;
    }
    vl sub_r(n,0);
    vl small_r(n,LINF);
    ll now_r = r;
    for (int i = n - 1; i >= 0; --i) {
        sub_r[i] = now_r - sum_a_r[i];
        chmin(small_r[i],min(small_r[i + 1],sub_r[i]));
        now_r += r;
    }
    ll ans = all_sum;
    chmin(ans,all_sum + small_l[n-1]);
    chmin(ans,all_sum + small_r[0]);
    for (int i = 0; i < n; ++i) {
        ll v;
        if(i == n - 1)v = all_sum + sub_l[i] + 0;
        else v = all_sum + sub_l[i] + small_r[i + 1];
        chmin(ans,v);
    }
    for (int i = n - 1; i >= 0; --i) {
        ll v;
        if(i == 0)v = all_sum + sub_r[i] + 0;
        else v = all_sum + sub_r[i] + small_l[i - 1];
        chmin(ans,v);
    }
    cout<<ans<<endl;

    return 0;
}
