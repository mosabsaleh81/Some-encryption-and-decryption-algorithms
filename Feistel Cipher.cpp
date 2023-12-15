#include<iostream>
#include<bitset>
#include<string>
using namespace std;


string feistel(string t, bitset<4> key) {
    
    string text=t;
    string chepher="";
    for (int i = 0; i < text.length(); i++) {
        bitset<8> bits;
        bitset <8> new_bits;
        for (int r = 0; r < 16; r++) {
          
            bits = text[i];
            key = ~key;
            //cout << "key =" << key << endl;
            for (int k = 3; k >= 0; k--) {
                new_bits[k + 4] = bits[k];
                new_bits[k] = key[k] ^ bits[k] ^ bits[k + 4];
            }
          // cout << r << " = " << new_bits << endl;

           

        }
       
        for (int k = 3; k >= 0; k--) {
            new_bits[k + 4] = bits[k];
            new_bits[k] = bits[k + 4];
        }

        chepher += new_bits.to_ulong();
    }
  
    return chepher;
}

int main() {

  
    cout << "Enter a text to encrypt : " << endl;
    string text;
    getline(cin, text);

   string binary_text;
   for (char c : text) {
       bitset<8> binary_char(c);
       binary_text += binary_char.to_string();
   }
  

   cout << "Original message : " << text << endl;
   cout << "Original message (binary)  :" << binary_text << endl;

   string ch = feistel(text, 12);

   string binary_chepher;
   for (char c : ch) {
       bitset<8> binary_char(c);
       binary_chepher += binary_char.to_string();
   }
   cout << "\n\n";
   cout << "Encrypted message : " <<ch << endl;
   cout << "Encrypted message (binary) :" << binary_chepher << endl;

   string de = feistel(ch, 12);
   string binary_decrypted;
   for (char c : de) {
       bitset<8> binary_char(c);
       binary_decrypted += binary_char.to_string();
   }
   cout<<"\n\n";
   cout << "Decrypted message : " <<de  << endl;
   cout << "Decrypted message (binary) :" << binary_decrypted << endl;

 

}
