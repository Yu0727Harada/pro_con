//
// Created on 2020/07/29.
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


using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int n;
int main() {
    while(cin>>n,n){
        vector<int>w(n+2,0);
        w[0] = -INF;
        w[n+1] = INF;
        for (int m = 1; m <= n; ++m) {
            cin>>w[m];
        }
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for (int i = 1; i +1 <= n; ++i) {
            if(abs(w[i] - w[i+1]) <=1){
                dp[i][i+1] = 2;
            }
        }

        for (int l = 2; l <= n; ++l) {
            for (int i = 1; i + l <= n; ++i) {
                int j = i + l;
                if(dp[i + 1][j - 1] == (j - 1) - ((i + 1) - 1)){
                    if(abs(w[i] - w[j]) <= 1){
                        dp[i][j] = max(j - (i - 1),dp[i][j]);
                    }else {
                        dp[i][j] = max((j - 1) - ((i + 1) - 1), dp[i][j]);
                    }
                }
                for (int k = i; k + 1 <= j; ++k) {
                    dp[i][j] = max(dp[i][k] + dp[k + 1][j],dp[i][j]);
                }
            }
        }
        cout<<dp[1][n]<<endl;
    }
}
//ダルマ落とし　区間DP　インデックスって難しいね
