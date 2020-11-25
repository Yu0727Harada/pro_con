//
// Created on 2020/11/08.
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
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n + 2,vector<int>(m + 2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char temp;
            cin>>temp;
            if(temp == '#'){
                grid[i][j] = 1;
            }
        }
    }

    vector<pair<int,int>>move_array = {
                {1,  0},
                {-1, 0},
                {0,  1},
                {0,-1},
                {1,1},
                {-1,-1},
                {1,-1},
                {-1,1}
        };

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {

            int ans = 0;
            ans += grid[i][j];

            for (int k = 0; k < 8; ++k) {
                pair<int,int> next;
                next.first = i + move_array[k].first;
                next.second = j + move_array[k].second;
                ans += grid[next.first][next.second];
            }
            cout<<ans;
        }
        cout<<endl;
    }




    return 0;
}
