//Roman Numeral Converter

#include <iostream>
#include <string>
using namespace std;

int IntValue(char s);                                       //function to convert individual roman numeral letters to integer values
void ConvertRomanToModern(string numeralRoman);             //function to convert roman numerals to modern numbers
void ConvertModernToRoman(int numberModern);                //function to convert modern numbers to roman numerals

int main() {
    char userSelection = '\0';
    string romanNumeral = "null";
    int modernNumber = 0;
    
   
    cout << "Enter \"r\" to input a roman numeral, \"m\" to input a modern number, or \"q\" to quit:\n";
    cin >> userSelection;
    while (userSelection != 'q') {
        if (userSelection == 'r') {
            cout << "Please enter a roman numeral:\n";
            cin.ignore();
            cin >> romanNumeral;
            ConvertRomanToModern(romanNumeral);
        }
        else if (userSelection == 'm') {
            cout << "Please enter a modern number:\n";
            cin.ignore();
            cin >> modernNumber;
            ConvertModernToRoman(modernNumber);
        }
        else {
            cout << "Invalid entry.\n";
        }
        cout << "Enter \"r\" to input a roman numeral, \"m\" to input a modern number, or \"q\" to quit:\n";
        cin.ignore();
        cin >> userSelection;
    }
    
    cout << "Goodbye!\n";
    
    return 0;
}

int IntValue(char s)                                                          //function to convert individual roman numeral letters to integer values
{
    if (s == 'I')
        return 1;
    if (s == 'V')
        return 5;
    if (s == 'X')
        return 10;
    if (s == 'L')
        return 50;
    if (s == 'C')
        return 100;
    if (s == 'D')
        return 500;
    if (s == 'M')
        return 1000;
    
    return -1;
}

void ConvertRomanToModern(string numeralRoman) {                                //function to convert roman numerals to modern numbers
    int convertedNumber = 0;
    int value1 = 0;
    int value2 = 0;
    
    cout << numeralRoman << " as a modern number: ";
    for (int i = 0; i < numeralRoman.length(); i++) {
        value1 = IntValue(numeralRoman[i]);
        if (i+1 < numeralRoman.length()) {
            value2 = IntValue(numeralRoman[i+1]);
            if (value1 >= value2) {
                convertedNumber = convertedNumber + value1;
            }
            else {
                convertedNumber = convertedNumber + value2 - value1;
                i ++;
            }
        }
        else {
            convertedNumber = convertedNumber + value1;
        }
    }
    cout << convertedNumber << endl;
}

void ConvertModernToRoman(int numberModern) {                                   //function to convert modern numbers to roman numerals
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string numeral[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;
    
    cout << numberModern << " as a roman numeral: ";
    while(numberModern > 0) {
      int div = numberModern/num[i];
      numberModern = numberModern%num[i];
      while(div--) {
        cout << numeral[i];
      }
      i--;
    }
    cout << endl;
}
