#pragma once
class CongruenceClass
{
private:
	int modulo_;
	int value_;
public:
	CongruenceClass();
	~CongruenceClass();
	CongruenceClass(int modulo);
	CongruenceClass(int value, int modulo);
	CongruenceClass(const CongruenceClass& congruence_class);
	//CongruenceClass& operator=(const CongruenceClass& other_class);
	CongruenceClass operator+(const CongruenceClass& other_class);
	CongruenceClass operator-(const CongruenceClass& other_class);
	CongruenceClass operator*(const CongruenceClass& other_class);
	CongruenceClass operator=(const int& operand);
	CongruenceClass operator+(const int& operand);
	CongruenceClass operator-(const int& operand);
	CongruenceClass operator*(const int& operand);
	bool operator==(const CongruenceClass& other_class);
	bool operator==(const int& operand);
	bool operator>(const CongruenceClass& other_class);
	bool operator>(const int& operand);
	bool operator<(const CongruenceClass& other_class);
	bool operator<(const int& operand);
	bool operator>=(const CongruenceClass& other_class);
	bool operator>=(const int& operand);
	bool operator<=(const CongruenceClass& other_class);
	bool operator<=(const int& operand);
	int GetValue();
	CongruenceClass& Inverse();
};

