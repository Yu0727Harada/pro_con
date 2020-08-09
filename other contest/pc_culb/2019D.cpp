//
// Created on 2020/07/21.
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



int cnt_paint(int row,int colour,vector<vector<int>>flag){
    int ret = 0;
    for (int i = 0; i < 5; ++i) {
        if(flag[row][i] != colour)ret++;
    }
    return ret;
}

int main() {
    int n;

    cin>>n;
    vector<vector<int>>flag(n,vector<int>(5));
    //0-R, 1-B, 2-W, 3-#
    for (int j = 0; j < 5; ++j) {
        string t;
        cin>>t;
        for (int i = 0; i < n; ++i) {
            if(t[i] == 'R'){
                flag[i][j] = 0;
            }else if(t[i]=='B'){
                flag[i][j] = 1;
            }else if(t[i]=='W'){
                flag[i][j] = 2;
            }else{
                flag[i][j] = 3;
            }
        }
    }
    vector<vector<int>>dp(n,vector<int>(3,INF));
    for (int i = 0; i < 3; ++i) {
        dp[0][i] = cnt_paint(0,i,flag);
    }
    for (int k = 0; k < n - 1; ++k) {
        for (int i = 0; i < 3; ++i) {
            dp[k+1][(i+1)%3] = min(dp[k+1][(i+1)%3],dp[k][i]+cnt_paint(k+1,(i+1)%3,flag));
            dp[k+1][(i+2)%3] = min(dp[k+1][(i+2)%3],dp[k][i]+cnt_paint(k+1,(i+2)%3,flag));
        }
    }
    int ans = INF;
    for (int l = 0; l < 3; ++l) {
        ans = min(dp[n-1][l],ans);
    }
    cout<<ans<<endl;
    return 0;
}
