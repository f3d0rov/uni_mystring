
#include "string.hpp"

String::String(){

}

String::String(int len_, char *str_){
	len = len_;

	if(str_){
		str = str_;
	}else{
		str = new char[len];
	}
}

String::String(const char *str_){
	len = strlen(str_);
	str = new char[len];

	for(int i = 0; i < len; i++){
		str[i] = str_[i];
	}
}

String::String(const String &s){
	len = s.len;
	str = new char[len];

	for(int i = 0; i < len; i++){
		str[i] = s.str[i];
	}
}

String::~String(){
	delete[] str;
}

String &String::operator=(const String &s){
	delete[] str;

	len = s.len;
	str = new char[len];

	for(int i = 0; i < len; i++){
		str[i] = s.str[i];
	}

	return *this;
}

String String::operator+(const String &s){
	String newstr;

	newstr.len = len + s.len;
	newstr.str = new char[newstr.len];

	for(int i = 0; i < len; i++){
		newstr.str[i] = str[i];
	}

	for(int i = 0; i < s.len; i++){
		newstr.str[i + len] = s.str[i];
	}

	return newstr;
}

bool String::operator==(const String &s){
	if(len != s.len) return false;

	for(int i = 0; i < len; i++){
		if(str[i] != s.str[i]) return false;
	}

	return true;
}

bool String::operator!=(const String &s){
	return !(*this == s);
}

bool String::operator<(const String &s){
	int minLen = len < s.len ? len : s.len;

	for(int i = 0; i < minLen; i++){
		if(str[i] < s.str[i]) return true;
		if(str[i] > s.str[i]) return false;
	}

	if(len < s.len){
		return true;
	}

	return false;

}

bool String::operator<=(const String &s){
	int minLen = len < s.len ? len : s.len;

	for(int i = 0; i < minLen; i++){
		if(str[i] < s.str[i]) return true;
		if(str[i] > s.str[i]) return false;
	}

	if(len < s.len){
		return true;
	}else if(len > s.len){
		return false;
	}

	return true;
}

bool String::operator>(const String &s){
	return !(*this <= s);
}

bool String::operator>=(const String &s){
	return !(*this < s);
}

int String::length(){
	return len;
}

char *String::getStr(){
	return str;
}

bool String::isConvertibleToInt(){
	for(int i = 0; i < len; i++){
		if(str[i] < '0' || str[i] > '9') return false;
	}
	return true;
}

long long int String::toInt(){
	long long int result = 0;

	for(int i = 0; i < len; i++){
		result = result * 10 + (str[i] - '0');
	}

	return result;
}


std::istream &operator>>(std::istream &in, String &s){
	bool reading = false;
	int currentLen = 1, pointer = 0;
	char *buffer = new char[currentLen];
	char read = 0;

	while(read = in.get()){
		if(read == '\n' || read == ' ' || read == '\t'){
			if(reading) break;
		}else{
			reading = true;
			buffer[pointer++] = read;

			if(pointer == currentLen){
				char *copy = new char[currentLen * 2];
				
				for(int i = 0; i < currentLen; i++){
					copy[i] = buffer[i];
				}

				currentLen *= 2;

				delete[] buffer;
				buffer = copy;
			}
		}
	}


	s.str = new char[pointer];
	s.len = pointer;

	for(int i = 0; i < pointer; i++){
		s.str[i] = buffer[i];
	}

	delete[] buffer;

	return in;
}

std::ostream &operator<<(std::ostream &out, const String &s){
	for(int i = 0; i < s.len; i++){
		out << s.str[i];
	}
	return out;
}
