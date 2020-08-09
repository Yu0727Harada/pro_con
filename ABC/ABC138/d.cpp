//
// Created on 2020/06/05.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    int q;
    cin>>q;

    vector<vector<int>>g(n,vector<int>());
    for (int i = 1; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll>root(n,0);
    for (int j = 0; j < q; ++j) {
        int p;
        ll x;
        cin>>p>>x;
        p--;
        root[p] += x;
    }
    queue<pair<int,int>>bfs;
    vector<bool>visit(n,false);
    bfs.push({0,0});
    while(!bfs.empty()){
        int v_n = bfs.front().first;
        int v_last = bfs.front().second;
        bfs.pop();
        visit[v_n] = true;
        root[v_n] += v_last;
        for (int i = 0; i < g[v_n].size() ; ++i) {
            if(visit[g[v_n][i]] == false ){
                bfs.push({g[v_n][i],root[v_n]});
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        cout << root[k] << ( k + 1 < n ? ' ' : '\n' );
    }

    return 0;
}
