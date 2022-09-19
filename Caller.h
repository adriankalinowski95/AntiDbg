#pragma once
#include <vector>
#include <memory>
#include "BaseMethod.h"

namespace anti_debug {
template <class... Methods>
class Caller {
	using BaseMethodPtr = std::shared_ptr<BaseMethod>;
public:
	Caller() : 
		m_methods{ std::make_shared<Methods>()...}
	{
		
	}

	bool execute() {
		bool isCorrect = true;
		for(auto& method : m_methods) {
			auto status = method->execute();
			method->print(status);

			if(!status) {
				isCorrect = false;
			}
		}

		return isCorrect;
	}

private:
	std::vector<BaseMethodPtr> m_methods;
};
}
