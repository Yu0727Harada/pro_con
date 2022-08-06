//
// Created on 2022/06/18.
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
    vector<vector<pair<int,ll>>> edge(n,vector<pair<int,ll>>());
    vi x(n);
    for (int i = 0; i < n; ++i) {
        cin>>x[i];
        x[i]--;
    }
    vl c(n);
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    for (int i = 0; i < n; ++i) {
        edge[x[i]].push_back({i,c[i]});
    }
    vi visit(n,false);
    vi t_visit(n,false);
    vector<pair<int,ll>> r_path;

    queue<pair<int,ll>>q;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if(t_visit[i] == false){
            q.push({i,0});
            r_path.clear();
            r_path.push_back({i,INF + 10});
            visit.resize(n,0);
            visit[i] = true;
            while(!q.empty()){
                int v = q.front().first;
                ll p_cost = q.front().second;
                q.pop();
                if(edge[v].size() == 0)continue;
                int u = edge[v][0].first;
                ll cost = edge[v][0].second;
                r_path.push_back({u,cost});
                if(visit[u] == true && t_visit[u] == false){
                    ll min_cost = cost;
                    bool find = false;
                    for (int j = r_path.size() - 2; j >= 0; --j) {
                        if(r_path[j].first == u){
                            find = true;
                            break;
                        }
                        else{
                            chmin(min_cost,r_path[j].second);
                        }
                    }
                    if(find)ans += min_cost;
                    r_path.clear();
                }else{
                    visit[u] = true;
                    q.push({u,cost});
                }
            }
            for (int j = 0; j < n; ++j) {
                if(visit[j])t_visit[j] = true;
            }

        }

    }

    cout<<ans<<endl;
    return 0;
}
