//
// Created on 2020/05/10.
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
    ll ans = LINF;
    bool ok = false;
    int m;
    int n;
    int x;
    cin>>n>>m>>x;
    vector<ll>price(n);
    vector<vector<int>>A(n,vector<int>(m));
    for (int i = 0; i < n; ++i) {
        cin>>price[i];
        for (int j = 0; j < m; ++j) {
            cin>>A[i][j];
        }
    }
    for (int bit = 0; bit < (1<<n); ++bit) {
        ll now_price = 0;
        vector<int>now_understand(m,0);
        for (int i = 0; i < n; ++i) {
            if(bit & (1<<i)){
                now_price += price[i];
                for (int j = 0; j < m; ++j) {
                    now_understand[j] += A[i][j];
                }
            }
        }
        bool temp_ok = true;
        for (int k = 0; k < m; ++k) {
            if(now_understand[k] < x) {
                temp_ok = false;
                break;
            }
        }
        if(temp_ok){
            ok = true;
            ans = min(ans,now_price);
        }
    }

    if (ok){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}
