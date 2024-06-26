//
// Created by yu on 2023/11/29.
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
//#include <atcoder/all>


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

    ll n,m;
    cin>>n>>m;
    m--;
    vl words(n);
    for (int i = 0; i < n; ++i) {
        cin>>words[i];
    }

    ll ok = LINF;
    ll ng = 0ull;
    ll mid;
    while(ok - ng > 1){
        mid = (ok + ng)/2;

        bool check = true;
        ll now_w = 0;
        ll now_h = 0;
        for (int i = 0; i < n; ++i) {
            if(now_w == 0){
                //先頭だったらスペースを入れない
                if(mid > now_w + words[i])now_w += words[i];
                else check = false;
            }else{
                if(mid > now_w + words[i] + 1){
                    now_w += (words[i]);
                    now_w ++;
                }else if(mid <= words[i]){
                    check = false;
                }else{
                    //入らない場合は次の行へ
                    now_h++;
                    now_w = 0;
                    now_w += words[i];
                }
            }
        }
        if(now_h > m)check = false;
        if(check)ok = mid;
        else ng = mid;
    }
    cout<<ok - 1<<endl;

    return 0;
}
