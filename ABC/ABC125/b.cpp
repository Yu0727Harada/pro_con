//
// Created on 2020/05/21.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    cin>>n;
    vector<int>value(n);
    vector<int>cost(n);

    for (int i = 0; i < n; ++i) {
        cin>>value[i];
    }
    for (int j = 0; j < n; ++j) {
        cin>>cost[j];
    }

    vector<vector<int>>dp(n + 1, vector<int>(1010,0));

    dp[0][0] = 0;

    for (int k = 1; k <= n; ++k) {
        int n_value = value[k - 1];
        int n_cost = cost[k - 1];

        for (int j = 0; j < n_cost; ++j) {
            dp[k][j] = dp[k - 1][j];
        }
        for (int i = 0 + n_cost; i < 1010; ++i) {
            dp[k][i] = max(dp[k-1][i - n_cost] + n_value, dp[k - 1][i]);
        }
    }

    int ans = 0;

    for (int l = 0; l < 1010; ++l) {
        ans = max(ans, dp[n][l] - l);
    }

    cout<<ans<<endl;
    return 0;
}
