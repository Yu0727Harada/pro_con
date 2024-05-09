//
// Created by yu on 2023/11/28.
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
    int n,k,q;
    cin>>n>>k>>q;
    vi koma(k,0);
    vi masu(n,0);
    for (int i = 0; i < k; ++i) {
        int a;
        cin>>a;
        a--;
        koma[i] = a;
        masu[a]++;
    }
    for (int i = 0; i < q; ++i) {
        int l;
        cin>>l;
        l--;

            if(koma[l] == n - 1)continue;
            else{
                if(masu[koma[l] + 1] == 0){
                    masu[koma[l]] = 0;
                    masu[koma[l] + 1] ++;
                    koma[l] = koma[l]+1;

                }else{
                    continue;
                }
            }

    }
    for (int i = 0; i < n; ++i) {
        if(masu[i]){
            cout<<i+1<<endl;
        }
    }
    return 0;
}
