//
// Created on 2021/09/01.
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
    deque<char>a;
    deque<char>b;
    deque<char>c;

    string sa;
    string sb;
    string sc;
    cin>>sa>>sb>>sc;
    for (int i = 0; i < sa.size(); ++i) {
        a.push_back(sa[i]);
    }
    for (int i = 0; i < sb.size(); ++i) {
        b.push_back(sb[i]);
    }
    for (int i = 0; i < sc.size(); ++i) {
        c.push_back(sc[i]);
    }

    char now = 'a';
    while(true){
        if(now == 'a'){
            if(a.empty()){
                cout<<"A"<<endl;
                break;
            }else{
                now = a.front();
                a.pop_front();
            }
        }
        if(now == 'b'){
            if(b.empty()){
                cout<<"B"<<endl;
                break;
            }else{
                now = b.front();
                b.pop_front();
            }
        }
        if(now == 'c'){
            if(c.empty()){
                cout<<"C"<<endl;
                break;
            }else{
                now = c.front();
                c.pop_front();
            }
        }

    }


    return 0;
}
