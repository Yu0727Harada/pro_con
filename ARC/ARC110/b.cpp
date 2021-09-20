//
// Created by 原田 on 2021/09/16.
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

    int n;
    cin>>n;
    string t;
    cin>>t;

    ll ans = 9999999999 + 1;

    if(t == "1"){
        ans *= 2;
        cout<<ans<<endl;
        return 0;
    }else if(t == "0"){
        cout<<ans<<endl;
        return 0;
    }else if(t == "11"){
        cout<<ans<<endl;
        return 0;
    }

    int zero_num = 0;
    int one_num = 0;
    int zero_last = 0;

    for (int i = 0; i < t.size(); ++i) {
        if(t[i] == '1'){
            one_num++;
            if(one_num > 2){
                cout<<0<<endl;
                return 0;
            }
            zero_last = 0;
        }else{
            if(zero_num >= 1 && one_num != 2){
                cout<<0<<endl;
                return 0;
            }
            zero_num++;
            zero_last++;
            if(zero_last > 1){
                cout<<0<<endl;
                return 0;
            }

            one_num = 0;
        }
    }
    if(t[t.size() - 1] == '0'){
        ans -= zero_num - 1;
    }else{
        ans -= zero_num;
    }
    cout<<ans<<endl;

    return 0;
}
