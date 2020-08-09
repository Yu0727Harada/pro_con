#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
using gragh = vector<vector<int>>;

int main() {
    string S;
    cin>>S;

    if(S=="SUN"){
        cout<<7<<endl;}
    else if(S=="MON"){
        cout<<6<<endl;
        }else if(S=="TUE"){
        cout<<5<<endl;}
    else if(S=="WED"){
        cout<<4<<endl;}
    else if(S=="THU"){
        cout<<3<<endl;}
    else if(S=="FRI"){
        cout<<2<<endl;}
    else if(S=="SAT") {
        cout << 1 << endl;
    }
}
