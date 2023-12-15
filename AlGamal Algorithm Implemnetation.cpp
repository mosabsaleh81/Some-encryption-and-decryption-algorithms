#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> findPrimitiveRoots(int num) {
    vector<int> primitiveRoots;
    cout<< "all possible primitive roots of q = ";
    for (int i = 2; i < num; i++) {
        bool isPrimitiveRoot = true;
        for (int j = 1; j < num - 1; j++) {
            int x = pow(i, j);
            if ( x % num == 1) {
                isPrimitiveRoot = false;
                break;
            }
        }
        if (isPrimitiveRoot) {
            cout  << i <<"  ";
            primitiveRoots.push_back(i);
        }
    }
    cout << endl;
    return primitiveRoots;
}



int modularExponentiation(int base, int exponent, int modulus) {
    int result = 1;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

int RandomNumber(int min, int max) {
    srand(time(NULL));

    int num = min + rand() % (max - min + 1);
    while (!isPrime(num)) {
        num = min + rand() % (max - min + 1);
    }

    return num;
}

void encrypt(int plaintext) {
    srand(time(NULL));

    int primeNum = RandomNumber(0, 1000);
    cout << "Select q randomly is " << primeNum << endl;

    vector<int> primitiveRoots = findPrimitiveRoots(primeNum);
  

    int primitiveRoot = primitiveRoots[RandomNumber(0, primitiveRoots.size() - 1)];

    int privateKey = RandomNumber(2, primeNum - 2);
    cout << "XA " << privateKey << endl;
    int publicKey = modularExponentiation(primitiveRoot, privateKey, primeNum);

    int randomKey = RandomNumber(2, primeNum - 2);
    int c1 = modularExponentiation(primitiveRoot, randomKey, primeNum);
    int c2 = (modularExponentiation(publicKey, randomKey, primeNum) * plaintext) % primeNum;

    cout << "Encrypted ciphertext (Part 1, Part 2): (" << c1 << ", " << c2 << ")" << endl;

    cout << "Decrypted plaintext: " << (c2 * modularExponentiation(c1, primeNum - 1 - privateKey, primeNum)) % primeNum << endl;
  
}



int main() {
   
    int plaintext;
    cout << "Enter the plaintext to encrypt: ";
    cin >> plaintext;

     encrypt(plaintext);

    

    return 0;
}
