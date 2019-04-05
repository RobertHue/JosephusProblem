#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

#include <vector>
#include <list>
#include <iostream>

/// @brief erases the element at given index idx inside the passed vector
/// @param0		vec	the vector you want the index to be erased from
/// @param1		idx	the index to be removed
template<typename T>
void eraseVectorAtIndex(std::vector<T>& vec, int idx) {
	std::vector<T>::const_iterator citer = vec.cbegin();
	for (int j = 0; j < idx; ++j)	++citer;
	vec.erase(citer);
}


/// @brief method which solves the josephus problem
/// @param0		N	the number of people
/// @param1		K	the people being removed on the table
/// @param2		evadedVectorList	the ordered list of evaded people
/// @ret		the remainder of the josephus problem
int Josephus(int N, int K, std::vector<int>& evadedVectorList) {

	// setup the josephus problem for N people (ID = i)
	std::list<int> list;
	for (int i = 1; i <= N; ++i) {
		list.push_back(i);
	}
	std::list<int>::iterator iter = list.begin();
	
	// try to solve it
	// int evadeIndex = K -1;
	while (list.size() > 1) {

		for (int j = 0; j < K-1; ++j) {
			++iter;

			// if end of list is reached reset it (iterator out of bounds)
			if (iter == list.end()) {
				iter = list.begin();
			}
		}

		// add the evaded index to the evadedList (param2)
		evadedVectorList.push_back(*iter);

		// erase element at iterator position and advance
		iter = list.erase(iter);

		// if iterator points to the end of the list then advance to the beginning again (ring buffer)
		if (iter == list.end()) { iter = list.begin(); }

		// ::::::::::::::::::::::::::::::::::::::::::::::::::::
		// :::::: different solution than with iterators ::::::
		// ::::::::::::::::::::::::::::::::::::::::::::::::::::
		// eraseVectorAtIndex(list, evadeIndex);
		// advance the index for the next iteration
		// evadeIndex += K-1;
		// if (evadeIndex >= list.size()) {
		//	 evadeIndex = (evadeIndex % list.size());
		// }
	}

	// return the remainder of the josephus problem
	int remainder = list.front();
	return remainder;
}

#endif /* JOSEPHUS_H_ */