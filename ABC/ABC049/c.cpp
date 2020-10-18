//
// Created on 2020/10/18.
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
    string s;
    cin>>s;
    vector<string> d = {"dream","dreamer", "erase", "eraser"};

    for (int i = s.size()-1; i >= 0; --i) {
        bool ok_entire = false;
        for (int j = 0; j < d.size(); ++j) {
            bool ok = true;
            for (int k = 0; k < d[j].size(); ++k) {
                if(s[i-k] != d[j][d[j].size()-1-k]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                i -= d[j].size()-1;
                ok_entire = true;
                break;
            }else{
                continue;
            }
        }
        if(!ok_entire){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
