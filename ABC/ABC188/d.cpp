//
// Created on 2021/01/10.
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
    ll C;
    cin>>C;

    vector<pair<int,int>> A;
    for (int i = 0; i < n; ++i) {
        int a,b,c;
        cin>>a>>b>>c;
        A.push_back({a,c});
        A.push_back({b+1,-c});
    }

    sort(all(A));
    int day = 0;
    ll price = 0;
    ll ans = 0;
    for (int i = 0; i < A.size(); ++i) {
        int target_day = A[i].first;

        ans += (target_day - day) * min(price,C);

        price += A[i].second;
        day = target_day;
    }

    cout<<ans<<endl;


    return 0;
}
