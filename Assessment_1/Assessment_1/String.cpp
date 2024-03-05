// I have changed the preprocessor definitions on my project to include _CRT_SECURE_NO_WARNINGS to allow for the classic "C style" string functions (such as strcmp, strlen etc) to run without errors / warnings
#include <iostream>
#include "String.h"
#include <cstring>
#include <cctype>
#include <cstddef>
using namespace std;


String::String()
{
	data = new char[1];
	data[0] = '\0';
}

String::String(const char* _str)
{
	data = new char[strlen(_str) + 1]; // Allocating memory on the heap for a character array with size equal to the length of _str + 1 (+ 1 is to account for the null terminator)
	strcpy(data, _str); // Using strcpy function to copy _str into data
}

String::String(const String& _other)
{
	data = new char[_other.Length() + 1];
	strcpy(data, _other.data);
}

String::~String()
{
	delete[] data;  // Cleaning up allocated memory
}


size_t String::Length() const  // Returns an integer representing the count of characters up to the null termination character
{
	size_t length = 0;  // Initialise the string length to zero

	while (data[length] != '\0')  // While loop to keep iterating through the character array until the null terminator is found
	{
		length++;
	}
	return length;  // Output of length of the array
}

char& String::CharacterAt(size_t _index)  // Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'
{
	if (_index >= Length() || _index < 0)
		return data[Length()]; // return the null terminator
	else
		return data[_index];
}

const char& String::CharacterAt(size_t _index) const
{
	// If index is out of bounds, return '\0'
	if (_index >= Length() || _index < 0)
		return data[Length()]; // return the null terminator
	else
		return data[_index];
}

bool String::EqualTo(const String& _other) const  // Returns true if str contains the same characters
{

	return strcmp(data, _other.data) == 0;  // strcmp function used to compare both strings and output 0 if they are the same
}

String& String::Append(const String& _str)  // Adds str to the end of the string
{
	size_t oldLength = Length();
	char* newData = new char[oldLength + _str.Length() + 1];
	strcpy(newData, data);
	strcat(newData, _str.data);
	delete[] data;
	data = newData;  // Delete old data and update to new data
	return *this;
}

String& String::Prepend(const String& _str)  // Adds str to the beginning of the string
{
	size_t oldLength = Length();
	char* newData = new char[oldLength + _str.Length() + 1];
	strcpy(newData, _str.data);
	strcat(newData, data);
	delete[] data;
	data = newData;
	return *this;
}

const char* String::CStr() const  // Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
{
	return data;
}

String& String::ToLower()  // Convert all characters to lowercase
{
	size_t caseLength = Length();
	for (size_t i = 0; i < caseLength; ++i)
	{
		data[i] = tolower(data[i]);
	}
	return *this;
}

String& String::ToUpper()  // Convert all characters to uppercase
{
	size_t caseLength = Length();
	for (size_t i = 0; i < caseLength; ++i)   
	{
		data[i] = toupper(data[i]);
	}
	return *this;
}

size_t String::Find(const String& _str)  // Returns the location of the findString. If not found, return -1
{
	char* found = strstr(data, _str.data);
	if (found != nullptr) {
		return found - data;
	}
	else
	{
		return -1;
	}
}

size_t String::Find(size_t _startIndex, const String& _str)  // Returns the location of the strToFind. Beginning the search from startIndex. If not found, return -1
{
	const char* strToFind = _str.CStr(); 
	size_t length = Length();
	if (_startIndex >= length)
		return static_cast<size_t>(-1); 

	char* found = strstr(data + _startIndex, strToFind); 
	if (found != nullptr) {
		return found - data; 
	}
	return static_cast<size_t>(-1);
}

String& String::Replace(const String& _find, const String& _replace)  // Replaces all occurrences of findString with replaceString
{
	size_t found = Find(_find);
	while (found != string::npos) {
		string temp(data);
		temp.replace(found, _find.Length(), _replace.data);
		*this = temp.c_str();
		found = Find(_find);
	}
	return *this;
}

String& String::ReadFromConsole()
{
	const int bufferSize = 1024;
	char buffer[bufferSize];
	cin.getline(buffer, bufferSize);
	*this = buffer;
	return *this;
}

String& String::WriteToConsole()  // Write the string to the console window
{
	cout << data;
	return *this;
}

bool String::operator==(const String& _other)  // Returns true if lhs == rhs
{
	return EqualTo(_other);
}

bool String::operator!=(const String& _other)
{
	return !EqualTo(_other);
}

String& String::operator=(const String& _str)  // Replaces the characters in lhs with the characters in rhs
{
	if (this != &_str) {
		delete[] data;
		data = new char[_str.Length() + 1];
		strcpy(data, _str.data);
	}
	return *this;
}

bool String::operator<(const String& _other)  // Returns true if this string comes before rhs in the alphabet
{
	return strcmp(data, _other.data) < 0;
}


char& String::operator[](size_t _index)  // Returns the character located at position n
{
	return CharacterAt(_index);
}

const char& String::operator[](size_t _index) const
{
	return CharacterAt(_index);
}
