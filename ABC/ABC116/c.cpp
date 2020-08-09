//
// Created on 2020/07/30.
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
    vector<int>h(n,0);
    for (int i = 0; i < n; ++i) {
        cin>>h[i];
    }
    int ans = 0;
    for (int i = 1; i <= 100; ++i) {
        int l;
        int r;
        bool ok = false;
        for (int j = 0; j < n; ++j) {
            if(h[j] >= i && !ok){
                ok = true;
            }else if(h[j] >= i && ok){
                continue;
            }else if(h[j] < i && ok){
                ok = false;
                ans ++;
            }else if(h[j] < i && !ok){
                continue;
            }
        }
        if(ok){
            ans ++;
        }
    }
    cout<<ans<<endl;

    return 0;
}

