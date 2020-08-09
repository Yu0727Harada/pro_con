//
// Created on 2020/07/18.
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
    int k;
    cin>>n>>k;
    vector<int>pasta_list(n+1,-1);
    for (int i = 0; i < k; ++i) {
        int date;
        int pasta;
        cin>>date;
        cin>>pasta;
        pasta --;
        pasta_list[date] = pasta;
    }

    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(3,0)));

    if(pasta_list[1] == -1){
        dp[1][0][1] = 1;
        dp[1][1][1] = 1;
        dp[1][2][1] = 1;
    }else{
        dp[1][pasta_list[1]][1] =1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(pasta_list[i+1] == j || pasta_list[i+1] == -1) {
                dp[i + 1][j][2] += dp[i][j][1];
                dp[i + 1][j][2] %= 10000;
            }
            if(pasta_list[i+1] == (j+1)%3 || pasta_list[i+1] == -1){
                dp[i + 1][(j + 1) % 3][1] += dp[i][j][1];
                dp[i + 1][(j + 1) % 3][1] %= 10000;
                dp[i + 1][(j + 1) % 3][1] += dp[i][j][2];
                dp[i + 1][(j + 1) % 3][1] %= 10000;
            }
            if(pasta_list[i+1] == (j+2)%3 || pasta_list[i+1] == -1) {
                dp[i + 1][(j + 2) % 3][1] += dp[i][j][1];
                dp[i + 1][(j + 2) % 3][1] %= 10000;
                dp[i + 1][(j + 2) % 3][1] += dp[i][j][2];
                dp[i + 1][(j + 2) % 3][1] %= 10000;
            }
        }
    }

    int ans = 0;
    for (int l = 0; l < 3; ++l) {
        for (int i = 1; i < 3; ++i) {
            ans += dp[n][l][i];
            ans %= 10000;
        }
    }
    cout<<ans<<endl;
    return 0;
}
