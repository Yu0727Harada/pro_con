//
// Created on 2023/07/09.
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
    int n,x,y;
    cin>>n>>x>>y;
    x--;
    y--;

    vvi g(n,vi());
    vi visit(n,-1);
    vi route_x;
    vi route_y;

    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    queue<int> q;

    q.push(y);


    while(!q.empty()){
        int now = q.front();

        q.pop();

        if(now == x){

            break;
        }

        for (int i = 0; i < g[now].size(); ++i) {
            int next = g[now][i];
            if(visit[next] == -1){
                visit[next] = now;
                q.push(next);
            }
        }
    }

    queue<int>qq;
    qq.push(x);
    while(!qq.empty()){
        cout<<qq.front() + 1<<endl;
        if(qq.front() == y)break;
        if(visit[qq.front()] != -1)qq.push(visit[qq.front()]);
        qq.pop();
    }








    return 0;
}
