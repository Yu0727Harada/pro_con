
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

int n;
vvi edge;
ll ans = 0;
vector<ll> dp;

ll select(int m,int l,ll ret){
    if(m == n){
        chmax(dp[l],ret);
        return ret;
    }
    if(l & (1<<m)){
        select(m + 1,l,ret);
    }else{
        for (int i = m + 1; i < n; ++i) {
            if(!(l & (1<<i))){
                int l_t = l;
                l_t |= (1<<i);
                l_t |= (1<<m);
                ll ret_t = ret;
                ret_t += (ll)edge[m][i];
                select(m + 1,l_t,ret_t);
            }
        }
        select(m + 1,l,ret);
    }

    return ret;
}


int main() {

    cin>>n;
    edge.resize(n,vi(n,-1));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin>>edge[i][j];
        }
    }
    int l_t = 0;
    int bit_size=0;
    bit_size |= (1<<n);
    dp.resize(bit_size);
    select(0,l_t,0);

    for (int i = 0; i < bit_size; ++i) {
        chmax(ans,dp[i]);
    }
    cout<<ans<<endl;


    return 0;
}
