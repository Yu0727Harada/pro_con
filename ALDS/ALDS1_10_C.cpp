//
// Created on 2020/07/23.
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


int main() {
    int q;
    cin>>q;
    while(q){
        string x;
        string y;
        cin>>x>>y;
        //indexを揃えるために冒頭に意味のない文字を追加
        x = "#" + x;
        y = "#" + y;
        //別になくてもいいかもしれないswap
        if(y.size() > x.size()){
            swap(x,y);
        }
        //y.size < x.size
        vector<vector<int>>dp(y.size(),vector<int>(x.size(),0));
        for (int i = 0; i < y.size() - 1; ++i) {
            for (int j = 0; j < x.size(); ++j) {
                //yをi文字目まで見た時にxの位置がjの時のLCSの値で更新していく

                //choose
                //i文字目を選ぶ。選んださいの遷移先を更新
                for (int k = j + 1; k < x.size(); ++k) {
                    if (y[i + 1] == x[k]) {
                        dp[i + 1][k] = max(dp[i][j] + 1, dp[i + 1][k]);
                        break;
                    }
                }
                //non choose
                //i文字目を選ばない
                dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < x.size(); ++i) {
            ans = max(dp[y.size() - 1][i],ans);
        }
        cout<<ans<<endl;

        q--;
    }

}
//最長共通部分列　LCS（longest common subsequence)問題
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja