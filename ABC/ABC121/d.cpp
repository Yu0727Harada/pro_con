//
// Created by 原田 on 2021/11/19.
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
    ll a, b;
    cin>>a>>b;
    b++;

    vl pow_l ( 66);
    pow_l[0] = 1;
    for (int i = 1; i < 66; ++i) {
        pow_l[i] = pow_l[i - 1] * 2;
    }
    vl mod_v_a (65);
    vl mod_v_b(65);
    ll i = 0;

    while(pow_l[i] < a){
        ll interval = pow_l[i] * 2;
        mod_v_a[i] += ((a - pow_l[i]) / interval) * pow_l[i];
        if((a - pow_l[i]) % interval <= pow_l[i])mod_v_a[i] += (a - pow_l[i]) % interval;
        else mod_v_a[i] += pow_l[i];
        i++;
    }
    i = 0;
    while(pow_l[i] <= b){
        ll interval = pow_l[i] * 2;
        mod_v_b[i] += ((b - pow_l[i]) / interval) * pow_l[i];
        if((b - pow_l[i]) % interval <= pow_l[i])mod_v_b[i] += (b - pow_l[i]) % interval;
        else mod_v_b[i] += pow_l[i];
        i++;
    }
    ll ans = 0;
    for (int j = 0; j <= 65; ++j) {
        if((mod_v_b[j] - mod_v_a[j]) % 2 == 1){
            ans += pow_l[j];
        }
    }
    cout<<ans<<endl;

    return 0;
}

