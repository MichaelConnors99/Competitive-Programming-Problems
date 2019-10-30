//30/10/19
//UVA problem 11340

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		int K;
		cin >> K;
		map<char,int> values;
		int total = 0;
		while(K--){
			char symbol;
			int value;
			cin >> symbol >> value;
			values[symbol] = value;
		}
		int M;
		cin >> M;
		while(M-- >= 0){
			string line;
			getline(cin,line);
			for(int i = 0;i < line.length();i++){
				if(values.count(line[i]) > 0){
				total += values[line[i]];
				}
			}
		}
		int euro = total / 100;
		int cents = total % 100;
		cout << euro << ".";
		if(cents < 10){
			cout << "0";
		}
		cout << cents << "$" << endl;
	}
}
