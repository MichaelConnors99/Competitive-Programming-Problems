// 16/8/19
/*
takes in two integers and prints if a is greater than less than or equal to b
*/
#include <iostream>
using namespace std;
int main(){
	int T, a, b;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &a, &b);
		if(a<b){printf("%c\n",'<');}
		else if(a>b){printf("%c\n", '>');}
		else{printf("%c\n", '=');}
	}
	return 0;
}
