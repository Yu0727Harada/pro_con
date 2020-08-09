//
// Created on 2020/07/20.
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
    int m;
    cin>>m;
    vector<int>distance(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>distance[i];
    }
    vector<int>weather(m+1,0);
    for (int i = 0; i < m ; ++i) {
        cin>>weather[i];
    }
    vector<vector<int>>dp(m+1,vector<int>(n+1,INF));
    dp[0][0] = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //stay
            dp[i+1][j+1] = min(dp[i][j] + (distance[j+1] * weather[i]),dp[i+1][j+1]);
            //go
            dp[i+1][j] = min(dp[i][j],dp[i+1][j]);
        }
    }
    int ans = INF;
    for (int k = 1; k <= m; ++k) {
        ans = min(dp[k][n],ans);
    }
    cout<<ans<<endl;
    return 0;
}
