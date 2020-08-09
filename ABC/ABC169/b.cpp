//
// Created on 2020/05/31.
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
    ll ans = 1;
    vector<ll>A(n);
    for (int j = 0; j < n; ++j) {
        cin>>A[j];
        if(A[j] == 0){
            cout<<0<<endl;
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
       if(ans > LINF/A[i]){
           cout<<-1<<endl;
           return 0;
       }
       ans *= A[i];
    }
    cout<<ans<<endl;
    return 0;
}
/*
N個の整数A1,...,ANが与えられます。

A1×...×ANを求めてください。

ただし、結果が10^18を超える場合は、代わりに -1 を出力してください。

 オーバーフロー判定
 */
