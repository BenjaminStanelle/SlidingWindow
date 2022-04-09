#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
string SubStringKUniqueChars(string input, int unique);
int main() {
	string p1 = "abaacacaacda";
	string p2 = "aabbccddc";
	string p3 = "aabacbeeeebeaabb";

	auto result1= SubStringKUniqueChars(p1, 2);
	cout << result1<<endl;

	auto result2 = SubStringKUniqueChars(p2, 2);
	cout << result2 << endl;

	auto result3 = SubStringKUniqueChars(p3, 2);
	cout << result3 << endl;
	return 0;
}

string SubStringKUniqueChars(string input, int unique) {
	if (input.length() <= unique){
		return input;
		}
	if (unique <= 1) {
		return input;
	}
	//create hashmap <character, Running Total Of That Char>
	unordered_map< char, int> hmap; 
	int L = 0, R = 0, max_start = 0, max_length = 0, i, temp, max_len=0;
	while(R< input.length()) {
		hmap[input[R]]++; //increment value of key:input[i] or create and set to 0;
		while (unique < hmap.size()) {
			hmap[input[L]]--;
			if (hmap.find(input[L])->second == 0) {
				hmap.erase(input[L]);
			}

			L++;
		}
		max_len = max(max_len, R - L + 1);

		if (R - L+1 > max_length - max_start) {
			max_length = R;
			max_start = L;
		}

		R++;
	}

	string result = input.substr(max_start, max_length+1-max_start);
	return result;
}