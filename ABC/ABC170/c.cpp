//
// Created on 2020/06/14.
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
    int x,n;
    cin>>x>>n;
    vector<int>p(n);
    for (int i = 0; i < n; ++i) {
        cin>>p[i];
    }
    if(n == 0){
        cout<<x<<endl;
        return 0;
    }
    sort(all(p));
    int cnt = 0;
    vector<int>ans;
    int ans_abs = INF;
    for (int j = 0; j <= 105; ++j) {
        if(j == p[cnt]){
            cnt ++;
            continue;
        }
        if(abs(j - x) < ans_abs){
            ans_abs = abs(j-x);
            ans.clear();
            ans.push_back(j);
        }else if(abs(j - x) == ans_abs){
            ans.push_back(j);
        }
    }
    sort(all(ans));
    cout<<ans[0]<<endl;


    return 0;
}
