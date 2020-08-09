//
// Created on 2020/07/05.
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
    int n;
    cin>>n;
    queue<int>q;
    vector<int>a;
    for (int i = 0; i < n; ++i) {
        int t;
        cin>>t;
        a.push_back(t);
    }
    sort(rall(a));
    ll ans = 0;
    q.push(a[1]);
    q.push(a[1]);
    ans += a[0];
    for (int j = 2; j < n; ++j) {
        int d = q.front();
        ans += d;
        q.pop();
        q.push(a[j]);
        q.push(a[j]);
    }
    cout<<ans<<endl;
    return 0;
}
