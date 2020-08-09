//
// Created on 2020/05/16.
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

int solve(){
    vector<ll>x(2);
    cin>>x[1];
    ll k;
    ll ans = -1;
    cin>>k;
    for (ll i = 1; i < k; ++i) {
        string s = to_string(x[i]);
        int MIN = 10;
        int MAX = -1;
        for (ll j = 0; j < s.size(); ++j) {
            MIN = min(s[j]-'0',MIN);
            MAX = max(s[j]-'0',MAX);
        }
        x.push_back(x[i]+MIN*MAX);
        if(MIN == 0){
            ans = x[i+1];
            break;
        }
    }
    if(ans == -1) ans = x[k];
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
