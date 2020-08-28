//
// Created on 2020/08/28.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;
    vector<pair<int,int>>edge(n);
    vector<int>color(n);
    vector<priority_queue<pair<int,int>, vector<pair<int,int> >,greater< pair<int,int> > > >v_p(n);
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin>>x>>y;
        edge[i] = {x,y};
        for (int j = 0; j < i; ++j) {
            int u = j;
            int d = abs(min(abs(edge[u].first - edge[i].first), abs(edge[u].second - edge[i].second)));
            v_p[j].push({d, i});
            v_p[i].push({d, j});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater< pair<int,int> >>p_q;
    p_q.push({0,0});
    ll ans = 0;
    int sum_c = 0;
    while(!p_q.empty()){
        if(sum_c >= 2 * n)break;
        int d = p_q.top().first;
        int u = p_q.top().second;
        p_q.pop();
        if(color[u] == 2) continue;
        color[u] = 2;
        ans += d;
        sum_c += 2;
        while(!v_p[u].empty()){
            int next_d = v_p[u].top().first;
            int next_u = v_p[u].top().second;
            v_p[u].pop();
            if(color[next_u] == 2) continue;
            p_q.push({next_d, next_u});
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
