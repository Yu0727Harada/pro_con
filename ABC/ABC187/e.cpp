//
// Created on 2021/01/02.
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

    vi a(n);
    vi b(n);
    vi c(n,0);

    vvi edge(n,vi());
    for (int i = 0; i < n-1; ++i) {
        cin>>a[i];
        cin>>b[i];
        a[i]--;
        b[i]--;
        edge[a[i]].push_back(b[i]);
        edge[b[i]].push_back(a[i]);
    }
    vi v(n,0);
    int q;
    cin>>q;
    for (int i = 0; i < q; ++i) {
        int t,e,x;
        cin>>t>>e>>x;
        e--;
        if(t == 1){
            v[a[e]] += x;
        }else{
            v[a[e]] -= x;
        }
    }

    int min_v = 0;

    vector<bool>visit(n,false);
    queue<pair<int,int>>que;
    que.push({1,0});
    while(!que.empty()){
        int u = que.front().first;
        int cnt = que.front().second;
        cnt += v[u];
        que.pop();
        visit[u] = true;
        c[u] = cnt;
        min_v = min(cnt,min_v);
        for (int i = 0; i < edge[u].size(); ++i) {
            if(!visit[u])que.push({edge[u][i],cnt});
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<c[i] - min_v<<endl;
    }

    return 0;
}
