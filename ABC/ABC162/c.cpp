//
// Created on 2020/04/12.
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

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a %b);
}

int main() {
    ll ans = 0;
    ll k;
    cin>>k;
    for (ll i = 1; i <= k; ++i) {
        for (ll j = 1; j <= k; ++j) {
            for (ll l = 1; l <= k; ++l) {
                ans += gcd(i,gcd(j,l));
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
