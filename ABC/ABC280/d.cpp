
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


vector<pair<ll,ll>>prime_factorize(ll n){
    vector<pair<ll,ll>>ret;
    for (ll i = 2; i * i <= n ; ++i) {
        if(n % i == 0){
            ll ex = 0;//指数
            while(n % i == 0){
                ex++;
                n /= i;
            }
            ret.push_back({i, ex});
        }
    }
    if(n != 1){
        ret.push_back({n,1});
    }
    return ret;
    //example n = 12, ret = [[2,2],[3,1]と返す
}

ll solve(ll x, ll y){
    ll ret = y / x;

    if(ret >= 2){
        ret += solve(x,ret);
    }
    return ret;

}

int main() {

    ll k;
    cin>>k;

    auto v = prime_factorize(k);

    ll ng = 0;
    ll ok = LINF;
    ll mid;

    while(abs(ok - ng) > 1){
        mid = (ok + ng) / 2;
        bool judge = true;
        for (int i = 0; i < v.size(); ++i) {
            if(v[i].second <= solve(v[i].first,mid)){
                continue;
            }else{
                judge = false;
                break;
            }
        }
        if(judge){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout<<ok<<endl;



    return 0;
}
