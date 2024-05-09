//
// Created by yu on 2023/12/16.
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


ll bfs(int u,vvi &edge,vector<bool> &visit){
    int cnt = 1;
    for (int i = 0; i < edge[u].size(); ++i) {
        if(visit[edge[u][i]] == false){
            visit[edge[u][i]] = true;
            cnt += bfs(edge[u][i],edge,visit);
        }
    }
    return cnt;
}


int main() {
    int n;
    cin>>n;
    vvi edge(n,vi());
    for (int i = 0; i < n -1; ++i) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<bool>visit(n,false);
    visit[0]=true;
    if(edge[0].size() == 1){
        cout<<1<<endl;
        return 0;
    }
    vector<ll>ans(edge[0].size());
    for (int i = 0; i < edge[0].size(); ++i) {
        visit[edge[0][i]] = true;
        ans[i] =bfs(edge[0][i],edge,visit);

    }
    sort(all(ans));
    ll out = 0;
    for (int i = 0; i < ans.size()-1; ++i) {
        out += ans[i];
    }
    cout<<out + 1<<endl;


    return 0;
}
