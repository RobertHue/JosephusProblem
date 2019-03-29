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


/// @brief method which solves the josephus problem
/// @param0		N	the number of people
/// @param1		K	the people being removed on the table
/// @param2		evadedList	the ordered list of evaded people
/// @ret		the remainder of the josephus problem
int Josephus(int N, int K, std::vector<int>& evadedList) {
	// @TODO what happens if K is greater than N?

	// setup the josephus problem for N
	std::vector<int> list;
	for (int i = 0; i < N; ++i) {
		list.push_back(i);
	}

	// try to solve it
	int evadeIndex = K - 1;
	while (list.size() > 1) {
		// debug output: not really needed..
		std::cout	<<	"removed at:"			<< evadeIndex 
					<<	" - with value of: "	<< list.at(evadeIndex) 
					<< std::endl;

		// add the evaded index to the evadedList parameter for testing 
		// and erase it from josephus list
		evadedList.push_back(list.at(evadeIndex));
		eraseVectorAtIndex(list, evadeIndex);
		
		// advance the index for the next iteration
		evadeIndex += K-1;
		if (evadeIndex > list.size()) {
			evadeIndex = (evadeIndex % list.size())+1;
		}
	}

	// return the remainder of the josephus problem
	int remainder = list.front();
	return remainder;
}

/// leider hat es nicht so geklappt mit der Bewerbung
#endif /* JOSEPHUS_H_ */







//// :::FRAGENKATALOG:::
// was bedeutet virtual?
// was ist der unterschied zwischen einer klasse und einem objekt
// wie kann ich informationen verstecken?
// was ist der unterschied zwischen python und c++
// gibt es einen unterschied bei tmeplates in java zu c++
// wozu dienen templates?


// Erzählen sie mal was über sich (10 min) - keine aufzählung mehr sondern eher die motivation...
// Wie schätzen sie sich ein in c++
// die lebenshaltungskosten sind in münchen höher. mit 18€h hätte man kein informatik studieren brauchen...

// MAS mixed mode ferchau vllt noch? ka ach was solls...