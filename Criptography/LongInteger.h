#pragma once
#include <string>
class LongInteger
{
private:
	std::string number_;
public:
	LongInteger();
	LongInteger(std::string number);
	LongInteger(const LongInteger& other_number);
	LongInteger operator+(LongInteger& other_number);
	LongInteger operator-(LongInteger& other_number);
	LongInteger operator*(LongInteger& other_number);
	LongInteger operator=(std::string& string_value);
	bool operator<(LongInteger& other_number);
	bool operator>(LongInteger& other_number);
	bool operator<=(LongInteger& other_number);
	bool operator>=(LongInteger& other_number);
	bool operator==(LongInteger& other_number);
	LongInteger operator+(std::string& other_number);
	LongInteger operator-(std::string& other_number);
	LongInteger operator*(std::string& other_number);
	LongInteger operator+(const char* other_number);
	LongInteger operator-(const char* other_number);
	LongInteger operator*(const char* other_number);
	LongInteger operator+(int other_number);
	LongInteger operator-(int other_number);
	LongInteger operator*(int other_number);
	bool operator< (std::string other_number);
	bool operator> (std::string other_number);
	bool operator<=(std::string other_number);
	bool operator>=(std::string other_number);
	bool operator==(std::string other_number);
	bool operator< (const char* other_number);
	bool operator> (const char* other_number);
	bool operator<=(const char* other_number);
	bool operator>=(const char* other_number);
	bool operator==(const char* other_number);
	std::string KaratsubaMultiply(std::string n, std::string m);
	std::pair<std::string, std::string> KaratsubaDivide(std::string n, std::string m);
	std::string Add(std::string a, std::string b);
	std::string Substract(std::string a, std::string b);
	std::string Multiply(std::string a, std::string b);
	LongInteger& MultiplyWithChar(char x);
	std::string GetPrintableValue();
	std::string TenPow(std::string powerme, int power);
	std::string IntegerToString(int integer);
	bool IsNegative(std::string number);
	void ChangeSign();
	int FloorTen(LongInteger M);
	int Floor(LongInteger numerator, LongInteger denominator);
	~LongInteger();
};

