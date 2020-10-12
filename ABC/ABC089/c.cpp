//
// Created on 2020/10/12.
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
    int n;
    cin>>n;
    vector<ll>person(5,0);
    for (int i = 0; i < n; ++i) {
        string name;
        cin>>name;
        if(name[0] == 'M'){
            person[0]++;
        }else if(name[0] == 'A' ){
            person[1]++;
        }else if(name[0] == 'R'){
            person[2] ++;
        }else if(name[0] == 'C'){
            person[3]++;
        }else if(name[0] == 'H'){
            person[4]++;
        }
    }

    ll ans = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = i+1; j < 5; ++j) {
            for (int k = j+1; k < 5; ++k) {
                ans += person[i] * person[j] * person[k];
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}
