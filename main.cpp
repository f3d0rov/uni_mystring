
#include <iostream>

#include "string.hpp"

int main(){
	std::cout << "Input your name: ";

	String name;

	std::cin >> name;
	String hello = String("Hello, ") + name + "!";
	std::cout << hello << std::endl;

	std::cout << "Length of your name: " << name.length() << std::endl;

	String compare;
	std::cout << "Input string to compare your name to: ";
	std::cin >> compare;

	if(name < compare){
		std::cout << "\"" << name << "\" is alphabetically before \"" << compare << "\"" << std::endl;
	}else if(name == compare){
		std::cout << "\"" << name << "\" is equal to \"" << compare << "\"" << std::endl;
	}else{
		std::cout << "\"" << name << "\" is alphabetically after \"" << compare << "\"" << std::endl;
	}

	String convert;

	std::cout << "Input string to convert to int: ";
	std::cin >> convert;

	if(convert.isConvertibleToInt()){
		long long int result = convert.toInt();
		std::cout << "Converted int: " << result << std::endl;
	}else{
		std::cout << "Cannot convert \"" << convert << "\" to int" << std::endl;
	}

	std::cout << "ENTER to end program...";
	std::cin.get();

	return 0;
}
