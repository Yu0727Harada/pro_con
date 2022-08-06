//
// Created by 原田 on 2022/02/04.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int a;
    int n;

    cin>>a;
    cin>>n;
    vector<int>dp(n*10,INF);

    dp[n] = 0;
    vector<int> ten = {1,10,100,1000,10000,100000,1000000,10000000};

    queue<int>q;
    q.push(n);
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        if(now % a == 0){
            if(dp[now / a] > dp[now] + 1){
                dp[now / a] = dp[now] + 1;
                int p = now/a;
                q.push(now/a);
            }

        }
        string s = to_string(now);
        reverse(all(s));
        for (int j = 1; j < 2; ++j) {
            int next = 0;

            bool ok = true;
            for (int k = s.size(); k < s.size() * 2; ++k) {
                if(k == 2 * s.size() - 1 && s[(k - 1) % s.size()] == '0')ok = false;
                next += (s[(k - 1) % s.size()] - '0') * ten[k - s.size()];
            }
            if(next == 0 || ok == false)continue;
            if(dp[next] > dp[now]+ j){
                dp[next] = dp[now] + j;
                q.push(next);
            }

        }
    }
    if(dp[1] == INF){
        cout<<-1<<endl;
    }else{
        cout<<dp[1]<<endl;
    }

    return 0;
}
