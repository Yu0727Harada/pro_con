//
// Created on 2020/09/16.
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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    int q;
    cin>>q;
    vector<vector<int>>point(n+2,vector<int>(n+2,0));

    for (int i = 0; i < m; ++i) {
        int l,r;
        cin>>l>>r;
        point[l][r]++;
    }

    for (int i = 1; i < n+2; ++i) {
        for (int j = 1; j < n+2; ++j) {
            point[i][j] = point[i][j-1] + point[i][j];
        }
    }

    for (int i = 1; i < n+2; ++i) {
        for (int j = 1; j < n+2; ++j) {
            point[i][j] = point[i-1][j] + point[i][j];
        }
    }

    for (int k = 0; k < q; ++k) {
        int q_l,q_r;
        cin>>q_l>>q_r;

        int ans = point[q_r][q_r] - point[q_l - 1][q_r] - point[q_r][q_l-1] + point[q_l-1][q_l-1];
        cout<<ans<<endl;
    }

    return 0;
}
//二次元累積和