//
// Created by 原田 on 2021/07/20.
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
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> edge(n,vector<pair<int,ll>>());
    for (int i = 0; i < m; ++i) {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;b--;
        edge[a].push_back({b,c});
        edge[b].push_back({a,c});
    }

    vl one_cost(n,LINF);
    vl n_cost(n,LINF);

     priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>p_que;
     p_que.push({0,0});
     while(!p_que.empty()){
         int v = p_que.top().second;
         ll cost = p_que.top().first;
         p_que.pop();
         if(one_cost[v] < cost)continue;
         one_cost[v] = cost;

         for (int i = 0; i < edge[v].size(); ++i) {
             int u = edge[v][i].first;
             ll next_cost = edge[v][i].second;
             if(one_cost[u] > cost + next_cost){
                 p_que.push({cost + next_cost,u});
             }
         }
     }
     p_que.push({0,n-1});
    while(!p_que.empty()){
        int v = p_que.top().second;
        ll cost = p_que.top().first;
        p_que.pop();
        if(n_cost[v] < cost)continue;
        n_cost[v] = cost;

        for (int i = 0; i < edge[v].size(); ++i) {
            int u = edge[v][i].first;
            ll next_cost = edge[v][i].second;
            if(n_cost[u] > cost + next_cost){
                p_que.push({cost + next_cost,u});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<one_cost[i] + n_cost[i]<<endl;
    }

    return 0;
}
//典型ダイクストラ