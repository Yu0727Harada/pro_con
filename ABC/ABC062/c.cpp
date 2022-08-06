//
// Created by 原田 on 2022/08/05.
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
    ll h,w;
    cin>>h>>w;
    ll ans = INF;

    ll S1;
    ll S2;
    ll S3;
    vl S;
    if(h > 2){
        if(h % 3 == 1){
            S1 = (h / 3) * w;
            S2 = ((h / 3) + 1) * w;
            S3 = ((h / 3)) * w;
            S = {S1,S2,S3};;
            sort(all(S));
            S.clear();
            chmin(ans,abs(S[2] - S[0]));
        }else if(h % 3 == 2){
            S1 = (h / 3) * w;
            S2 = ((h / 3) + 1) * w;
            S3 = ((h / 3) + 1) * w;
            S = {S1,S2,S3};;
            sort(all(S));
            S.clear();
            chmin(ans,abs(S[2] - S[0]));
        }else{
            S1 = (h / 3) * w;
            S2 = ((h / 3)) * w;
            S3 = ((h / 3)) * w;
            S = {S1,S2,S3};;
            sort(all(S));
            S.clear();
            chmin(ans,abs(S[2] - S[0]));
        }

    }
    if(w > 2){
        if(w % 3 == 1){
            S1 = (w / 3) * h;
            S2 = ((w / 3) + 1) * h;
            S3 = ((w / 3)) * h;
            S = {S1,S2,S3};;
            sort(all(S));
            chmin(ans,abs(S[2] - S[0]));
            S.clear();
        }else if(w % 3 == 2){
            S1 = (w / 3) * h;
            S2 = ((w / 3) + 1) * h;
            S3 = ((w / 3) + 1) * h;
            S = {S1,S2,S3};;
            sort(all(S));
            chmin(ans,abs(S[2] - S[0]));
            S.clear();
        }else{
            S1 = (w / 3) * h;
            S2 = ((w / 3)) * h;
            S3 = ((w / 3)) * h;
            S = {S1,S2,S3};;
            sort(all(S));
            chmin(ans,abs(S[2] - S[0]));
            S.clear();
        }

    }

    for (ll i = 1; i <= h; ++i) {
        S1 = i * w;
        S2 = ((h - i) * (w / 2));
        S3 = ((h - i) * ((w / 2) + w % 2));
        S = {S1,S2,S3};;
        sort(all(S));
        chmin(ans,abs(S[2] - S[0]));
        S.clear();
    }
    for (ll i = 1; i <= w; ++i) {
        S1 = i * h;
        S2 = ((w - i) * (h / 2));
        S3 = ((w - i) * ((h / 2) + h % 2));
        S = {S1,S2,S3};;
        sort(all(S));
        chmin(ans,abs(S[2] - S[0]));
        S.clear();
    }
    cout<<ans<<endl;
    return 0;
}
