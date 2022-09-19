#pragma once
#include "BaseMethod.h"

namespace anti_debug {
class Int3 : public BaseMethod {
public:
	bool execute() override;
	std::string_view getMethodName() override;
};
}

