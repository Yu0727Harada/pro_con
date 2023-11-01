//
// Created on 2023/07/26.
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

    vvi family(n,vi());

    for (int i = 1; i < n; ++i) {
        int p;
        cin>>p;
        p--;
        family[p].push_back(i);
    }

    vi insurance(n,0);
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin>>x>>y;
        x--;
        chmax(insurance[x],y + 1);
    }

    queue<pair<int,int>>q;
    vi visit(n,0);
    q.push({0,insurance[0]});

    int ans = 0;
    while(!q.empty()){
        int u = q.front().first;
        int current = q.front().second;
        q.pop();
        if(visit[u] == 1)continue;
        visit[u] = 1;
        chmax(current,insurance[u]);
        if(current > 0)ans++;
        for (int i = 0; i < family[u].size(); ++i) {
            int next = family[u][i];
            if(visit[next] == 0){
                q.push({next,current - 1});
            }
        }

    }

    cout<<ans<<endl;
    return 0;
}
