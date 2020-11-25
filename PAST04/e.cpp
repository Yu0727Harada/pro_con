//
// Created on 2020/11/08.
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
const long long LINF =1e18;
const int INF = 1e9;



int main() {

    int n;
    cin>>n;
    string s;
    cin>>s;

    if(n == 1 || n == 2){
        cout<<"None"<<endl;
        return 0;
    }

    if(n == 3){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(i == j)continue;

                for (int k = 0; k < 3; ++k) {
                    if(j == k || i ==k)continue;
                    string t ="";
                    t += s[i];
                    t += s[j];
                    t += s[k];
                    if(s == t)continue;
                    string rt = t;
                    reverse(all(rt));
                    if(rt == s)continue;
                    cout<<t<<endl;
                    return 0;

                }
            }
        }


    }
    if(n == 4){
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if(i == j)continue;

                for (int k = 0; k < 4; ++k) {
                    if(j == k || i ==k)continue;
                    for (int l = 0; l < 4; ++l) {
                        if(l == i || l ==j || l == k)continue;
                        string t ="";
                        t += s[i];
                        t += s[j];
                        t += s[k];
                        t += s[l];
                        if(s == t)continue;
                        string rt = t;
                        reverse(all(rt));
                        if(rt == s)continue;
                        cout<<t<<endl;
                        return 0;
                    }


                }
            }
        }


    }
    if(n == 5){
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if(i == j)continue;

                for (int k = 0; k < 5; ++k) {
                    if(j == k || i ==k)continue;
                    for (int l = 0; l < 5; ++l) {
                        if(l == i || l ==j || l == k)continue;
                        for (int m = 0; m < 5; ++m) {
                            if(m==i || m == j || m == k || m == l) continue;
                            string t ="";
                            t += s[i];
                            t += s[j];
                            t += s[k];
                            t += s[l];
                            t += s[m];
                            if(s == t)continue;
                            string rt = t;
                            reverse(all(rt));
                            if(rt == s)continue;
                            cout<<t<<endl;
                            return 0;
                        }

                    }


                }
            }
        }


    }
    cout<<"None"<<endl;
    return 0;
}
