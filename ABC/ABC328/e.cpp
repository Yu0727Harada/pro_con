
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

vector<vector<pair<int,ll>>> edge;//{next,cost}
ll ans = LINF;
ll k;
void dfs(int u,ll cost,vi visit){
    visit[u] = 1;
    bool  complete = true;
    for (int i = 0; i < visit.size(); ++i) {
        if(!visit[i])complete = false;
    }
    if(complete)chmin(ans,cost);
    for (int i = 0; i < edge[u].size(); ++i) {
        if(!visit[edge[u][i].first]){
            dfs(edge[u][i].first,(cost + edge[u][i].second)%k,visit);
        }
    }
}


int main() {
    int n,m;
    cin>>n>>m;

    cin>>k;
    edge.resize(n,vector<pair<int,ll>>());
    vi visit(n,0);
    for (int i = 0; i < m; ++i) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--;
        v--;
        edge[u].push_back({v,w});
        edge[v].push_back({u,w});
    }

    for (int i = 0; i < n; ++i) {
        dfs(i,0,visit);
    }
    cout<<ans<<endl;
    return 0;
}
