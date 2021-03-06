//
// Created on 2020/05/15.
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
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;


int main() {
    int n;
    int m;
    cin>>n>>m;
    int ans_l = 0;
    int ans_r = n;

    for (int i = 0; i < m; ++i) {
        int l;
        int r;
        cin>>l>>r;
        l--;
        ans_l = max(l,ans_l);
        ans_r = min(r,ans_r);
    }
    int ans = max(ans_r-ans_l,0);
    cout<<ans<<endl;
    return 0;
}
