//
// Created by 原田 on 2021/07/08.
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

class train{
public:
    int to;
    int k;
    int time;

};


int main() {

    ll n,m;
    cin>>n>>m;
    ll x,y;
    cin>>x>>y;
    x--;y--;
    vector<vector<train>> mp(n,vector<train>());
    vector<ll>cost(n,LINF);
    for (int i = 0; i < m; ++i) {
        ll a,b,t,k;
        cin>>a>>b>>t>>k;
        train temp;
        a--;b--;
        temp.to = b;
        temp.k = k;
        temp.time = t;
        mp[a].push_back(temp);
        temp.to = a;
        mp[b].push_back(temp);
    }

     priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>p_que;
    p_que.push({0,x});

    while(!p_que.empty()){
        ll c = p_que.top().first;
        ll v = p_que.top().second;
        p_que.pop();
        if(cost[v] > c){
            cost[v] = c;

            for (int i = 0; i < mp[v].size(); ++i) {
                ll next_cost = c + (mp[v][i].k - c % mp[v][i].k)%mp[v][i].k + mp[v][i].time;
                ll next_u = mp[v][i].to;
                if(cost[next_u] > next_cost){
                    p_que.push({next_cost,next_u});
                }
            }

        }

    }

    if(cost[y] == LINF){
        cout<<-1<<endl;
    }else{
        cout<<cost[y]<<endl;
    }

    return 0;
}
