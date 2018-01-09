#include "stdafx.h"
#include "LongInteger.h"


LongInteger::LongInteger()
{
	number_ = "";
}

LongInteger::LongInteger(std::string number)
{
	number_ = number;
}

LongInteger::LongInteger(const LongInteger & other_number)
{
	this->number_ = other_number.number_;
}

LongInteger LongInteger::operator+(LongInteger & other_number)
{
	LongInteger This(*this);
	LongInteger Other(other_number);
	if (IsNegative(this->number_) && IsNegative(other_number.number_))
	{
		This.ChangeSign();
		Other.ChangeSign();
		LongInteger result = This + Other;
		result.ChangeSign();
		return result;
	}
	if (IsNegative(this->number_) && !IsNegative(other_number.number_))
	{
		This.ChangeSign();
		return Other - This;
	}
	if (!IsNegative(this->number_) && IsNegative(other_number.number_))
	{
		Other.ChangeSign();
		return This - Other;
	}
	std::string result = "";
	std::string first_number = This.number_;
	std::string second_number = Other.number_;
	std::reverse(first_number.begin(), first_number.end());
	std::reverse(second_number.begin(), second_number.end());
	int first_number_length = first_number.length();
	int second_number_length = second_number.length();
	int max_length = first_number_length;
	if (max_length < second_number_length)
	{
		max_length = second_number_length;
	}
	int carry = 0;
	for (int i = 0; i < max_length; i++)
	{
		int first_digit = 0;
		int second_digit = 0;
		int next_digit = 0;
		if (i < first_number_length)
		{
			first_digit = first_number[i] - '0';
		}
		if (i < second_number_length)
		{
			second_digit = second_number[i] - '0';
		}
		next_digit = first_digit + second_digit + carry;
		carry = next_digit / 10;
		next_digit %= 10;
		result += ('0' + next_digit);
	}
	if (carry != 0)
	{
		result += '1';
	}
	std::reverse(result.begin(), result.end());
	return LongInteger(result);
}

LongInteger LongInteger::operator-(LongInteger & other_number)
{
	LongInteger This(*this);
	LongInteger Other(other_number);
	if (IsNegative(this->number_) && IsNegative(other_number.number_))
	{
		Other.ChangeSign();
		return This + Other;
	}
	if (IsNegative(this->number_) && !IsNegative(other_number.number_))
	{
		LongInteger result("0");
		This.ChangeSign();
		result = This + Other;
		result.ChangeSign();
		return result;
	}
	if (!IsNegative(this->number_) && IsNegative(other_number.number_))
	{
		Other.ChangeSign();
		return This + Other;
	}
	std::string result;
	std::string first_number = This.number_;
	std::string second_number = Other.number_;

	bool is_inversed = false;
	if (first_number == second_number)
	{
		return LongInteger("0");
	}
	if (LongInteger(this->number_) < other_number)
	{
		result = first_number;
		first_number = second_number;
		second_number = result;
		result = "";
		is_inversed = true;
	}

	int first_number_length = first_number.length();
	int second_number_length = second_number.length();
	int difference = 0;

	if (first_number_length > second_number_length)
	{
		difference = first_number_length - second_number_length;
		result = first_number.substr(0, difference);
	}

	int carry = 0;
	for (int i = difference; i < first_number_length; i++)
	{
		int first_digit = 0;
		int second_digit = 0;
		int next_digit = 0;
		first_digit = first_number[i] - '0';
		second_digit = second_number[i - difference] - '0';
		next_digit = first_digit - second_digit;
		if (next_digit >= 0)
		{
			next_digit %= 10;
		}
		else
		{
			next_digit = (next_digit + 10) % 10;
			if (result[i - 1] == '0')
			{
				int k = 1;
				result[i - 1] = '9';
				while (result[i - 1 - k] == '0')
				{
					result[i - 1 - k] = '9';
					k++;
				}
				result[i - 1 - k] = result[i - 1 - k] - 1;
			}
			else
			{
				result[i - 1] = result[i - 1] - 1;
			}
		}
		result += ('0' + next_digit);

	}
	int first_zero = 0;
	int result_length = result.length();
	for (first_zero; first_zero < result_length; first_zero++)
	{
		if (result[first_zero] != '0')
		{
			break;
		}
	}
	result = result.substr(first_zero, result.length());
	if (is_inversed)
	{
		result = "-" + result;
		return *(new LongInteger(result));
	}
	return LongInteger(result);
}

