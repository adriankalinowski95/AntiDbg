#pragma once
#include <string_view>

class BaseMethod {
public:
	virtual bool execute() = 0;
	virtual void print(bool status) = 0;

protected:
	void printMethod(std::string_view methodName) {

	}
};

