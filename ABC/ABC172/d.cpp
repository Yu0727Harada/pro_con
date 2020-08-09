//
// Created on 2020/06/27.
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
#define rall(x) (x).rbegin(),(x).rend()
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    ll ans = 0;
    vector<ll>yakusu(n+1,0);
    for (ll i = 1; i <= n; ++i) {
        ans += i * (((n/i)*(n/i+1))/2);
    }
    cout<<ans<<endl;
    return 0;
}

/*
O=NlogNの解法
 int main() {
    int n;
    cin>>n;
    ll ans = 0;
    vector<ll>yakusu(n+1,0);
    for (ll i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i){
            yakusu[j] ++;
        }
    }
    for (ll k = 1; k <= n; ++k) {
        ans += k * yakusu[k];
    }
    cout<<ans<<endl;
    return 0;
}
*/

