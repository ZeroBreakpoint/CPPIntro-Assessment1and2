#include <iostream>
#include "String.h"
#include <cstring>
#include <cctype>
#include <cstddef>
using namespace std;

// Function to test Length()
//void testLength(const String& str) {
//    cout << "Length of the string (not including the null terminator): " << str.Length() << endl;
//}

//// Function to test CharacterAt(index)
//void testCharacterAt(const String& str, size_t _index) {
//    cout << "Character at index " << _index << ": " << str.CharacterAt(_index) << endl;
//}

// Function to test EqualTo(str)
//void testEqualTo(const String& str1, const String& str2) {
//    cout << "Are strings equal? " << (str1.EqualTo(str2) ? "Yes" : "No") << endl;
//}

//// Function to test Append(str)
//void testAppend(const String& str1, const String& str2) {
//    String nonConstStr1 = str1; // Create a non-const copy
//    String result = nonConstStr1.Append(str2);
//    cout << "After appending: " << result.CStr() << endl;
//}

//// Function to test Prepend(str)
//void testPrepend(const String& str1, const String& str2) {
//    String nonConstStr1 = str1; // Create a non-const copy
//    String result = nonConstStr1.Prepend(str2);
//    cout << "After prepending: " << result.CStr() << endl;
//}

//// Function to test ToLower()
//void testToLower(const String& str) {
//    String result = str;
//    result.ToLower();
//    cout << "String in lowercase: " << result.CStr() << endl;
//}

//// Function to test ToUpper()
//void testToUpper(const String& str) {
//    String result = str;
//    result.ToUpper();
//    cout << "String in uppercase: " << result.CStr() << endl;
//}

//void testFind(const String& str, const String& findStr) {
//    // Create a non-const copy of the string
//    String nonConstStr = str;
//
//    cout << "Find \"" << findStr.CStr() << "\" in \"" << str.CStr() << "\": " << nonConstStr.Find(findStr) << endl;
//}
//
//// Function to test Find(startIndex, findString)
//void testFindFromIndex(const String& str, size_t startIndex, const String& findStr) {
//    // Create a non-const copy of the string
//    String nonConstStr = str;
//
//    cout << "Find \"" << findStr.CStr() << "\" in \"" << str.CStr() << "\" from index " << startIndex << ": " << nonConstStr.Find(startIndex, findStr) << endl;
//}

// Function to test Replace(findString, replaceString)
//void testReplace(String& str, const String& findStr, const String& replaceStr) {
//    str.Replace(findStr, replaceStr);
//    cout << "After replacing \"" << findStr.CStr() << "\" with \"" << replaceStr.CStr() << "\": " << str.CStr() << endl;
//}

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

    cout << "Using the 'find' function to detect 'RLD' in 'HELLO, WORLD'.  'RLD' is detected to start at index location: ";  
    cout << displayMessage.Find("RLD");
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    cout << "Using the 'find from index' function to detect 'RLD' in 'HELLO, WORLD' from index location 4.\n'RLD' is detected to start at index location: ";
    cout << displayMessage.Find( 4, "RLD");
    cout << '\n';
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << '\n';

    //String str5("World");
    //// Create a non-const copy of the string
    //String nonConstStr = displayMessage;

    //// Now you can call the Find function on the non-const copy
    //testFind(nonConstStr, String("HELLO")); // For testing Find(findString)
    //testFindFromIndex(nonConstStr, 7, String("HELLO")); // For testing Find(startIndex, findString)

    /*testReplace(displayMessage, str5, String("Universe"));*/

    // Additional tests for ReadFromConsole(), WriteToConsole(), Equality Operator, Subscript Operator, and Assignment Operator

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