//
// Created on 2021/03/27.
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



int main() {
    ll n;
    cin>>n;
    vector<vector<ll>> log(n,vector<ll>(n,0));

    for (int i = 0; i < n; ++i) {
        cin>>log[i][i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            log[i][j] = log[i][j-1] | log[j][j];
        }
    }

    ll ans = LINF;
    queue<pair<ll,ll>> q;
    for (int i = 0; i < n; ++i) {
        q.push({i,log[0][i]});
    }
    while(!q.empty()){
        ll now =q.front().first;
        ll v = q.front().second;
        q.pop();

        if(now == n - 1){
            chmin(ans,v);
        }else{
            for (int i = now + 1; i < n; ++i) {
                q.push({i,v ^ log[now + 1][i]});
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}
