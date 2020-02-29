//28/2/20
//UVA 146

#include <bits/stdc++.h>

using namespace std;

int main(){
	char str[50];
	int size = 0;
	while(scanf("%50s",str) && str[0] != '#'){
		if(next_permutation(str,str+strlen(str))){
			cout << str <<endl;
		}
		else{
			cout << "No Successor" << endl;
		}
	}
}
