#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>


using namespace std;


int main(){

    ifstream input;
    input.open("decrypt_me.txt", ios::in);
    int numofchars = 0;
    float freq[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char a;
    string line;
    float percentage[26];
    char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

// part 1 getting the frequency of each letter

    a = input.get();
    while (a != EOF)
   {
      cout << a;
      freq[a - 'A']++;
      a = input.get();
   }
input.clear();
input.seekg(0, ios::beg);
//part 2 getting the number of characters
    while( getline(input, line) )
{
    numofchars += line.length();
}
    cout << "\n\n\n\nCharacters: " << numofchars << endl;



// part 3 displaying the results
    for (int i = 0; i <= 25; i++)
  {
        percentage[i] = ((freq[i])/(numofchars));
      cout << alphabet[i] << "\t" << setprecision(3) << percentage[i] * 100 << "%" << endl;
  }


 return 0;

}








