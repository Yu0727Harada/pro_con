//
// Created on 2020/06/06.
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
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>>g(n,vector<int>());
    vector<int>color(n,0);
    for (int i = 0; i < m; ++i) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int j = 0; j < n; ++j) {
        cin>>color[j];
    }
    for (int k = 0; k < q; ++k) {
        int t;
        cin>>t;
        if(t == 1){
            int x;
            cin>>x;
            x--;
            cout<<color[x]<<endl;
            for (int i = 0; i < g[x].size(); ++i) {
                color[g[x][i]] = color[x];
            }
        }else{
            int x,y;
            cin>>x>>y;
            x--;
            cout<<color[x]<<endl;
            color[x] = y;
        }
    }
    return 0;
}
