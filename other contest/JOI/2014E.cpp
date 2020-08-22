//
// Created on 2020/08/21.
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
    n++;
    int k;
    cin>>k;
    vector<pair<int,int>>taxi(n,pair<int,int>());//c,r
    vector<vector<int>>road(n,vector<int>());

    for (int i = 1; i < n; ++i) {
        int c,r;
        cin>>c>>r;
        taxi[i] = {c,r};
    }
    for (int j = 0; j < k; ++j) {
        int a,b;
        cin>>a>>b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    vector<ll>dict(n,INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>p_que;
    vector<int>color(n,0);
    dict[1] = 0;
    p_que.push({0,1});
    while(!p_que.empty()){
        int d = p_que.top().first;
        int v = p_que.top().second;
        p_que.pop();
        color[v] = 2;
        queue<pair<int,int>>q;//cost,cnt
        q.push({v,0});
        vector<bool>visit(n,false);
        visit[v] = true;
        while(!q.empty()){
            int s = q.front().first;
            int cnt = q.front().second;
            q.pop();
            for (int i = 0; i < road[s].size(); ++i) {
                int u = road[s][i];
                if(dict[u] > dict[v] + taxi[v].first && color[u] != 2){
                    dict[u] = dict[v] + taxi[v].first;
                    p_que.push({dict[u],u});
                    color[u] = 1;
                }
                if(!visit[u] && taxi[v].second > cnt + 1)q.push({u,cnt + 1});
                visit[u] = true;
            }

        }

    }
    cout<<dict[n-1]<<endl;

    return 0;
}
