//
// Created by 原田 on 2021/06/17.
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
    deque<char>dq;
    int cnt = 0;
    dq.push_back('b');
    int n;
    string st;
    cin>>n>>st;
    if(st == "b"){
        cout<<0<<endl;
        return 0;
    }
    while(true){
        cnt++;
        dq.push_front('a');
        dq.push_back('c');
        string s = "";
        auto temp = dq;
        while(!temp.empty()){
            s += temp.front();
            temp.pop_front();
        }
        if(st == s){
            cout<<cnt<<endl;
            return 0;
            break;
        }
        cnt++;
        dq.push_front('c');
        dq.push_back('a');
        s = "";
        temp = dq;
        while(!temp.empty()){
            s += temp.front();
            temp.pop_front();
        }
        if(st == s){
            cout<<cnt<<endl;
            return 0;
            break;
        }
        cnt++;
        dq.push_front('b');
        dq.push_back('b');
        s = "";
        temp = dq;
        while(!temp.empty()){
            s += temp.front();
            temp.pop_front();
        }
        if(st == s){
            cout<<cnt<<endl;
            return 0;
            break;
        }
        if(dq.size() > n)break;

    }
    cout<<-1<<endl;
    return 0;
}
