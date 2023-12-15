 #include<iostream>
#include <string>
using namespace std;

string Encryption(string str, int key) {

	string s = str;
	

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = ((s[i]-'a' + key) % 26) + 'a';
		}
		else if (s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = ((s[i] - 'A' + key) % 26) + 'A';
		}
		else {
			s[i] = s[i];
		}

	}
	return s;
}

void Dycreption(string str) {
	
	for (int key = 1; key <= 26; key++) {
		string s = str;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = ((s[i] - 'a' - key + 26) % 26) + 'a';
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = ((s[i] - 'A' - key + 26 ) % 26) + 'A';
			}
			else {
				s[i] = s[i];
			}

		}
		cout << key << "- " << s << endl;
	}
	
}
int main() {
	string x,y;
	int key;
	cout << "enter the text : " ;
	getline(cin, x);
	cout << endl << "enter the key : ";
	cin >> key;
	y = Encryption(x, key); 


	cout << endl << "planitext :" << x<<endl;
		
		cout<<"chiphertext : " << y<<"\n \n \n";
	
	Dycreption(y);
	
}