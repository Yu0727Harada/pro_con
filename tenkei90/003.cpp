//
// Created by 原田 on 2021/07/15.
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



int main() {
    int n;
    cin>>n;

    vvi edge(n,vi());

    for (int i = 0; i < n-1; ++i) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vi cost(n,-1);

    queue<pair<int,int>>q;
    q.push({0,0});
    int max_c = 0;
    int max_index = -1;
    while(!q.empty()){
        int v = q.front().first;
        int c = q.front().second;

        q.pop();
        cost[v] = c;
        if(c > max_c){
            max_c = c;
            max_index = v;
        }
        for (int i = 0; i < edge[v].size(); ++i) {
            int next_v = edge[v][i];
            if(cost[next_v] == -1){
                q.push({next_v,c+1});
            }
        }
    }

    q.push({max_index,0});
    vi cost_f(n,-1);
    max_c = 0;
    max_index = -1;
    while(!q.empty()){
        int v = q.front().first;
        int c = q.front().second;

        q.pop();
        cost_f[v] = c;
        if(c > max_c){
            max_c = c;
            max_index = v;
        }
        for (int i = 0; i < edge[v].size(); ++i) {
            int next_v = edge[v][i];
            if(cost_f[next_v] == -1){
                q.push({next_v,c+1});
            }
        }
    }
    cout<<max_c + 1<<endl;
    return 0;
}
