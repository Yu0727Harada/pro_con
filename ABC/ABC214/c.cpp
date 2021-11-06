//
// Created on 2021/08/14.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;

    vl s(n,0);
    deque<ll> s_sum(2 * n + 3,0);
    for (int i = 0; i < n; ++i) {
        cin>>s[i];
    }
    s_sum[0] = s[0];

    for (int i = 1; i < s_sum.size(); ++i) {
        s_sum[i] = s_sum[i-1] + s[i % n];
    }

    s_sum.push_front(0);
    vl ans(n,LINF);
    vector<pair<ll,int>> time(n);
    for (int i = 0; i < n; ++i) {
        if(i == 0){
            cin>>ans[0];
            time[0] = {ans[0],n};
        }
        else {
            cin>>ans[i];
            time[i] = {ans[i],i};

            }
        }
    sort(all(time));

    for (int i = 0; i < time.size(); ++i) {
        for (int cnt = 1; cnt < n; ++cnt) {
            int j = (time[i].second + cnt) % n;
            int l_index;
            if(j == 0)j = n;
            if(j < time[i].second) l_index = j + n;
            else l_index = j;

            if(ans[j % n] <= time[i].first + s_sum[l_index] - s_sum[time[i].second])break;
            ans[j % n] = time[i].first + s_sum[l_index] - s_sum[time[i].second];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout<<ans[i]<<endl;
    }

    return 0;
}
