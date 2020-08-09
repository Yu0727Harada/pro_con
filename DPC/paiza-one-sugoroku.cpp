#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<string>dize(6+1);
    vector<string> ID = {"T","B","U","D","L","R"};

    int number;
    for (string id:ID) {
        cin>>number;
        dize[number] =id;
    }

    int ans = 0;
    int p = 0;
    int last;
    int N;
    cin>>N;

    cin>>p;

    for (int i = 0; i < N-1; ++i) {
        last=p;
        cin>>p;
        if((dize[p]=="T" && dize[last]=="B") ||
           (dize[p]=="B" && dize[last]=="T") ||
           (dize[p]=="L" && dize[last]=="R") ||
           (dize[p]=="R" && dize[last]=="L")  ||
           (dize[p]=="U" && dize[last]=="D") ||
           (dize[p]=="D" && dize[last]=="U"))
        {
            ans +=2;
        }else if(dize[p]==dize[last]){
            continue;
        }else{
            ans++;
        }
    }

    cout<<ans<<endl;

}