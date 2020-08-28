//
// Created on 2020/08/27.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>road(n+1,vector<pair<int,int>>());
    vector<int>color(n+1,0);
    priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > >q;
    for (int i = 0; i < m; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        road[a].push_back({c,b});
        road[b].push_back({c,a});
    }
    q.push({0,1});
    vector<int>ans;
    int f_ans = 0;
    int sum = 0;
    while(!q.empty()){
        if(sum >= 2 * n) break;
        int c = q.top().first;
        int u = q.top().second;
        q.pop();
        if(color[u] == 2)continue;
        color[u] = 2;
        sum += 2;
        ans.push_back(c);
        f_ans += c;
        for (int i = 0; i < road[u].size(); ++i) {
            int next_c = road[u][i].first;
            int next_v = road[u][i].second;
            if(color[next_v] != 2){
                q.push({next_c,next_v});
                color[next_v] = 1;
            }
        }
    }
    sort(all(ans));
    for (int i = 0; i < k - 1; ++i) {
        f_ans -= ans[ans.size()-1-i];
    }
    cout<<f_ans<<endl;
    return 0;
}
