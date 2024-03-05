#include <iostream>
#include "String.h"
#include <cstring>
#include <cctype>
#include <cstddef>
using namespace std;

int main() {
    // Test cases below

    String hello("Hello, ");
    String world("World");
    String displayMessage("Hello, World");
    cout << displayMessage.CStr();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    cout << "The length of the 'Hello, World' string (not including the null terminator) is: " << displayMessage.Length() << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    cout << "Now we can test the 'characterat' function.  The character at index 7 is: " << displayMessage.CharacterAt(7);
    cout << '\n';

    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    if (hello.EqualTo(world)) {
        cout << "String 1 is equal to String 2\n";
    }
    else {
        cout << "String 1 is not equal to String 2\n";
    }
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    cout << "After using the 'append' function we have: ";
    String appended = hello.Append(world);
    appended.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    cout << "After using the 'prepend' function we have: ";
    String bang("! ");
    String prepended = appended.Prepend(bang);
    prepended.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    displayMessage.ToLower();
    cout << "Testing of the 'ToLower' function.  String in lowercase: "; displayMessage.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    displayMessage.ToUpper();
    cout << "Testing of the 'ToUpper' function.  String in uppercase: "; displayMessage.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';



    size_t foundIndex = displayMessage.Find("RLD");
    if (foundIndex != static_cast<size_t>(-1)) {
        cout << "Using the 'find' function to detect 'RLD' in 'HELLO, WORLD'.  'RLD' is detected to start at index location: " << foundIndex;
    }
    else {
        cout << "String not found: -1";
    }
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';


    size_t foundIndexTwo = displayMessage.Find(3, "RLD");
    if (foundIndexTwo != static_cast<size_t>(-1)) {
        cout << "Using the 'find from index' function to detect 'RLD' in 'HELLO, WORLD' searching only from index location 3.\n'RLD' is detected to start at index location: " << foundIndexTwo;
    }
    else {
        cout << "String not found: -1";
    }
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';


    displayMessage.Replace("HELLO", "GREETINGS");
    cout << "After using the 'replace' function to replace the word 'HELLO' with the word 'GREETINGS', we have: " << displayMessage.CStr();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    cout << "Please enter some numbers or text to test the 'ReadFromConsole' function: ";
    String inputString;
    inputString.ReadFromConsole();
    cout << "You entered: "; inputString.WriteToConsole();
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    String helloTwo("Hello, ");
    String worldTwo("World");
    String displayMessageTwo("Hello, World");
    cout << "Now we can test the 'equality operator' function to check if 'Hello, ' is equal to 'World': " << (helloTwo == worldTwo ? "Equal" : "Not Equal") << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';


    cout << "Testing the 'subscript operator' function to see which character is at index 4 in 'Hello, World': " << displayMessageTwo[4] << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';


    cout << "Testing the 'lessthan operator' function to check if 'Hello, ' comes before 'World' in the alphabet: " << (String(helloTwo) < String(worldTwo) ? "Yes" : "No") << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    system("pause");
}