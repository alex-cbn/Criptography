#include "stdafx.h"
#include "CongruenceClass.h"


CongruenceClass::CongruenceClass()
{
}

CongruenceClass::~CongruenceClass()
{
}

CongruenceClass::CongruenceClass(int modulo)
{
	modulo_ = modulo;
}

CongruenceClass::CongruenceClass(int value, int modulo)
{
	if (value < 0)
	{
		value = value * -1;
		value %= this->modulo_;
		value_ = modulo - value;
		modulo_ = modulo;
		return;
	}
	value_ = value % modulo;
	modulo_ = modulo;
}

CongruenceClass::CongruenceClass(const CongruenceClass & congruence_class)
{
	this->value_ = congruence_class.value_;
	this->modulo_ = congruence_class.modulo_;
}

//CongruenceClass & CongruenceClass::operator=(const CongruenceClass & other_class)
//{
//	modulo_ = other_class.modulo_;
//	value_ = other_class.value_;
//	return *this;
//}

CongruenceClass CongruenceClass::operator+(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		int new_value = this->value_;
		new_value += other_class.value_;
		new_value %= this->modulo_;
		return CongruenceClass(new_value, modulo_);
	}
	return CongruenceClass(this->value_, this->modulo_);
}

CongruenceClass CongruenceClass::operator-(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		int new_value = this->value_;
		new_value -= other_class.value_;
		if (new_value < 0)
		{
			new_value = new_value * -1;
			new_value %= this->modulo_;
			return CongruenceClass(modulo_ - new_value, modulo_);
		}
		new_value %= this->modulo_;
		return CongruenceClass(new_value, modulo_);
	}
	return CongruenceClass(this->value_, this->modulo_);
}

CongruenceClass CongruenceClass::operator*(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		int new_value = this->value_;
		new_value *= other_class.value_;
		new_value %= this->modulo_;
		return CongruenceClass(new_value, modulo_);
	}
	return CongruenceClass(this->value_, this->modulo_);
}

CongruenceClass CongruenceClass::operator=(const int & operand)
{
	this->value_ = operand;
	int new_value = operand;
	if (new_value < 0)
	{
		new_value = new_value * -1;
		new_value %= this->modulo_;
		return CongruenceClass(modulo_ - new_value, modulo_);
	}
	this->value_ %= this->modulo_;
	return CongruenceClass(this->value_, this->modulo_);
}

CongruenceClass CongruenceClass::operator+(const int & operand)
{
	int new_value = this->value_;
	new_value += operand;
	new_value %= this->modulo_;
	return CongruenceClass(new_value, modulo_);
}

CongruenceClass CongruenceClass::operator-(const int & operand)
{
	int new_value = this->value_;
	new_value -= operand;
	if (new_value < 0)
	{
		new_value = new_value * -1;
		new_value %= this->modulo_;
		return CongruenceClass(modulo_ - new_value, modulo_);
	}
	new_value %= this->modulo_;
	return CongruenceClass(new_value, modulo_);
}

CongruenceClass CongruenceClass::operator*(const int & operand)
{
	int new_value = this->value_;
	new_value *= operand;
	new_value %= this->modulo_;
	return CongruenceClass(new_value, modulo_);
}

bool CongruenceClass::operator==(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		return (this->value_ == other_class.value_);
	}
	else
	{
		return false;
	}
}

bool CongruenceClass::operator==(const int & operand)
{
	return this->value_ == operand % this->modulo_;
}

bool CongruenceClass::operator>(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		return (this->value_ > other_class.value_);
	}
	else
	{
		return false;
	}
}

bool CongruenceClass::operator>(const int & operand)
{
	return this->value_ > operand % this->modulo_;
}

bool CongruenceClass::operator<(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		return (this->value_ < other_class.value_);
	}
	else
	{
		return false;
	}
}

bool CongruenceClass::operator<(const int & operand)
{
	return this->value_ < operand % this->modulo_;
}

bool CongruenceClass::operator>=(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		return (this->value_ >= other_class.value_);
	}
	else
	{
		return false;
	}
}

bool CongruenceClass::operator>=(const int & operand)
{
	return this->value_ >= operand % this->modulo_;
}

bool CongruenceClass::operator<=(const CongruenceClass & other_class)
{
	if (this->modulo_ == other_class.modulo_)
	{
		return (this->value_ <= other_class.value_);
	}
	else
	{
		return false;
	}
}

bool CongruenceClass::operator<=(const int & operand)
{
	return this->value_ <= operand % this->modulo_;
}

int CongruenceClass::GetValue()
{
	return value_;
}

CongruenceClass & CongruenceClass::Inverse()
{
	CongruenceClass inverse = *this;
	for (int i = 0; i < modulo_; i++)
	{
		if (inverse * i == 1)
		{
			inverse = i;
			return inverse;
		}
	}
	printf("Valoare eronata\n");
}
