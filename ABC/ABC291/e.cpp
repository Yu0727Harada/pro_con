//
// Created on 2023/08/04.
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
    int n,m;
    cin>>n>>m;

    vvi edge(n,vi());
    vi cnt(n,0);
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        edge[y].push_back(x);
        cnt[x]++;
    }
    queue<int>q;
    for (int i = 0; i < n; ++i) {
        if(cnt[i] == 0)q.push(i);
    }

    if(q.size() != 1){
        cout<<"No"<<endl;
        return 0;
    }

    vi ans;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);
        cnt[u]--;
        for (int i = 0; i < edge[u].size(); ++i) {
            cnt[edge[u][i]]--;
            if(cnt[edge[u][i]] == 0)q.push(edge[u][i]);
        }
        if(ans.size() < n && q.size() > 1){
            cout<<"No"<<endl;
            return 0;
        }
    }

    if(ans.size() != n){
        cout<<"No"<<endl;
        return 0;
    }

    vi out(n);
    for (int i = 0; i < n; ++i) {
        out[ans[i]] = n - i;
    }
    cout<<"Yes"<<endl;
    for (int i = 0; i < n; ++i) {
        cout<<out[i]<<endl;

    }

    return 0;
}
