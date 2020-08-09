//
// Created on 2020/05/12.
//

//
// Created on 2020/05/12.
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

vector< int64_t > divisor(int64_t n) {
    vector< int64_t > ret;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
        if (ret.size()>=4) break;
    }
    sort(begin(ret), end(ret));
    return (ret);
}

int solve(){
    ll n,k;
    ll ans;
    cin>>n>>k;
    auto div = divisor(n);
    int next = n + div[1];
    ans = next + 2 * (k-1);
    cout<<ans<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t){
        solve();
        t--;
    }
    return 0;
}
