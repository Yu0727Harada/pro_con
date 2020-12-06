//
// Created on 2020/12/06.
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
    int n,r;
    cin>>n>>r;
    string s;
    cin>>s;
    int ans = 0;
    int index = 0;
    int index_0 = -1;

    for (int i = n-1; i > 0; --i) {
        if(s[i] == '.'){
            index_0 = i;
            break;
        }
    }
    if(index_0 == -1){
        cout<<0<<endl;
        return 0;
    }
    while(true){
        if(s[index] == '.' || index_0 <= index + r - 1){
            ans ++;
            for (int i = 0; i < r && index + i < n; ++i) {
                s[index + i] = 'o';
            }
            bool ok = true;
            for (int i = n - 1; i >= 0; --i) {
                if(s[i] == '.'){
                    index_0 = i;
                    ok = false;
                    break;
                }
            }
            if(ok)break;
        }

        index++;
        ans++;


    }
    cout<<ans<<endl;

    return 0;
}
