//
// Created on 2020/05/31.
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
    vector<pair<ll,ll>>v(n);
    vector<pair<ll,ll>>rv(n);
    ll ans;
    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        v[i] = {a,b};
        rv[i] = {b,a};
    }
    sort(all(v));
    sort(all(rv));
    if(n % 2 == 0){
        ll r_1 =rv[n/2].first;
        ll r_2 = rv[n/2-1].first;
        ll l_1 = v[n/2 -1].first;
        ll l_2 = v[n/2].first;
        ans = (r_1 + r_2)  - (l_2 + l_1 - 1);
    }else{
        ll r = rv[n/2].first;
        ans = r - (v[n/2].first - 1);
    }
    cout<<ans<<endl;
    return 0;
}
