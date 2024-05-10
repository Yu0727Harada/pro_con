//
// Created by yu on 2024/04/24.
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

pair<vi,vi> t_blank(int n,vvi t){
    vi s_blank_row ;
    for (int i = 0; i < n; ++i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(t[i][j] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_row.push_back(i);
        }else{
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(t[i][j] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_row.push_back(i);
        }else{
            break;
        }
    }
    sort(all(s_blank_row));

    vi s_blank_col ;
    for (int i = 0; i < n; ++i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(t[j][i] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_col.push_back(i);
        }else{
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(t[j][i] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_col.push_back(i);
        }else{
            break;
        }
    }
    sort(all(s_blank_col));
    return {s_blank_row,s_blank_col};
}

vvi rotate(vvi t,int n){
    vvi ret(n,vi(n,0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(t[i][j]){
                ret[j][n - 1 - i] = 1;
            }
        }
    }
    return ret;
}

bool check_same(int n,vvi t,vvi s,int s_itr_begin, int s_itr_end,int s_itr_jbegin, int s_itr_jend){
    pair<vi,vi> tmp = t_blank(n,t);
    vi t_blank_row = tmp.first;
    vi t_blank_col = tmp.second;
    int t_itr_begin = 0;
    int t_itr_end = n - 1;
    for (int i = 0; i < t_blank_row.size(); ++i) {
        if(t_blank_row[i] != t_itr_begin){
            break;
        }else{
            t_itr_begin = t_blank_row[i] + 1;
        }
    }
    for (int i = t_blank_row.size() - 1; i >= 0 ; --i) {
        if(t_blank_row[i] != t_itr_end){
            break;
        }else{
            t_itr_end = t_blank_row[i] - 1;
        }
    }
    int t_itr_jbegin = 0;
    int t_itr_jend = n - 1;
    for (int i = 0; i < t_blank_col.size(); ++i) {
        if(t_blank_col[i] != t_itr_jbegin){
            break;
        }else{
            t_itr_jbegin = t_blank_col[i] + 1;
        }
    }
    for (int i = t_blank_col.size() - 1; i >= 0 ; --i) {
        if(t_blank_col[i] != t_itr_jend){
            break;
        }else{
            t_itr_jend = t_blank_col[i] - 1;
        }
    }

    bool ok = true;
    int si_itr = s_itr_begin;
    int ti_itr = t_itr_begin;
    while(si_itr <= s_itr_end && ti_itr <= t_itr_end){
        int sj_itr = s_itr_jbegin;
        int tj_itr = t_itr_jbegin;
        while(sj_itr <= s_itr_jend && tj_itr <= t_itr_jend){
            if(s[si_itr][sj_itr] != t[ti_itr][tj_itr]){
                ok = false;
            }

            sj_itr++;
            tj_itr++;
        }
        if(sj_itr != s_itr_jend + 1 || tj_itr != t_itr_jend + 1)ok =false;
        si_itr++;
        ti_itr++;
    }
    if(si_itr != s_itr_end + 1 || ti_itr != t_itr_end + 1)ok = false;
    return ok;
}

int main() {
    int n;
    cin>>n;
    vvi s(n,vi(n,0));
    vvi t(n,vi(n,0));
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin>>tmp;
        for (int j = 0; j < n; ++j) {
            if(tmp[j] == '#'){
                s[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin>>tmp;
        for (int j = 0; j < n; ++j) {
            if(tmp[j] == '#'){
                t[i][j] = 1;
            }
        }
    }
    vi s_blank_row ;
    for (int i = 0; i < n; ++i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(s[i][j] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_row.push_back(i);
        }else{
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(s[i][j] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_row.push_back(i);
        }else{
            break;
        }
    }
    sort(all(s_blank_row));

    vi s_blank_col ;
    for (int i = 0; i < n; ++i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(s[j][i] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_col.push_back(i);
        }else{
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int blank_is = true;
        for (int j = 0; j < n; ++j) {
            if(s[j][i] == 1)blank_is = false;
        }
        if(blank_is){
            s_blank_col.push_back(i);
        }else{
            break;
        }
    }
    sort(all(s_blank_col));

    int s_itr_begin = 0;
    int s_itr_end = n - 1;
    for (int i = 0; i < s_blank_row.size(); ++i) {
        if(s_blank_row[i] != s_itr_begin){
            break;
        }else{
            s_itr_begin = s_blank_row[i] + 1;
        }
    }
    for (int i = s_blank_row.size() - 1; i >= 0 ; --i) {
        if(s_blank_row[i] != s_itr_end){
            break;
        }else{
            s_itr_end = s_blank_row[i] - 1;
        }
    }

    int s_itr_jbegin = 0;
    int s_itr_jend = n - 1;

    for (int i = 0; i < s_blank_col.size(); ++i) {
        if(s_blank_col[i] != s_itr_jbegin){
            break;
        }else{
            s_itr_jbegin = s_blank_col[i] + 1;
        }
    }
    for (int i = s_blank_col.size() - 1; i >= 0 ; --i) {
        if(s_blank_col[i] != s_itr_jend){
            break;
        }else{
            s_itr_jend = s_blank_col[i] - 1;
        }
    }

    if(check_same(n,t,s,s_itr_begin,s_itr_end,s_itr_jbegin,s_itr_jend)){
        cout<<"Yes"<<endl;
        return 0;
    }
    t = rotate(t,n);
    if(check_same(n,t,s,s_itr_begin,s_itr_end,s_itr_jbegin,s_itr_jend)){
        cout<<"Yes"<<endl;
        return 0;
    }
    t = rotate(t,n);
    if(check_same(n,t,s,s_itr_begin,s_itr_end,s_itr_jbegin,s_itr_jend)){
        cout<<"Yes"<<endl;
        return 0;
    }
    t = rotate(t,n);
    if(check_same(n,t,s,s_itr_begin,s_itr_end,s_itr_jbegin,s_itr_jend)){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}