LongInteger LongInteger::operator*(LongInteger & other_number)
{
	LongInteger This(*this);
	LongInteger Other(other_number);
	bool is_negative = IsNegative(this->number_) ^ IsNegative(other_number.number_);
	if (IsNegative(this->number_))
	{
		This.ChangeSign();
	}
	if (IsNegative(other_number.number_))
	{
		Other.ChangeSign();
	}
	LongInteger _result;
	LongInteger result("0");
	LongInteger partial_result("0");
	std::string first_number = This.number_;
	std::string second_number = Other.number_;
	std::reverse(second_number.begin(), second_number.end());
	int first_number_length = first_number.length();
	int second_number_length = second_number.length();
	for (int pow = 0; pow < second_number_length; pow++)
	{
		partial_result = first_number;
		partial_result = partial_result.MultiplyWithChar(second_number[pow]);
		std::string zeros = "";
		for (int i = 0; i < pow; i++)
		{
			zeros += "0";
		}
		partial_result = partial_result.GetPrintableValue() + zeros;
		result = result + partial_result;
	}
	if (!is_negative)
	{
		return result;
	}
	else
	{
		result.ChangeSign();
		return result;
	}

}

LongInteger LongInteger::operator=(std::string & string_value)
{
	number_ = string_value;
	return LongInteger(number_);
}

bool LongInteger::operator<(LongInteger & other_number)
{
	LongInteger This(this->number_);
	LongInteger Other(other_number.number_);
	bool this_negative = IsNegative(This.number_);
	bool other_negative = IsNegative(Other.number_);
	if (this_negative && other_negative)
	{
		This.ChangeSign();
		Other.ChangeSign();
		return This > Other;
	}
	if (this_negative && !other_negative)
	{
		return true;
	}
	if ((!this_negative && other_negative))
	{
		return false;
	}
	if (this->number_.length() != other_number.number_.length())
	{
		return this->number_.length() < other_number.number_.length();
	}
	else
	{
		return this->number_ < other_number.number_;
	}
}

bool LongInteger::operator>(LongInteger & other_number)
{
	if ((*this == other_number) || (*this < other_number))
	{
		return false;
	}
	return true;
}

bool LongInteger::operator<=(LongInteger & other_number)
{
	return (*this < other_number) || (*this == other_number);
}

bool LongInteger::operator>=(LongInteger & other_number)
{
	return (*this > other_number) || (*this == other_number);
}

bool LongInteger::operator==(LongInteger & other_number)
{
	return this->number_ == other_number.number_;
}

LongInteger LongInteger::operator+(std::string & other_number)
{
	LongInteger result(other_number);
	result = result + *this;
	return result;
}

LongInteger LongInteger::operator-(std::string & other_number)
{
	LongInteger result(other_number);
	result = *this - result;
	return result;
}

LongInteger LongInteger::operator*(std::string & other_number)
{
	LongInteger result(other_number);
	result = result * *this;
	return result;
}

//LongInteger LongInteger::operator+(std::string other_number)
//{
//	LongInteger result(other_number);
//	result = result + *this;
//	return result;
//}
//
//LongInteger LongInteger::operator-(std::string other_number)
//{
//	LongInteger result(other_number);
//	result = *this -result;
//	return result;
//}
//
//LongInteger LongInteger::operator*(std::string other_number)
//{
//	LongInteger result(other_number);
//	result = result * *this;
//	return result;
//}

LongInteger LongInteger::operator+(const char * other_number)
{
	LongInteger result(other_number);
	result = *this + result;
	return result;
}

LongInteger LongInteger::operator-(const char * other_number)
{
	LongInteger result(other_number);
	result = *this - result;
	return result;
}

LongInteger LongInteger::operator*(const char * other_number)
{
	LongInteger result(other_number);
	result = *this * result;
	return result;
}

LongInteger LongInteger::operator+(int other_number)
{
	LongInteger Other(IntegerToString(other_number));
	return *this + Other;
}

LongInteger LongInteger::operator-(int other_number)
{
	LongInteger Other(IntegerToString(other_number));
	return *this - Other;
}

LongInteger LongInteger::operator*(int other_number)
{
	LongInteger Other(IntegerToString(other_number));
	return *this * Other;
}

bool LongInteger::operator<(std::string other_number)
{
	LongInteger Other(other_number);
	return *this < Other;
}

bool LongInteger::operator>(std::string other_number)
{
	LongInteger Other(other_number);
	return *this > Other;
}

bool LongInteger::operator<=(std::string other_number)
{
	LongInteger Other(other_number);
	return *this <= Other;
}

bool LongInteger::operator>=(std::string other_number)
{
	LongInteger Other(other_number);
	return *this >= Other;
}

bool LongInteger::operator==(std::string other_number)
{
	return other_number == this->number_;
}

bool LongInteger::operator<(const char * other_number)
{
	return *this < std::string(other_number);
}

