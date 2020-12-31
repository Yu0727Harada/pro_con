//
// Created on 2020/12/28.
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
    int a,b,c,d;
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    d = s[3] - '0';


    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                int ans = a;
                string f = to_string(a);
                if(i){
                    ans +=b;
                    f += "+" + to_string(b);
                }else{
                    ans -=b;
                    f += "-" + to_string(b);
                }
                if(j){
                    ans +=c;
                    f += "+" + to_string(c);
                }else{
                    ans -=c;
                    f += "-" + to_string(c);
                }
                if(k){
                    ans +=d;
                    f += "+" + to_string(d);
                }else{
                    ans -=d;
                    f += "-" + to_string(d);
                }
                f += "=7";
                if(ans == 7){
                    cout<<f<<endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
