//
// Created on 2020/10/26.
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
vector<int>memo(200110,0);

void divisor(ll n) {

  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
        memo[i] ++;
      if(i * i != n && i != 1) memo[n / i]++;
    }
  }
}

int main() {
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<bool>ans(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    for (ll j = n; j >= 1; --j) {
        if(memo[j] % 2 != a[j]){
            ans[j] = 1;
            divisor(j);
        }else{
            ans[j] = 0;
        }
    }
    cout<<memo[1]<<endl;
    for (int i = 1; i <= n; ++i) {
       if(ans[i]){
           cout<<i<<endl;
       }
    }

    return 0;
}

