#pragma once
#include "Printer.h"
#include "Scanner.h"

int getLen(const char* str) {
	int len = 0;
	while (str[len] != '\0') len++;
	return len;
}

char* copyStr(const char* src) {
	int len = getLen(src);
	char* dest = new char[len + 1];
	for (int i = 0; i < len; i++)
		dest[i] = src[i];
	dest[len] = '\0';
	return dest;
}

class AllInOne : public Printer, public Scanner {
private:
	char* modelName;

public:
	AllInOne(int id, int speed, int res, char* model)
		: Device(id), Printer(speed), Scanner(res) {
		modelName = copyStr(model);
		cout << "AllInOne constructor called" << endl;
	}

	void displayAllInOne() const {
		cout << "Model Name: " << modelName << endl;
		displayDevice();
		displayPrinter();
		displayScanner();
	}
};