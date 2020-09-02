//
// Created on 2020/09/01.
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


int main() {

    vector<int>list(100005,0);
    for (int i = 2; i < 100005; ++i) {
        for (int j = i + i; j < list.size(); j = j + i) {
            list[j] ++;
        }
    }

    vector<int>like_list(100005,0);
    for (int i = 3; i < 100005; i ++) {
        if(list[i] == 0 && list[(i+1)/2] == 0){
            like_list[i]++;
        }
        like_list[i] = like_list[i - 1]+like_list[i];
    }

    int q;
    cin>>q;
    for (int k = 0; k < q; ++k) {
        int l,r;
        cin>>l>>r;
        int ans = like_list[r]-like_list[l-2];
        cout<<ans<<endl;
    }
    return 0;
}
