//
// Created on 2021/05/08.
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
#include <array>

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

class item{
public:
    vector<int>per;

};


int main() {
    int n;
    cin>>n;

    vl a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }

    //n個の要素のbit全探索する
    if(n >= 8){
        a.resize(8);
        n = 8;
    }

    vvi l(202,vi());

    for (int bit = 0; bit < (1<<n); ++bit) {

        ll mod = 0;
        for (int i = 0; i < n; ++i) {
            if(bit & (1<<i)){
                mod += a[i] % 200;
                mod %= 200;
            }
        }
        if(bit == 0)continue;
        l[mod].push_back(bit);
        if(l[mod].size() >= 2){
            cout<<"Yes"<<endl;
            vi out;
            for (int i = 0; i < n; ++i) {
                if(l[mod][0] & (1<<i)){
                    out.push_back(i + 1);
                }
            }
            cout<<out.size();
            for(auto item : out){
                cout<<" "<<item;
            }
            cout<<endl;
            out.clear();
            for (int i = 0; i < n; ++i) {
                if(l[mod][1] & (1<<i)){
                    out.push_back(i + 1);
                }
            }
            cout<<out.size();
            for(auto item:out){
                cout<<" "<<item;
            }
            cout<<endl;
            return 0;
        }
    }

    cout<<"No"<<endl;
    return 0;
}
