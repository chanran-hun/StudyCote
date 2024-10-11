#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

int main() {
	time_t currentTime = time(NULL);

	tm* localTime = localtime(&currentTime); 

	cout << localTime->tm_year + 1900 << "-"
		 << localTime->tm_mon + 1 << "-"
		 << localTime->tm_mday << endl;

	return 0;
}