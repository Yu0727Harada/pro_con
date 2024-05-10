//
// Created by yu on 2023/11/14.
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
    ll bit;
    cin>>bit;


    //n個の要素のbit全探索する

     priority_queue<ll, vector<ll>, greater<ll>>q;
     priority_queue<ll, vector<ll>, greater<ll>>q_n;

    q.push(0);
    cout<<0<<endl;
    ll p = 1;
    for (ll i = 0; i < 60; ++i) {


        if(bit & (ll)(1ull<<i)){
            //i個目の要素にフラグが立っていた時の処理

            while(!q.empty()){
                ll a = q.top();
                q.pop();
                if(a + p <= bit){
                    cout<<a + p<<endl;
                    q_n.push(a);
                    q_n.push(a + p);
                }
            }
            swap(q,q_n);
        }else{

        }
        p = p << 1;
    }


    return 0;
}
