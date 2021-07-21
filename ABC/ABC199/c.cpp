//
// Created on 2021/04/24.
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

    int n;
    cin>>n;
    string s;
    cin>>s;
    int q;
    cin>>q;

    string f_s = s.substr(0,n);
    string b_s = s.substr(n,n);

    bool muki = true;

    for (int i = 0; i < q; ++i) {
        int t,a,b;
        cin>>t>>a>>b;
        a--;
        b--;
        if(t == 1){
            if(muki){
                if(a >= n && b >= n){
                    a -= n;
                    b -= n;
                    swap(b_s[a],b_s[b]);
                }
                else if(b >= n && a < n){
                    b -= n;
                    swap(f_s[a],b_s[b]);
                }else if(b < n && a < n){
                    swap(f_s[a],f_s[b]);
                }
            }else{
                if(a >= n && b >= n){
                    a -= n;
                    b -= n;
                    swap(f_s[a],f_s[b]);
                }
                else if(b >= n && a < n){
                    b -= n;
                    swap(b_s[a],f_s[b]);
                }else if(b < n && a < n){
                    swap(b_s[a],b_s[b]);
                }
            }

        }else{
            muki = !muki;
        }

    }

    if(muki){
        cout<<f_s<<b_s<<endl;
    }else{
        cout<<b_s<<f_s<<endl;
    }

    return 0;
}

