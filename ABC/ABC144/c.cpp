#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
    long long N;
    cin>>N;
    long long ans = 1e13;

    for (long long i = 1; i <= N/i; ++i) {
        if (N%i==0){
            ans = min((i-1+(N/i-1)),ans);
        }

    }

    cout<<ans<<endl;
}
