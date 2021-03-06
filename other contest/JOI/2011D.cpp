//
// Created on 2020/07/17.
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
    int N;
    cin>>N;
    vector<ll>num(N,0);
    for (int i = 0; i < N; ++i) {
        cin>>num[i];
    }
    vector<vector<ll>>dp(N+1,vector<ll>(21,0));
    dp[0][0] = 1;
    for (int j = 0; j < N - 1; ++j) {
        for (int i = 0; i <= 20; ++i) {
            //add
            ll next_add = i + num[j];
            ll next_sub = i - num[j];


            if(next_add >= 0 && next_add <= 20){
                dp[j + 1][next_add] += dp[j][i];
            }
            //sub
            if(next_sub >= 0 && next_sub <= 20 && j > 0){
                dp[j + 1][next_sub] += dp[j][i];
            }
        }
    }

    cout<<dp[N - 1][num[N-1]]<<endl;
    return 0;
}
