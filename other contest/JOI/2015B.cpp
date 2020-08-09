//
// Created on 2020/07/27.
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
    vector<ll>cake(n);
    for (int i = 0; i < n; ++i) {
        cin>>cake[i];
    }
    if(n == 1){
        cout<<cake[0]<<endl;
        return 0;
    }
    if(n == 2){
        cout<<max(cake[0],cake[1])<<endl;
        return  0;
    }

    vector<vector<ll>>dp(n,vector<ll>(n,0));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = cake[i];
        dp[i][(i+1)%n] = max(cake[i],cake[(i+1)%n]);
    }

    for (int d = 2; d < n - 1 ; d ++) {
        for (int i = 0; i < n; ++i) {
            int l = i;
            int r = (i + d) % n;
            int p_l = (l + 1) % n;
            int pp_l = (l + 2)%n;
            int p_r = (r - 1);
            int pp_r = (r - 2);
            if(p_r < 0) p_r += n;
            if(pp_r < 0) pp_r += n;
            //cake[r]をとる
            if(cake[l] > cake[p_r]){
                dp[l][r] = max(dp[p_l][p_r] + cake[r],dp[l][r]);
            }else{
                dp[l][r] = max(dp[l][pp_r] + cake[r],dp[l][r]);
            }
            //cake[l]をとる
            if(cake[p_l] > cake[r]){
                dp[l][r] = max(dp[pp_l][r] + cake[l],dp[l][r]);
            }else{
                dp[l][r] = max(dp[p_l][p_r] + cake[l],dp[l][r]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int l = (i + 1)%n;
        int r = (i + (n - 1))%n;
        if(cake[l] > cake[r]){
            ans = max(cake[i] + dp[(l + 1)%n][r],ans);
        }else{
            int t = r - 1;
            if(t < 0)t+=n;
            ans = max(cake[i] + dp[l][t],ans);
        }
    }

    cout<<ans<<endl;
    return 0;
}
