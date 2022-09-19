#pragma once
#include "BaseMethod.h"

namespace anti_debug {
class Int3 : public BaseMethod {
public:
	bool execute() override;
	void print(bool status) override;
};
}

