//21/08/19
/*
UVA problem 10141
*/
#include <iostream>

using namespace std;

int main(){
	int n, p;
	int count=1;
	char s[80];
	while(scanf("%d %d", &n, &p) && n != 0 && p != 0 ){
		double lowestPrice = 999999999999999999, price;
		int compliance;
		int highestCompliance = -1;
		string ans="", name="";
		for(int i = 0;i < n;i++){
			scanf(" %[^\n]s",s);
		}

		for(int i = 0;i < p;i++){
			cin.ignore();
			getline(cin,name);
			cin >> price >>compliance;
			if(compliance > highestCompliance){
				highestCompliance = compliance;
				ans = name;
				lowestPrice = price;
			}
			else if(compliance == highestCompliance && price < lowestPrice){
				highestCompliance = compliance;
				ans = name;
				lowestPrice = price;
			}

			for(int j = 0;j < compliance;j++){
				scanf(" %[^\n]s",s);
			}
		}

		if(count > 1){
			cout << "\n";
		}

		cout << "RFP #" << count << endl;
		cout << ans << endl;
		count++;
	}
	return 0;
}