bool LongInteger::operator>(const char * other_number)
{
	return *this > std::string(other_number);
}

bool LongInteger::operator<=(const char * other_number)
{
	return *this <= std::string(other_number);
}

bool LongInteger::operator>=(const char * other_number)
{
	return *this >= std::string(other_number);
}

bool LongInteger::operator==(const char * other_number)
{
	return *this == std::string(other_number);
}

std::string LongInteger::KaratsubaMultiply(std::string n, std::string m)
{
	LongInteger N(n);
	LongInteger M(m);
	LongInteger ten("10");
	if ((N < ten) && (M < ten))
	{
		std::string buffer;
		int result = atoi(n.c_str()) * atoi(m.c_str());
		while (result != 0)
		{
			buffer = char('0' + result % 10) + buffer;
			result /= 10;
		}
		if (buffer == "")
		{
			buffer = "0";
		}
		return std::string(buffer);
	}
	else
	{
		int min_length = 0;
		int n_length = n.length();
		int m_length = m.length();
		if (n_length > m_length)
		{
			min_length = m_length;
		}
		else
		{
			min_length = n_length;
		}
		int k = (min_length + 1) / 2;
		std::string a = n.substr(0, n_length - k);
		std::string b = n.substr(n_length - k, n_length);
		std::string c = m.substr(0, m_length - k);
		std::string d = m.substr(m_length - k, m_length);
		std::string prod_1 = TenPow(KaratsubaMultiply(a, c), 2 * k);
		std::string prod_2 = KaratsubaMultiply(Add(a, b), Add(c, d));
		std::string prod_3 = KaratsubaMultiply(a, c);
		std::string prod_4 = KaratsubaMultiply(b, d);
		std::string fact_2 = Substract(prod_2, prod_3);
		fact_2 = Substract(fact_2, prod_4);
		fact_2 = TenPow(fact_2, k);
		std::string result = Add(prod_1, fact_2);
		result = Add(result, prod_4);
		return result;
	}
}

std::pair<std::string, std::string> LongInteger::KaratsubaDivide(std::string n, std::string m)
{
	LongInteger N(n);
	LongInteger M(m);
	if (N == "0")
	{
		return std::make_pair("0", "0");
	}
	if (M == "1")
	{
		return std::make_pair(n, "0");
	}
	if (M < "0")
	{
		M.ChangeSign();
		std::pair<std::string, std::string> _return = KaratsubaDivide(N.GetPrintableValue(), M.GetPrintableValue());
		LongInteger Q(_return.first);
		LongInteger R(_return.second);
		Q.ChangeSign();
		return std::make_pair(Q.GetPrintableValue(), R.GetPrintableValue());

	}
	if (N < "0")
	{
		N.ChangeSign();
		std::pair<std::string, std::string> _return = KaratsubaDivide(N.GetPrintableValue(), M.GetPrintableValue());
		LongInteger Q(_return.first);
		LongInteger R(_return.second);
		if (R > "0")
		{
			Q.ChangeSign();
			Q = Q - "1";
			R = M - R;
			return std::make_pair(Q.GetPrintableValue(), R.GetPrintableValue());
		}
		if (R == "0")
		{
			Q.ChangeSign();
			return std::make_pair(Q.GetPrintableValue(), "0");
		}
		return std::make_pair(Q.GetPrintableValue(), R.GetPrintableValue());

	}
	int N_length = n.length();
	int M_length = m.length();
	if (N_length < M_length)
	{
		return std::make_pair("0", N.GetPrintableValue());
	}
	if (N_length == M_length)
	{
		std::string guess_q = "0";
		for (int i = 0; i < 10; i++)
		{
			guess_q[0] = (char)('0' + i);
			LongInteger N_new = M * guess_q;
			if (N == N_new)
			{
				return std::make_pair(guess_q, N_new.GetPrintableValue());
			}
		}
	}
	if (N_length > M_length)
	{
		int floor = FloorTen(M);
		LongInteger TenM = LongInteger(TenPow("1", M_length));
		LongInteger TenNM = LongInteger(TenPow("1", N_length - M_length));
		LongInteger left = M * floor;
		left = TenM - left;
		left = left * 2;
		LongInteger y_0, y_i, y_i_1;
		y_0 = TenNM;
		if (left <= m)
		{
			y_0 = y_0 * floor;
		}
		else
		{
			y_0 = y_0 * (floor + 1);
		}
		int i = 0;
		y_i_1 = y_0;
		do
		{
			y_i = y_i_1;
			LongInteger y_i_sq = y_i * y_i;
			int floor_in = Floor(y_i_sq, TenNM);
			LongInteger FakeM = M * floor_in;
			int floor_real = Floor(FakeM, TenM);
			y_i_1 = y_i;
			y_i_1 = y_i_1 * 2;
			y_i_1 = y_i_1 - floor_real;
		} while (i<1 || y_i_1>y_i); // pasul 10
	}
	return std::pair<std::string, std::string>();
}

