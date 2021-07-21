//
// Created on 2021/05/15.
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {

    string s;
    cin>>s;
    int ans = 0;

    for (int i = 0; i <= 9999; ++i) {
        string t = to_string(i);

        while(t.size() < 4){
            t = '0' + t;
        }
        bool ok = true;
        for (int j = 0; j < s.size(); ++j) {
            bool find = false;
            if(s[j] == 'o'){
                for (int k = 0; k < t.size(); ++k) {
                    if(t[k]-'0' == j){
                        find = true;
                    }
                }
                if(find)continue;
                else ok =false;
            }else if(s[j] == 'x') {
                for (int k = 0; k < t.size(); ++k) {
                    if (t[k]-'0' == j) {
                        find = true;
                    }
                }
                if (!find)continue;
                else ok = false;

            }
        }
        if(ok)ans ++;

    }
    cout<<ans<<endl;


    return 0;
}
