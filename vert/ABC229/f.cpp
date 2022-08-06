//
// Created by 原田 on 2022/05/16.
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
typedef vector<vl> vvl;

const long long LINF =1e18;
const int INF = 1e9;



int main() {

    int n;
    cin>>n;

    vi a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    vi b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin>>b[i];
    }

    vector<vector<vector<ll>>> dp(n + 1,vvl(2,vl(2,LINF)));
    dp[1][0][0] = a[1];
    dp[1][1][1] = 0;

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                for (int l = 0; l < 2; ++l) {

                    if(j == l){
                        //今塗る色と、前塗った色が同じ場合i - i+1辺を削除
                        if(j == 0){
                            //０頂点と同じ色なので、０頂点とi頂点を結ぶ辺も削除する
                            chmin(dp[i][j][k],dp[i - 1][l][k] + b[i - 1] + a[i]);
                        }else{
                            chmin(dp[i][j][k],dp[i - 1][l][k] + b[i - 1]);
                        }
                    }else{
                        if(j == 0){
                            //０頂点と同じ色なので、０頂点とi頂点を結ぶ辺も削除する
                            chmin(dp[i][j][k],dp[i - 1][l][k] + a[i]);
                        }else{
                            chmin(dp[i][j][k],dp[i - 1][l][k]);
                        }
                    }


                }
            }
        }
    }
    ll ans = LINF;
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
            if(j == k) {
                //同じなら辺を削除
                chmin(ans, dp[n][j][k] + b[n]);
            }else{
                chmin(ans,dp[n][j][k]);
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
