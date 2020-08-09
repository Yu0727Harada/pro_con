//
// Created on 2020/05/03.
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
    int ans = 0;
    int n;
    cin>>n;
    vector<pair<int,int>>high(n+1);
    high[0] = {-1,0};
    for (int i = 1; i <= n; ++i) {
        int temp;
        cin>>temp;
        high[i] = {temp,i};
    }
    sort(all(high));
    for (int i = 2; i <= n-1; ++i) {
        for (int j = 0; j < ; ++j) {
            high[j]
        }
    }

    cout<<ans<<endl;
    return 0;
}
