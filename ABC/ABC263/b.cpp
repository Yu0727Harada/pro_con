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



int main() {
    int n;
    cin>>n;
    vi p(n,-1);
    for (int i = 1; i < n; ++i) {
        int tmp;
        cin>>tmp;
        tmp--;
        p[i] = tmp;
    }
    int ans = 0;
    queue<pair<int,int>>q;
    q.push({0,0});
    while(!q.empty()){
        int u = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = u + 1; i < n; ++i) {
            if(p[i] == u)q.push({i,cnt+1});
        }
        if(u == n - 1)ans = cnt;
    }
    cout<<ans<<endl;

    return 0;
}
