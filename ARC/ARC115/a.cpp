//
// Created by 原田 on 2021/09/23.
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
typedef vector<vl> vvl;
const long long LINF =1e18;
const int INF = 1e9;



int main() {
    int n;
    cin>>n;



    vvl raw(n,vl(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>raw[i][j];
        }
    }

    if(n == 1){
        cout<<"Yes"<<endl;
        cout<<0<<endl;
        cout<<raw[0][0]<<endl;
        return 0;
    }

    vl diff(n);
    ll min_v = LINF;
    ll min_index = -1;
    for (int i = 0; i < n - 1; ++i) {
        diff[i] = raw[0][i+1] - raw[0][i];
        if(min_v > raw[0][i]){
            chmin(min_v,raw[0][i]);
            min_index = i;
        }
        if(min_v > raw[0][i+1]){
            chmin(min_v,raw[0][i+1]);
            min_index = i + 1;
        }
    }

    vl base(n);
    base[min_index] = 0;
    for (int i = min_index; i < n-1; ++i) {
        base[i+1] = diff[i] + base[i];
    }
    for (int i = min_index; i >= 1; --i) {
        base[i - 1] = base[i] - diff[i - 1];
    }




    vl a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = raw[i][0] - base[0];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(a[i] != raw[i][j] - base[j]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }


    cout<<"Yes"<<endl;
    cout<<a[0];
    for (int i = 1; i < n; ++i) {
        cout<<" "<<a[i];

    }
    cout<<endl;

    cout<<base[0];
    for (int i = 1; i < n; ++i) {
        cout<<" "<<base[i];
    }
    cout<<endl;
    return 0;
}
