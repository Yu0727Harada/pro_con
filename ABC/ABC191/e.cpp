//
// Created on 2021/03/15.
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

    vector<vector<pair<int,int>>> edge(n,vector<pair<int,int>>());
    vector<vector<pair<int,int>>> r_edge(n,vector<pair<int,int>>());


    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        edge[a].emplace_back(b,c);
        r_edge[b].emplace_back(a,c);
    }


    for (int i = 0; i < n; ++i) {
        vi d(n,INF);//最短距離を保管する
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>p_que;
        int ans = INF;
        d[i] = 0;//出発点の距離は0
        p_que.push({0,i});//最初の時点をプッシュ
        while(!p_que.empty()){
            int v = p_que.top().second;
            int cost = p_que.top().first;
            p_que.pop();
            if(d[v] != cost)continue;//コストと最短距離が一致しない時はそれは最短距離でないので飛ばす
            for (auto next : edge[v]) {
                int j = next.first;
                int next_cost = next.second;
                    if(d[j] > d[v] + next_cost){
                        d[j] = d[v] + next_cost;
                        p_que.push({d[v] + next_cost,j});
                }
            }
        }

        for (auto next : r_edge[i]) {
            int j = next.first;
            int cost = next.second;
            chmin(ans,d[j] + cost);
        }
        if(ans == INF){
            ans = -1;
        }
        cout<<ans<<endl;
    }


    return 0;
}
//ダイクストラ