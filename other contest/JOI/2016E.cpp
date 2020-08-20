//
// Created on 2020/08/20.
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
    ll n,m,k,s;
    cin>>n>>m>>k>>s;
    ll p,q;
    cin>>p>>q;
//    cout<<"n"<<endl;
    vector<ll>town(n+1000,0);//0->normal 1->denger 2->zombi
    queue<pair<ll,ll>>bfs_q;//v.cnt
    vector<vector<int>>edge(n+1,vector<int>());
    vector<ll>dist(n+1,LINF);//1 からそこの町までの最短コスト
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p_que;
    vector<int>color(n+1,0);//0->un 2->ok
    for (int i = 0; i < k; ++i) {
        ll tmp;
//        cout<<i<<endl;
        cin>>tmp;
        town[tmp] = 2;
        bfs_q.push({tmp,0});
        color[tmp] = 2;
    }

    for (int i = 0; i < m; ++i) {
//        cout<<i<<endl;
        int a,b;
        cin>>a>>b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }


    //BFSしてゾンビの街を決定する
//    cout<<"bfs"<<endl;
    while(!bfs_q.empty()){
        ll v = bfs_q.front().first;
        ll cnt = bfs_q.front().second;
        bfs_q.pop();
        if(cnt >= s)continue;
        for (int i = 0; i < edge[v].size(); ++i) {
            int u = edge[v][i];
            if(town[u] == 0){
                town.at(u) = 1;
                bfs_q.push({u,cnt+1});
            }
        }
    }

    //dik

    p_que.push({0,1});
    dist[1] = 0;

    while(!p_que.empty()){
        auto sum = accumulate(all(color),0LL);
        if(sum >= 2 * n)break;

        int d = p_que.top().first;
        int v = p_que.top().second;
        //cout<<d<<v<<endl;
        p_que.pop();
        color.at(v) = 2;
        for (int i = 0; i < edge[v].size(); ++i) {
            int u = edge.at(v).at(i);
            if(u == n){
                chmin(dist[u], dist[v]);
                continue;
            }
            if(color.at(u) != 2 && town[u] == 0){
                if(dist.at(u) > dist.at(v) + p){
                    dist.at(u) = dist.at(v) + p;
                    p_que.push({dist.at(u),u});
                    color.at(u) = 1;
                }
            }else if(color.at(u) != 2 && town[u] == 1){
                if(dist.at(u) > dist.at(v) + q){
                    dist.at(u) = dist.at(v) + q;
                    p_que.push({dist.at(u),u});
                    color.at(u) = 1;
                }
            }
        }
    }

    cout<<dist[n]<<endl;

    return 0;
}
