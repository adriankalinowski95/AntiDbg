#pragma once
#include <iostream>
#include <string_view>

class BaseMethod {
public:
	virtual bool execute() = 0;
	void print(bool status) {
		if(status) {
			std::cout << "[" << getMethodName() << "] Success!" << std::endl;
		}
		else {
			std::cout << "[" << getMethodName() << "] Fail!" << std::endl;
		}
	}

protected:
	virtual std::string_view getMethodName() = 0;
};