std::string LongInteger::Add(std::string a, std::string b)
{
	LongInteger La(a);
	LongInteger Lb(b);
	La = La + Lb;
	return La.GetPrintableValue();
}

std::string LongInteger::Substract(std::string a, std::string b)
{
	LongInteger La(a);
	LongInteger Lb(b);
	La = La - Lb;
	return La.GetPrintableValue();
}

std::string LongInteger::Multiply(std::string a, std::string b)
{
	LongInteger La(a);
	LongInteger Lb(b);
	La = La * Lb;
	return La.GetPrintableValue();
}

LongInteger & LongInteger::MultiplyWithChar(char x)
{
	int multiply_factor = x - '0';
	std::string result;
	std::string first_number = this->number_;
	std::reverse(first_number.begin(), first_number.end());
	int length = first_number.length();
	int carry = 0;
	for (int i = 0; i < length; i++)
	{
		int digit = first_number[i] - '0';
		int new_digit = multiply_factor * digit + carry;
		carry = new_digit / 10;
		new_digit = new_digit % 10;
		result += (new_digit + '0');
	}
	result += (carry + '0');
	std::reverse(result.begin(), result.end());
	return *new LongInteger(result);
}

std::string LongInteger::GetPrintableValue()
{
	int first_zero = 0;
	int number_length = number_.length();
	for (first_zero; first_zero < number_length; first_zero++)
	{
		if (number_[first_zero] != '0')
		{
			break;
		}
	}
	number_ = number_.substr(first_zero, number_.length());
	if (number_ == "")
	{
		number_ = "0";
	}
	return number_;
}

std::string LongInteger::TenPow(std::string powerme, int power)
{
	std::string zeros;
	for (int i = 0; i < power; i++)
	{
		zeros += "0";
	}
	zeros = powerme + zeros;
	return zeros;
}

std::string LongInteger::IntegerToString(int integer)
{
	std::string result;
	while (integer != 0)
	{
		result = char('0' + integer % 10) + result;
		integer /= 10;
	}
	return std::string(result);
}

bool LongInteger::IsNegative(std::string number)
{
	if (number == "")
	{
		return false;
	}
	if (number[0] == '-')
	{
		return true;
	}
	return false;
}

bool LongInteger::Sign()
{
	return !this->IsNegative(this->number_);
}

void LongInteger::ChangeSign()
{
	if (IsNegative(number_))
	{
		number_ = number_.substr(1, number_.length());
	}
	else
	{
		number_ = "-" + number_;
	}
}

int LongInteger::FloorTen(LongInteger M)
{
	int M_length = M.GetPrintableValue().length();
	LongInteger TenM = TenPow("1", M_length);
	int floor = 1;
	LongInteger minimum = M;
	for (int i = 1; i <= 10; i++)
	{
		LongInteger result;
		result = M * i;
		result = TenM - result;
		if (result < 0)
		{
			break;
		}
		else
		{
			if (result < minimum)
			{
				minimum = result;
				floor = i;
			}
		}
	}
	return floor;
}

int LongInteger::Floor(LongInteger numerator, LongInteger denominator)
{
	int floor = 1;
	LongInteger minimum = denominator;
	for (int i = 1; i <= 10; i++)
	{
		LongInteger result;
		result = denominator * i;
		result = numerator - result;
		if (result < 0)
		{
			break;
		}
		else
		{
			if (result < minimum)
			{
				minimum = result;
				floor = i;
			}
		}
	}
	return floor;
}

int LongInteger::ActualFractionFloor(LongInteger numerator, LongInteger denominator)
{
	LongInteger NUM = numerator;
	LongInteger DEN = denominator;
	bool result_sign=true;
	if (!NUM.Sign())
	{
		NUM.ChangeSign();
		result_sign = !result_sign;
	}
	if (!DEN.Sign())
	{
		DEN.ChangeSign();
		result_sign = !result_sign;
	}
	int floor = 0;
	LongInteger guess("0");
	while (guess <= NUM)
	{
		guess = guess + DEN;
		floor++;
	}
	if (result_sign)
	{
		return floor - 1;
	}
	else
	{
		return -(floor);
	}
}

int LongInteger::ActualFractionCeil(LongInteger numerator, LongInteger denominator)
{
	return ActualFractionFloor(numerator, denominator) + 1;
}

LongInteger::~LongInteger()
{
}
