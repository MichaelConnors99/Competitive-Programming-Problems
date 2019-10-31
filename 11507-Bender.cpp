//27/08/19
//UVA problem 11507

#include <iostream>

using namespace std;

int main(){
	int L;
	while(scanf("%d", &L) && L != 0){
		string bend,ans = "+x";
		for(int i = 0;i < L-1;i++){
			cin >> bend;
			//Just a big if else statement
			if(ans == "+x"){
				if(bend != "No"){
					ans = bend;
				}
			}
			else if(ans == "+y"){
				if(bend == "+y"){
					ans = "-x";
				}
				else if(bend == "-y"){
					ans = "+x";
				}
				else if(bend == "+z"){
					ans = "+y";
				}
				else if(bend == "-z"){
					ans = "+y";
				}
			}
			else if(ans == "+z"){
				if(bend == "+y"){
					ans = "+z";
				}
				else if(bend == "-y"){
					ans = "+z";
				}
				else if(bend == "+z"){
					ans = "-x";
				}
				else if(bend == "-z"){
					ans = "+x";
				}
			}
			else if(ans == "-x"){
				if(bend == "+y"){
					ans = "-y";
				}
				else if(bend == "-y"){
					ans = "+y";
				}
				else if(bend == "+z"){
					ans = "-z";
				}
				else if(bend == "-z"){
					ans = "+z";
				}
			}
			else if(ans == "-y"){
				if(bend == "+y"){
					ans = "+x";
				}
				else if(bend == "-y"){
					ans = "-x";
				}
				else if(bend == "+z"){
					ans = "-y";
				}
				else if(bend == "-z"){
					ans = "-y";
				}
			}
			else if(ans == "-z"){
				if(bend == "+y"){
					ans = "-z";
				}
				else if(bend == "-y"){
					ans = "-z";
				}
				else if(bend == "+z"){
					ans = "+x";
				}
				else if(bend == "-z"){
					ans = "-x";
				}
			}
		}
		cout << ans << endl;
	}
}
