#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(0);
    for(int i = 1;i <= 20;i++){
        int twice = i *2;
        int thrice = i* 3;
        if(find(v.begin(),v.end(),i) == v.end()){
            v.push_back(i);
        }
        if(find(v.begin(),v.end(),twice) == v.end()){
            v.push_back(i*2);
        }
        if(find(v.begin(),v.end(),thrice) == v.end()){
            v.push_back(i*3);
        }
    }
    v.push_back(50);
    sort(v.begin(),v.end());
    int score;
    while(cin >> score && score > 0){
        int permutations = 0;
        vector<string> combos;
        int count = 0;
        for(int i = 0;i < v.size();i++){
            for(int j = 0;j < v.size();j++){
                for(int k = 0;k < v.size();k++){
                    if(v[i] + v[j] + v[k] == score){
                        permutations++;
                        string combo = to_string(v[i]) + " " + to_string(v[j]) + " " + to_string(v[k]);
                        if(find(combos.begin(),combos.end(),combo) == combos.end()){
                            combos.push_back(to_string(v[i]) + " " +  to_string(v[j]) + " " +  to_string(v[k]));
                            combos.push_back(to_string(v[i]) + " " +  to_string(v[k]) + " " +  to_string(v[j]));
                            combos.push_back(to_string(v[j]) + " " +  to_string(v[i]) + " " +  to_string(v[k]));
                            combos.push_back(to_string(v[j]) + " " +  to_string(v[k]) + " " +  to_string(v[i]));
                            combos.push_back(to_string(v[k]) + " " +  to_string(v[i]) + " " +  to_string(v[j]));
                            combos.push_back(to_string(v[k]) + " " +  to_string(v[j]) + " " +  to_string(v[i]));
                            count++;
                        }
                    }
                }
            }
        }
        if(permutations == 0){
            cout << "THE SCORE OF " << score << " CANNOT BE MADE WITH THREE DARTS.\n";
        }
        else{
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << score << " IS " << count << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << score << " IS " << permutations << ".\n";
        }
        cout << "**********************************************************************\n";
    }
    cout << "END OF OUTPUT" << endl;
}
