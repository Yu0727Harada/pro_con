//
// Created by 原田 on 2021/04/13.
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
    string s1,s2,s3;

    cin>>s1>>s2>>s3;

    map<char,int>mp;
    vl kurai = {0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000};

    for (int i = 0; i < s1.size(); ++i) {
        mp[s1[i]] ++;
    }
    for (int i = 0; i < s2.size(); ++i) {
        mp[s2[i]] ++;
    }
    for (int i = 0; i < s3.size(); ++i) {
        mp[s3[i]] ++;
    }

    if(mp.size() > 10){
        cout<<"UNSOLVABLE"<<endl;
        return 0;
    }

    vector<int> v(10);
    iota(v.begin(), v.end(), 0);       // v に 1, 2, ... N を設定
    do {

        int i = 0;
        for(auto item : mp){
            mp[item.first] = v[i];
            i++;
        }
        bool ok = true;
        ll s1_n = 0;
        for (int j = 1; j <= s1.size(); ++j) {
            s1_n += mp[s1[s1.size() - j]] * kurai[j];
            if(j == s1.size() && mp[s1[s1.size() - j]] == 0){
                ok = false;
            }
        }
        ll s2_n = 0;
        for (int j = 1; j <= s2.size(); ++j) {
            s2_n += mp[s2[s2.size() - j]] * kurai[j];
            if(j == s2.size() && mp[s2[s2.size() - j]] == 0){
                ok = false;
            }
        }
        ll s3_n = 0;
        for (int j = 1; j <= s3.size(); ++j) {
            s3_n += mp[s3[s3.size() - j]] * kurai[j];
            if(j == s3.size() && mp[s3[s3.size() - j]] == 0){
                ok = false;
            }
        }
        if(s1_n + s2_n != s3_n){
            ok = false;
        }
        if(ok){
            cout<<s1_n<<endl;
            cout<<s2_n<<endl;
            cout<<s3_n<<endl;
            return 0;
        }

    } while( next_permutation(v.begin(), v.end()) );     // 次の順列を生成

    cout<<"UNSOLVABLE"<<endl;
    return 0;
}
