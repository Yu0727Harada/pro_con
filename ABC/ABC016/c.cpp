//
// Created on 2021/09/06.
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
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        vi fri(n,-1);
        queue<pair<int,int>>q;
        q.push({i,0});
        while(!q.empty()){
            int v = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if(fri[v] != -1)continue;
            fri[v] = cnt;
            for (int j = 0; j < edge[v].size(); ++j) {
                if(fri[edge[v][j]] == -1){
                    q.push({edge[v][j],cnt + 1});
                }
            }
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if(fri[j] == 2)ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}
