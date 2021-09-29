//
// Created by 原田 on 2021/09/29.
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

    //-A B-
    //B-A B-A

    int a_end_only = 0;
    int b_start_only = 0;
    int b_start_a_end = 0;
    int internal_ab = 0;

    for (int i = 0; i < n; ++i) {
        string s;
        cin>>s;
        if(s[0] == 'B' && s[s.size() - 1] == 'A')b_start_a_end++;
        else if(s[0] == 'B')b_start_only++;
        else if(s[s.size() - 1] == 'A')a_end_only++;
        for (int j = 0; j < s.size() - 1; ++j) {
            if(s[j] == 'A' && s[j + 1] == 'B')internal_ab++;
        }
    }

    int ans = 0;
    ans += internal_ab;
    ans += max(b_start_a_end - 1,0);
    if(a_end_only >= 1 && b_start_a_end >= 1){ans++;a_end_only--;}
    if(b_start_only >= 1 && b_start_a_end >=1){ans++;b_start_only--;}
    int t = min(a_end_only,b_start_only);
    ans += t;

    cout<<ans<<endl;



    return 0;
}

//すぬけ君は N 個の文字列を持っています。i 番目の文字列は si​ です。
//
//これらの文字列を好きな順序で並べたあと、連結して 1 つの文字列を作ることを考えます。 作った文字列に AB という部分文字列が含まれる個数としてありうる値のうち、最大値を求めてください。