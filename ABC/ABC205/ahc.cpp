//
// Created on 2021/06/26.
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

bool check(vector<string>a, string target,int upper){
    for (int i = 0; i < upper; ++i) {
        if (a[i].find(target) != std::string::npos) {
            return false;
        }
    }


    return true;
}
void InitRand()
{
    srand((unsigned int)time(NULL));
}

int main() {

    InitRand();

    int n,m;
    cin>>n>>m;
    //vector<vector<char>> s(n,vector<char>(n,'.'));
    vector<string>a(n,"");
    vector<vector<string>> dic(20,vector<string>());

    for (int i = 0; i < m; ++i) {
        string temp;
        cin>>temp;
        dic[temp.size()].push_back(temp);

    }

    for (int i = 0; i < n; ++i) {
        for (int j = 7; j < 20; ++j) {
            if(dic[j].empty()){
                continue;
            }
            if(a[i].size() + j >= 20){
                break;
            }
            string target = dic[j].back();
            dic[j].pop_back();
            if(check(a,target,i)){
                a[i] += target;
            }
        }
        for (int j = 6; j >= 0; --j) {
            if(dic[j].empty()){
                continue;
            }
            if(a[i].size()+j >= 20){
                continue;
            }
            string target = dic[j].back();
            dic[j].pop_back();
            if(check(a,target,i)){a[i]+= target;}
        }
        while(a[i].size() < 20){
            int r = rand() % 8;
            vector<char> vv = {'A','B','C','D','E','F','G','H'};
            a[i] += vv[r];
        }

    }

    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<endl;
    }

    return 0;
}
