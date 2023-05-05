#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <time.h>
using namespace std;

int main() {
    srand (time(NULL));
    random_device crypto_random_generator;
    int param1= 160; // Your choice: change it, if you want, 0 minimum, not too big.
    int param2= 128; // Your choice: change it, if you want, 0 minimum, not too big.
    uniform_int_distribution<int> int_distribution(1, 126 - 32  + param1);
    long long int lengh = 42000;
    long long int lenghLine = 1000;
    string filename = "key.txt";
    string line = "";
    cout << "Yet Another Cryptographic Key Generator v1.0.1." << endl;
    cout << "This software generate a good random printable ASCII file: " << filename << ".\nLengh: " << lengh << endl;
    cout << "Each line is at maximum: " << lenghLine << " long.\nThe lengh of the lines is limited to limit access to the SSD, to preserve it." << endl;
    cout << "Several methods are used and combined, in order to be \"more random\".\nIt's suitable for cryptographic usages!" << endl;
    ofstream fileApp(filename.c_str()); // Is append better?
    if(fileApp.is_open()) {
        int value = 0;
        for ( long long int caractere = 1; caractere<lengh+1; caractere++) {
            value = 32 + (rand()*int_distribution(crypto_random_generator))%(126 + param2); // Paranoid, I combine several methods!
            if ((value>31)&&(value<127)) { // Not always the case, because of param1 and param2. Printable ASCII char value.
                line = line + char(value);
                if ((caractere-1)%lenghLine==0) { //
                    fileApp << line << endl;
                    line="";
                }
            } else {
                caractere--;
            }
        }
        fileApp.close();
    cout << "Ok! You should rename and copy the file!" << endl;
    } else {
        cerr << "Impossible to append to the file " << filename << "!"<< endl;
    }
  
    return 0;
}
