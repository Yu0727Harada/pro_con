//
// Created on 2020/04/12.
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
    ll ans = 0;
    string s;
    int n;

    cin>>n>>s;



    for (int i = 0; i + 2 < n; ++i) {
        for (int j = i + 1; j +1 < n; ++j) {
            if(s[i] == s[j]) continue;
            for (int k = j+1; k < n ; ++k) {
                if(s[i] == s[k] || s[j] == s[k]) continue;
                if(j-i == k-j) continue;
                ans ++;
            }
        }

    }


    cout<<ans<<endl;
    return 0;
}
