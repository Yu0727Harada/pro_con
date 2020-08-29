//
// Created on 2020/08/29.
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
    int m;
    cin>>n>>m;
    vector<int>X(m);
    for (int i = 0; i < m; ++i) {
        cin>>X[i];
    }
    if(n >= m){
        cout<<0<<endl;
        return 0;
    }
    sort(all(X));
    priority_queue<pair<int,int>>p_q;//abs,abs = abs(i + 1 -i)のi
    for (int i = 0; i < m - 1; ++i) {
        int d = abs(X[i+1] - X[i]);
        p_q.push({d,i});
    }

    ll ans = X[m-1] - X[0];
    for (int j = 0; j < n - 1; ++j) {
        int index = p_q.top().second;
        p_q.pop();
        ans -= abs(X[index+1] - X[index]);
    }

    cout<<ans<<endl;
    return 0;
}
