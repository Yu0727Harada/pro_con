#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    long long N;
    cin>>N;
    string S;
    cin>>S;
    long long ans =1;

    for (int i = 0; i < N-1; ++i) {
        if (S[i] != S[i+1]){
            ans +=1;

        }
    }

    cout<<ans<<endl;

}
