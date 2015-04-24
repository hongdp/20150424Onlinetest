#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <stack>
using namespace std;

unordered_map<string, int> existSubStrMap;
priority_queue<string> existSubStrQueue;
stack<string> strStack;

bool isFebNum(int num);
bool isLuckySubStr(int, int, const string&);

int main(){
	string inputStr;
	cin >> inputStr;
	// cout << inputStr << endl;
	for(int indFront = 0; indFront < inputStr.length(); indFront++){
		for(int indBack = 1; indBack <= inputStr.length()-indFront; indBack++){
			if(isLuckySubStr(indFront,indFront+indBack-1,inputStr)){
				// cout << "yes" << endl;
				string temp = inputStr.substr(indFront,indBack);
				if(existSubStrMap.find(temp) == existSubStrMap.end()){
					// cout << "can't find" << endl;
					existSubStrQueue.push(temp);
					existSubStrMap.insert(make_pair(temp, 1));
				}
			}
		}
	}
	while(!existSubStrQueue.empty()){
		strStack.push(existSubStrQueue.top());
		existSubStrQueue.pop();
	}
	while(!strStack.empty()){
		cout << strStack.top() << endl;
		strStack.pop();
	}
	return 0;
}

bool isFebNum(int num){
	return num == 1 || num == 2 || num == 3 || num == 5 || num == 8 || num == 13 || num == 21;
}

bool isLuckySubStr(int front, int back, const string& inputStr){
	bool charList[26] = {};
	int numDiffChar = 0;
	
	for(int i = front; i <= back; i++){
		// cout << inputStr[i] << endl;
		if(!charList[inputStr[i]-'a']){
			numDiffChar++;
			charList[inputStr[i]-'a'] = true;
		}
	}
	// cout << "substr: " << inputStr.substr(front,back-front+1) << " " << numDiffChar << endl;
	return isFebNum(numDiffChar);
}