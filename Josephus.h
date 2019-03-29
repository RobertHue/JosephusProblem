#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

#include <vector>
#include <iostream>

template<typename T>
void eraseVectorAtIndex(std::vector<T>& vec, int idx) {
	std::vector<T>::const_iterator iter = vec.cbegin();
	for (int j = 0; j < idx; ++j)	++iter;
	vec.erase(iter);
}


int Josephus(int N, int K, std::vector<int>& evadedList) {

	// setup some josephus problem
	std::vector<int> list;
	for (int i = 0; i < N; ++i) {
		list.push_back(i);
	}

	// try to solve it
	int evadeIndex = K - 1;
	while (list.size() > 1) {
		std::cout << "removed at:" << evadeIndex << std::endl;
		evadedList.push_back(list.at(evadeIndex));

		eraseVectorAtIndex(list, evadeIndex);
		
		evadeIndex += K;

		if (evadeIndex > list.size()) {
			evadeIndex = evadeIndex % list.size();
		}
	}

	int remainder = list.front();
	return remainder;
}

#endif /* JOSEPHUS_H_ */