//
// Created on 2023/07/11.
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


vector<pair<ll, ll >> divisor(ll n) {
  vector<pair< ll, ll> > ret;
  for(ll i = 1; i <= n; i++) {
    if((floor(sqrt(double(i))) == sqrt(i)) && (floor(sqrt(double(n - i))) == sqrt(n - i))){
        ret.push_back({sqrt(i), sqrt(n - i)});
        ret.push_back({-sqrt(i), sqrt(n - i)});
        ret.push_back({sqrt(i), -sqrt(n - i)});
        ret.push_back({-sqrt(i), -sqrt(n - i)});

        if(i != n - i) {
            ret.push_back({sqrt(n - i), sqrt(i)});
            ret.push_back({-sqrt(n - i), sqrt(i)});
            ret.push_back({sqrt(n - i), -sqrt(i)});
            ret.push_back({-sqrt(n - i), -sqrt(i)});
        }
    }

  }
//  if(floor(sqrt(double(n))) == sqrt(n)){
//      ret.push_back({sqrt(n), 0});
//      ret.push_back({0, sqrt(n)});
//  }
  return (ret);
}

int main() {
    ll n;
    ll m;
    cin>>n>>m;

    vector<pair<ll,ll>> move = divisor(m);

    vvi g(n,vi(n,-1));

    queue<vl>q;
    q.push({0,0,0});
    g[0][0] = 0;

    while(!q.empty()){
        vl now = q.front();
        q.pop();

        if(g[now[0]][now[1]] == -1)continue;
        for (int i = 0; i < move.size(); ++i) {
            pair<ll,ll> next = {now[0] + move[i].first, now[1] + move[i].second};
            ll cnt = now[2] + 1;
            if(next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)continue;
            if(g[next.first][next.second] <= cnt && g[next.first][next.second] != -1)continue;
            g[next.first][next.second] = cnt;
            q.push({next.first, next.second, cnt});
        }
    }

    for (int i = 0; i < g.size(); ++i) {
        for ( int j = 0; j < g[i].size() - 1; j++ )
        {
            cout<<g[i][j]<<" ";
        }
        cout<<g[i][n - 1]<<endl;

    }

    return 0;
}
