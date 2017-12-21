// Criptography.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CongruenceClass.h"
#include "LongInteger.h"

int EasyGcd(int first_number, int second_number) {
	int auxiliar = 0;
	while (second_number != 0)
	{
		auxiliar = second_number;
		second_number = first_number % second_number;
		first_number = auxiliar;
	}
	return first_number;
}

int GeneralGcd(int first_number, int second_number) {
	return 0;
}

std::string cEZar_cypher(std::string sentence, char shift)
{
	CongruenceClass x(26);
	CongruenceClass n(shift - 'A' + 1, 26);
	char one_letter;
	int length = sentence.length();
	for (int i = 0; i < length; i++)
	{
		one_letter = sentence[i];
		if (one_letter == ' ')
		{
			continue;
		}
		x = one_letter - 'A';
		x = x - n;
		sentence[i] = 'A' + x.GetValue();
	}
	return sentence;
}

std::string cEZar_decypher(std::string sentence, char shift)
{
	shift = 2 * 'A' - shift -2;
	return cEZar_cypher(sentence, shift);
}



int main()
{
	//LongInteger _a("213");
	//LongInteger _b("450");
	//_a = _b * _a;
	LongInteger q("0");
	q.ActualFractionFloor(LongInteger("5"), LongInteger("3"));
	std::string adunatura = q.KaratsubaMultiply("1495", "876");
	//std::string chipher = "THE CHRISS BROWN FOX JUMPS OVER THE SNOOP DOG";
	//chipher = cEZar_cypher(chipher, 'F');
	//chipher = cEZar_decypher(chipher, 'F');
	std::string fake_a;
	std::string fake_b;
	//LongInteger _a("213");
	//LongInteger _b("450");
	//_a = _a * _b;
	while (1)
	{
		std::cout << "Serviti a: ";
		std::cin >> fake_a;
		std::cout << "Serviti b: ";
		std::cin >> fake_b;
		LongInteger a(fake_a);
		LongInteger b(fake_b);
		a = a * b;
		std::cout << "Craciun Zabeshit: " << a.GetPrintableValue() << std::endl;
	}
    return 0;
}

