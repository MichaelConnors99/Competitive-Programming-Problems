
#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int D;
        cin >> D;
        vector<string> makes;
        vector<pair<int,int>> ranges;
        string make;
        int low,high;
        while(D--){
            cin >> make >> low >> high;
            makes.push_back(make);
            ranges.push_back(make_pair(low,high));
        }
        int Q;
        cin >> Q;
        int query;
        string ans = "UNDETERMINED";
        while(Q--){
            ans = "UNDETERMINED";
            cin >> query;
            for(int i = 0;i < makes.size();i++){
                if(query >= ranges[i].first && query <= ranges[i].second){
                    if(ans == "UNDETERMINED")
                        ans = makes[i];
                    else{
                        ans = "UNDETERMINED";
                        break;
                    }
                }
            }
            cout << ans << endl;
        }
        if(T != 0){
            cout << endl;
        }
    }
}
