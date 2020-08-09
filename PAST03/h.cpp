//
// Created on 2020/06/06.
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
    int n,l;
    cin>>n>>l;
    vector<int>h(l,0);
    for (int i = 0; i < n; ++i) {
        int temp;
        cin>>temp;
        h[temp] = 1;
    }
    int t_1,t_2,t_3;
    cin>>t_1>>t_2>>t_3;

    vector<int>dp(l+6,INF);
    dp[0]=0;
    for (int j = 0; j < l; ++j) {
        if(h[j + 1] == 1){
            dp[j + 1] = min(dp[j] + t_1 + t_3,dp[j+1]);
        }else{
            dp[j + 1] = min(dp[j] + t_1,dp[j+1]);//action 1
        }
        if(h[j + 2] == 1){
            dp[j + 2] = min(dp[j] + t_2 + t_1 + t_3,dp[j+2]);
        }else{
            dp[j + 2] = min(dp[j] + t_2 + t_1,dp[j+2]);
            if(j+1 == l){
                dp[l] = min(dp[j] + (t_1 + t_2)/2,dp[l]);
            }
        }
        if(h[j + 4] == 1){
            dp[j + 4] = min(dp[j] + t_1 + 3 * t_2 + t_3,dp[j+4]);
        }else{
            dp[j+4] = min(dp[j] + t_1 + 3 * t_2,dp[j+4]);
            if(j+3 >= l){
                for (int i = 1; i <= 3; ++i) {
                    if(i + j == l){
                        dp[l] = min(dp[j] + t_1/2 + (i-1) * t_2 + t_2 /2, dp[l]);
                    }
                }
            }
        }
    }
    cout<<dp[l]<<endl;
    return 0;
}
