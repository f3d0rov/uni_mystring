
#pragma once

#include <iostream>
#include <cstring>

class String{
	private:
		char *str = NULL;
		int len = 0;
	public:
		String();
		String(int len_, char *str_ = NULL);
		String(const char *str_);
		String(const String &s);

		~String();

		String &operator=(const String &s);
		String operator+(const String &s);
		bool operator==(const String &s);
		bool operator!=(const String &s);

		bool operator<(const String &s);
		bool operator<=(const String &s);
		bool operator>(const String &s);
		bool operator>=(const String &s);

		int length();
		char *getStr();

		bool isConvertibleToInt();
		long long int toInt();

		friend std::istream &operator>>(std::istream &in, String &s);
		friend std::ostream &operator<<(std::ostream &out, const String &s);
};
