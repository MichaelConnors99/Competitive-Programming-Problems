#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,A,B,C;
    cin >> N;
    while(N--){
        cin >> A >> B >> C;
        bool run = true;
        for(int x = -100;x < 22 & run;x++){
            for(int y = -100;y < 99 & run;y++){
                for(int z = 0;z < 100 & run;z++){
                    if(x + y + z == A && x * y * z == B && x*x + y*y + z*z == C){
                        if(x != y && x != z && y != z){
                            cout << x << " " << y << " " << z << endl;
                            run = false;
                            break;
                        }
                    }
                }
            }
        }
        if(run)
            cout << "No solution." << endl;
    }
}
