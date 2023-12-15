#include<iostream>
#include<string>
using namespace std;



string Encryption(string str, string key) {
	string s = str;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = (((s[i] - 'a') + (key[i%key.size()])-'a') % 26) + 'a';
		}
		
		else {
			s[i] = s[i];
		}

	}
	return s;
}

string Dycreption(string str,string key) {

	string s = str;
	
		for (int i = 0; i < str.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = ((s[i]- 'a') - (key[i % key.size()]-'a' )+ 26) % 26 + 'a';
			}
		
			else {
				s[i] = s[i];
			}

		}
		return s;

}
string  choose_key(int n) {
	string k = "";
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		int r = rand() % 26;
		k += char(r + 'a');

	}
	return k;

}
int main() {

	string plain,chipher, key;
	int nk;
	cout << "enter the text : ";
	getline(cin, plain);
	cout << endl << "enter the number of key : ";
	cin >>nk;
	key= choose_key(nk);
	
	chipher = Encryption(plain, key);
	cout << "*************************\n";

	cout << endl << "ciphertext :" << chipher << endl;
	cout << "*************************\n";

	cout << "key : " << key << endl;
	cout << "*************************\n";
	plain = Dycreption(chipher, key);
	cout << "plaintext :" << plain <<endl;
	


}