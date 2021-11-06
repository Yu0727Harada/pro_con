//
// Created on 2021/08/21.
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;

vector<ll>prime_factorize(ll n){
    vector<ll>ret;
    for (ll i = 2; i * i <= n ; ++i) {
        if(n % i == 0){

            while(n % i == 0){
                n /= i;
            }
            ret.push_back(i);
        }
    }
    if(n != 1){
        ret.push_back(n);
    }
    return ret;
    //example n = 12, ret = [[2,2],[3,1]と返す
}

int main() {

    ll n;
    cin>>n;
    ll m;
    cin>>m;

    vi li(100010,0);

    for (ll i = 0; i < n; ++i) {
        ll a;
        cin>>a;
        vl b = prime_factorize(a);

        for (int j = 0; j < b.size(); ++j) {
            int c = b[j];
            if(li[c] != 0)continue;
            for (int k = c; k <= m;k += c) {
                li[k] = 1;
            }
        }
    }

    vi ans;
    ans.push_back(1);
    for (int i = 2; i <= m; ++i) {
        if(li[i] == 0)ans.push_back(i);
    }

    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i]<<endl;
    }


    return 0;
}
