#pragma once
#include <vector>
#include <memory>

namespace anti_debug {
template <class... Methods>
class Caller {
public:
	Caller() : 
		m_methods{std::shared_ptr<Methods>...}
	{
		
	}

	bool execute() {
		bool isCorrect = true;
		for(auto& method : m_methods) {
			auto status = method.execute();
			method.print(status);

			if(!status) {
				isCorrect = false;
			}
		}

		return isCorrect;
	}
private:
	std::vector<std::shared_ptr<BaseMethod>> m_methods;

};
}
