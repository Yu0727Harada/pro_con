
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

    int n,m;
    cin>>n>>m;
    vector<vector<pair<ll,int>>> edge(n,vector<pair<ll,int>>());
    map<pair<int,int>,int>m_mp;
    for (int i = 0; i < m; ++i) {
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;b--;
        if(a > b)swap(a,b);
        m_mp[{a,b}] = i;
        edge[a].push_back({c,b});
        edge[b].push_back({c,a});
    }

     priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>>p_que;

    p_que.push({(ll)0,0});

    vi prev(n,-2);
    vl cost_l(n,LINF);
    prev[0] = -1;
    cost_l[0] = 0;

    vi check (n,1);

    while(!p_que.empty()){
        int v = p_que.top().second;
        ll cost = p_que.top().first;
        p_que.pop();
        if(cost_l[v] < cost)continue;
        check[v] = 0;

        for (int i = 0; i < edge[v].size(); ++i) {
            if(check[edge[v][i].second] && edge[v][i].first + cost < cost_l[edge[v][i].second]){
                prev[edge[v][i].second] = v;
                cost_l[edge[v][i].second] = edge[v][i].first + cost;
                p_que.push({edge[v][i].first + cost,edge[v][i].second});
            }
        }

    }

    set<int>st;
    for (int i = 1; i < prev.size(); ++i) {
        if(i < prev[i]){
            st.insert(m_mp[{i,prev[i]}]);
        }else{
            st.insert(m_mp[{prev[i],i}]);
        }

    }
    for (auto item:st) {
        cout<<item+1<<endl;
    }

    return 0;
}
