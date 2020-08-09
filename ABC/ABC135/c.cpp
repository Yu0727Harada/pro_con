//
// Created on 2020/04/17.
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


int main() {
    ll ans = 0;
    ll n;
    cin>>n;
    vector<int>a(n+1);
    for (ll i = 0; i < n+1; ++i) {
        cin>>a[i];
    }

    for (ll j = 0; j < n; ++j) {
        int b;
        cin>>b;

        ans += min(b,a[j]+a[j+1]);
        a[j+1] -= (max(min(b-a[j],a[j+1]),0));
        a[j] = max(a[j] - b,0);
    }

    cout<<ans<<endl;
}
