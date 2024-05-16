//
// Created by yu on 2024/05/16.
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
    for (int i = 0; i < n - 1; ++i) {
        int a,b,x;
        cin>>a>>b>>x;
        x--;
        edge[i].push_back({i+1,a});
        edge[i].push_back({x,b});
    }
     priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>p_que;
    vl cost(n,LINF);
    p_que.push({0,0});
    cost[0] = 0;
    while(!p_que.empty()){
        int v = p_que.top().second;
        ll c = p_que.top().first;
        p_que.pop();

        if(v == n - 1){
            cout<<c<<endl;
            return 0;
        }
        for (int i = 0; i < edge[v].size(); ++i) {
            ll u_cost = (ll)edge[v][i].second;
            int u = edge[v][i].first;
            if(cost[v] + (ll)u_cost < cost[u]){
                cost[u] = cost[v] + u_cost;
                p_que.push({cost[u],u});
            }
        }
    }
    return 0;
}
