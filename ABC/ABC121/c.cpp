//
// Created on 2020/10/05.
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
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater< pair<int,int> >>p_q;

    for (int i = 0; i < n; ++i) {
        int a,b;
        cin>>a>>b;
        p_q.push({a,b});
    }
    ll ans = 0;
    while(m>0){
        int price = p_q.top().first;
        int limit = p_q.top().second;
        p_q.pop();
        for (int i = 0; i < limit && m > 0; ++i) {
            ans += price;
            m --;
        }
    }

    cout<<ans<<endl;
    return 0;
}
