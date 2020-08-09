#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
using gragh = vector<vector<int>>;

int alphabet_pos(char c,int n){
    if('A' <= c && c <= 'X') {
        if (c-'A'+ n )> ){
            return c - 'A'+ n;

        }else{
            return c - 'A'+ n;
        }
    }
    return -1;
}

char ex(int x){
    return char(x);
}


int main() {
    int N;
    string S;
    cin>>N;
    cin>>S;
    vector<string>alpa(26);
//    for (int j = 0; j < 26; ++j) {
//        alpa[j+char('A')] = char();
//    }

    for (int i = 0; i < S.size(); ++i) {
        char c = S[i];
        cout<<char('A'+ alphabet_pos(c,N))<<endl;

    }

}
