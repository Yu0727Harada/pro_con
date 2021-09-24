//
// Created by 原田 on 2021/09/21.
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

    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    a--;
    b--;
    c--;
    d--;
    string s;
    cin>>s;

    if(a < b && c < d ){
        //交差なし
        for (int i = 1; i < n; ++i) {
            if(s[i-1] == '#' && s[i] == '#'){
                if((a < i && i < c) || (b < i && i < d)){
                    //範囲内に連続してたらだめ
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
        cout<<"Yes"<<endl;
        return 0;
    }else{
        //交差あり
        bool blank_find = false;
        if(s[0] == '#' && s[1] == '#'){
            if((a < 1 && 1 < c) || (b < 1 && 1 < d)){
                //範囲内に連続してたら
                cout<<"No"<<endl;
                return 0;
            }
        }
        for (int i = 2; i < n; ++i) {
            if(s[i-1] == '#' && s[i] == '#'){
                if((a < i && i < c) || (b < i && i < d)){
                    //範囲内に連続してたらだめ
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            if(s[i-2] == '.' && s[i-1] == '.' && s[i] == '.'){
                if((b <= i - 1 && i - 1 <= d)){
                    blank_find = true;
                }
            }
        }
        if(blank_find){
            cout<<"Yes"<<endl;
            return 0;
        }else{
            cout<<"No"<<endl;
            return 0;
        }
    }

    return 0;
}
