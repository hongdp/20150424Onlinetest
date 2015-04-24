#include <iostream>
#include <vector>
using namespace std;

bool onRightDown(int current, int next);
bool maxNum_helper(const vector<int> & series, vector<int> & result, bool back);
int main(){
	int numTestcases;
	cin >> numTestcases;
	for(int i = 0; i < numTestcases; i++){
		string num;
		cin >> num;
		vector<int> series;
		vector<int> resultSeries;
		int result = 0;
		int current = 1;
		for(int j = 0; j < num.length(); j++){
			series.push_back(num[j] - '0');
		}
		maxNum_helper(series, resultSeries, false);
		for(int j = 0; j < resultSeries.size(); j++){
			cout << resultSeries[j];
		}
		cout << endl;
	}
}

bool maxNum_helper(const vector<int> & series, vector<int> & result, bool back){
	int current;
	if(result.size() == 0){
		current = 1;
	}
	else{
		current = result.back();
	}
	int max;
	 if (result.size()){
		// cout << "result.back(): " << result.back() << endl;
		// cout << "series[result.size()-1]: " << series[result.size()-1] << endl;
	}
		
	if(result.size()>=1 && result.back() < series[result.size()-1]){
		back = true;
	}
	if(back){
		max = 9;
	}
	else{
		max = series[result.size()];
	}
	// cout << "back: " << back << endl;
	for(int i = max; i >= 0; i--){
		if(onRightDown(current,i)){
			result.push_back(i);
			if(result.size() == series.size() || maxNum_helper(series, result, back)){
				return true;
			}
			result.pop_back();
		}
	}
	return false;
}


bool onRightDown(int current, int next){
	if(next == 0){
		return current % 3 != 0 || current == 0;
	}
	else{
		return (current+2) % 3 <= (next+2) % 3 && current/3 <= next/3 && current != 0;
	}
}