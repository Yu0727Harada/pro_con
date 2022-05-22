//
// Created on 2022/02/20.
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

vector<pair<int,int>> ans;
vvi edge;
int cnt;
vi visit;

pair<int,int> solve(int now){
    visit[now] = 1;

    int min_v = INF;
    int max_v = -1;
    int c = 0;
    for(int i = 0; i < edge[now].size() ; i++){
        if(visit[edge[now][i]] == INF){
            c ++;
            auto ret = solve(edge[now][i]);
            chmin(min_v,ret.first);
            chmin(min_v,ret.second);
            chmax(max_v,ret.first);
            chmax(max_v,ret.second);
        }
    }

    if(c == 0){
        min_v = cnt;
        max_v = cnt;
        cnt++;
    }
    ans[now] = {min_v,max_v};

    return {min_v,max_v};
}


int main() {

    int n;
    cin>>n;
    edge.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin>>u>>v;
        u--;v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    ans.resize(n);

    visit.resize(n,INF);
    visit[0] = 1;
    cnt = 1;
    solve(0);

    for (int i = 0; i < n; ++i) {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
    return 0;
}
