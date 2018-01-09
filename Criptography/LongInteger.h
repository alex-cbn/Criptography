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
	LongInteger& MultiplyWithChar(char x);
	std::string GetPrintableValue();
	bool Sign();
	void ChangeSign();

	LongInteger operator+(LongInteger& other_number);
	LongInteger operator-(LongInteger& other_number);
	LongInteger operator*(LongInteger& other_number);
	LongInteger operator=(std::string& string_value);

	LongInteger operator+(std::string& other_number);
	LongInteger operator-(std::string& other_number);
	LongInteger operator*(std::string& other_number);

	LongInteger operator+(const char* other_number);
	LongInteger operator-(const char* other_number);
	LongInteger operator*(const char* other_number);

	LongInteger operator+(int other_number);
	LongInteger operator-(int other_number);
	LongInteger operator*(int other_number);

	bool operator<(LongInteger& other_number);
	bool operator>(LongInteger& other_number);
	bool operator<=(LongInteger& other_number);
	bool operator>=(LongInteger& other_number);
	bool operator==(LongInteger& other_number);

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

	static std::string KaratsubaMultiply(std::string n, std::string m);
	static std::pair<std::string, std::string> KaratsubaDivide(std::string n, std::string m);
	static std::string Add(std::string a, std::string b);
	static std::string Substract(std::string a, std::string b);
	static std::string Multiply(std::string a, std::string b);
	static std::string TenPow(std::string powerme, int power);
	static std::string IntegerToString(int integer);
	static bool IsNegative(std::string number);
	static int FloorTen(LongInteger M);
	static int Floor(LongInteger numerator, LongInteger denominator);
	static int ActualFractionFloor(LongInteger numerator, LongInteger denominator);
	static int ActualFractionCeil(LongInteger numerator, LongInteger denominator);
	~LongInteger();
};

