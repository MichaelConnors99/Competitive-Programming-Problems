//16/8/19
/*
UVA problem 10114
*/


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int loans(int loanDuration, float downPayment, float loan, vector<pair<int,float>> depreciationInfo){
	int monthsPassed=0;
	float value=loan+downPayment;
	float payment=loan/loanDuration;

	for(int i = 0;i < depreciationInfo.size();i++){//iterates through array of depriation rates
		int time=depreciationInfo[i+1].first-depreciationInfo[i].first;//calculates duration of the depreciation
		//Applies depreciation and takes payment from loan
		for(int j = 0;j < time;j++){
			if(monthsPassed!=0){//doesnt pay loan on month 0
				loan-=payment;
			}
			value-=value*depreciationInfo[i].second;
			if(value>loan){
				return monthsPassed;
			}
			monthsPassed++;
		}
	}
	while(value<loan){//this is for when there is no more changes in depreciation rates
		loan-=payment;
		value-=value*depreciationInfo[depreciationInfo.size()-1].second;
		if(value<loan){
			monthsPassed++;
		}
	}
	return monthsPassed;

}
int main(){
	int loanDuration, no_of_depreciations;
	float payment,loan;
	while(scanf("%d", &loanDuration) && loanDuration > 0){//end case is a negative number for months

		int month; 
		float depreciation;		
		vector<pair<int,float>> depreciationInfo;

		scanf("%a %a %d", &payment, &loan, &no_of_depreciations);
		while(no_of_depreciations--){
			scanf("%d %a", &month, &depreciation);
			depreciationInfo.push_back(make_pair(month,depreciation));//fills up array with depreciation rates
		}

		int ans=loans(loanDuration, payment, loan, depreciationInfo);
		if(ans==1){
			cout<<"1 month"<<endl;
		}
		else{
			cout<<ans<<" months"<<endl;
		}
	}
}
