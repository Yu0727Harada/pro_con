//
// Created by 原田 on 2022/07/08.
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



int main() {
    int n;
    cin>>n;

    vector<vector<pair<int,int>>> edge(n,vector<pair<int,int>>());
    vi x(n);
    vi c(n);
    for (int i = 0; i < n; ++i) {
        cin>>x[i];
        x[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    for (int i = 0; i < n; ++i) {
        edge[i].push_back({x[i],c[i]});
    }

    vi state(n,0);
    //0 not visit
    //1 visited calculating
    //2 visited calculated
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vl vs;
        if(state[i] == 0){
            auto dfs = [&](auto f,int v) -> int{
                if(state[v] == 2)return - 1;
                if(state[v] == 1)return v;
                state[v] = 1;
                int r = f(f,edge[v][0].first);
                state[v] = 2;
                if(r == -1)return - 1;
                vs.push_back(edge[v][0].second);
                if(r == v)return - 1;
                return r;
            };
            dfs(dfs,i);
            if(vs.size() >= 1){
                ll tmp = LINF + 100000;
                for (int j = 0; j < vs.size(); ++j) {
                    chmin(tmp,vs[j]);
                }
                ans += tmp;
            }

        }
    }
    cout<<ans<<endl;

    return 0;
}

//閉路検出
//出次数が1 の有向グラフを Functional Graphとよぶ
