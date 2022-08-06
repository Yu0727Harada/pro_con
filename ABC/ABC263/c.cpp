//
// Created on 2022/08/06.
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


vector<vector<int>>ans;
int n,m;
void dfs(int target,vi now){
    now.push_back(target);
    if(now.size() == n){
        ans.push_back(now);
        return ;
    }
    for (int i = target + 1; i <= m; ++i) {
        dfs(i,now);
    }
    return ;
}


int main() {


    cin>>n>>m;
    for (int i = 1; i <= m; ++i) {
        vi a;
        dfs(i,a);
    }

    for (int i = 0; i < ans.size(); ++i) {
        for ( int j = 0; j < ans[i].size(); j++ )
        {
        	cout << ans[i][j] << ( j + 1 < ans[i].size() ? ' ' : '\n' );
        }
        cout << flush;
    }


    return 0;
}
