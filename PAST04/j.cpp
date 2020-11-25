//
// Created on 2020/11/08.
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
    int n,m;
    cin>>n>>m;
    ll xab,xac,xbc;
    cin>>xab>>xac>>xbc;
    string s;
    cin>>s;

    vector<vector<pair<ll,ll>>>link(n,vector<pair<ll,ll>>());
    for (int i = 0; i < m; ++i) {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        link[a].push_back({b,c});
        link[b].push_back({a,c});
    }

    vector<ll>dist(n,LINF);

    if(s[0] == 'A'){
        for (int i = 1; i < n; ++i) {
            if(s[i] == 'B'){
                dist[i] = min(xab,xac+xbc);
            }else if(s[i] == 'C'){
                dist[i] = min(xac,xab+xbc);
            }else{
                dist[i] = min(2*xab,2*xac);
                dist[i] = min(dist[i],xab+xac+xbc);
            }

        }
    }else if(s[0] == 'B'){
        for (int i = 1; i < n; ++i) {
            if(s[i] == 'A'){
                dist[i] = min(xab,xbc+xac);
            }else if(s[i] == 'C'){
                dist[i] = min(xbc,xab+xac);
            }else{
                dist[i] = min(2*xab,2*xbc);
                dist[i] = min(dist[i],xab+xac+xbc);
            }


        }
    }else{
        for (int i = 1; i < n; ++i) {
            if(s[i] == 'A'){
                dist[i] = min(xac,xab+xbc);
            }else if(s[i] == 'B'){
                dist[i] = min(xbc,xab+xac);
            }else{
                dist[i] = min(2*xac,2*xbc);
                dist[i] = min(dist[i],xab+xac+xbc);
            }
        }
    }


     priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>p_que;

     p_que.push({0,0});

     int sum = 0;
     vector<int>visit(n,0);//0-未　1ー灰色　2確定
    for (int i = 1; i < n; ++i) {
        p_que.push({dist[i],i});

    }

     while(!p_que.empty()){
        if(sum >= n) break;

         ll cost = p_que.top().first;
        int u = p_que.top().second;
        p_que.pop();

        if(dist[u] > cost){
            dist[u] = cost;
        }
        visit[u] = 2;
        sum ++;
         for (int i = 0; i < link[u].size(); ++i) {
             if(dist[u] + link[u][i].second < dist[link[u][i].first]){
                dist[link[u][i].first] = dist[u] + link[u][i].second;
                 if(visit[link[u][i].first] == 0 ){
                    p_que.push({dist[u] + link[u][i].second,link[u][i].first});
                     visit[link[u][i].first] = 1;
                 }
             }

         }


     }


    cout<<dist[n-1]<<endl;

    return 0;
}
