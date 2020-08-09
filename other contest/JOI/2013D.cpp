//
// Created on 2020/07/19.
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
    int d;
    cin>>d;
    int n;
    cin>>n;
    vector<int>temp(d+1);
    for (int i = 1; i <= d; ++i) {
        cin>>temp[i];
    }
    vector<vector<int>>cloth(n,vector<int>(3));
    //[0]C ~ [1]C, [2]hade
    for (int j = 0; j < n; ++j) {
        cin>>cloth[j][0];
        cin>>cloth[j][1];
        cin>>cloth[j][2];
    }
    vector<vector<int>>dp(d+1,vector<int>(110,-1));
    for (int l = 0; l < n; ++l) {
        if(cloth[l][0] <= temp[1] && temp[1] <= cloth[l][1]){
            dp[1][cloth[l][2]] = 0;
        }
    }
    for (int i = 1; i < d; ++i) {
        for (int j = 0; j < 110; ++j) {
            if(dp[i][j] == -1)continue;
            for (int k = 0; k < n; ++k) {
                if(cloth[k][0] <= temp[i+1] && temp[i+1] <= cloth[k][1]){
                    dp[i + 1][cloth[k][2]] = max(dp[i + 1][cloth[k][2]],dp[i][j] + abs(j - cloth[k][2]));
                }
            }
        }
    }

    int ans = 0;
    for (int m = 0; m < 110; ++m) {
        ans = max(ans,dp[d][m]);
    }
    cout<<ans<<endl;
    return 0;
}
