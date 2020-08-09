//
// Created on 2020/04/19.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;
const long long MOD = 1e9+7;

int main() {
    ll ans = 0;
    ll n;
    ll k;
    cin>>n>>k;
    vector<ll>sum(n+1);
    sum[0] = 0;
    ll temp = 0;
    for (int l = 1; l <= n; ++l) {
        temp += l;
        sum[l] = temp;
    }

    for (int i = k; i <= n + 1 ; ++i) {
        ll max = n * i - sum[i -1];
        ll min = sum[i - 1];

        ll unique_cnt = max - min + 1;
        ans = (ans + unique_cnt) % MOD;
    }

    cout<<ans<<endl;
    return 0;
}
