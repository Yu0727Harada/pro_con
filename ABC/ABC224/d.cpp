//
// Created on 2021/10/23.
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
    int m;
    cin>>m;
    vvi edge(10,vi());

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    vi init_p(10,0);
    for (int i = 1; i < 9; ++i) {
        int temp;
        cin>>temp;
        init_p[temp] = i;
    }

    map<vector<int>,int>mp;
    mp[init_p] = 1;
    queue<pair<vi,int>>q;
    q.push({init_p,1});
    while(!q.empty()){
        vi now_p = q.front().first;
        int now_cnt = q.front().second;
        q.pop();

        int empty_v;
        for (int i = 1; i < 10; ++i) {
            if(now_p[i] == 0)empty_v = i;
        }

        for (int i = 0; i < edge[empty_v].size(); ++i) {
            vi next_p = now_p;
            swap(next_p[empty_v],next_p[edge[empty_v][i]]);
            if(mp[next_p] == 0){
                q.push({next_p,now_cnt+1});
                mp[next_p] = now_cnt + 1;
            }else if(mp[next_p] > now_cnt + 1){
                q.push({next_p,now_cnt+1});
                mp[next_p] = now_cnt + 1;
            }else{
                continue;
            }
        }
    }

    vi ans_p = {0,1,2,3,4,5,6,7,8,0};
    cout<<mp[ans_p] - 1<<endl;

    return 0;
}
