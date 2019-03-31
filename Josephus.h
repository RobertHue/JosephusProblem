#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

#include <vector>
#include <list>
#include <iostream>

template<typename T>
void eraseVectorAtIndex(std::vector<T>& vec, int idx) {
	std::vector<T>::const_iterator citer = vec.cbegin();
	for (int j = 0; j < idx; ++j)	++citer;
	vec.erase(citer);
}


/// @brief method which solves the josephus problem
/// @param0		N	the number of people
/// @param1		K	the people being removed on the table
/// @param2		evadedList	the ordered list of evaded people
/// @ret		the remainder of the josephus problem
int Josephus(int N, int K, std::vector<int>& evadedVectorList) {
	// @TODO what happens if K is greater than N?

	// setup the josephus problem for N
	std::list<int> list;
	for (int i = 1; i <= N; ++i) {
		list.push_back(i);
	}


	std::list<int>::iterator iter = list.begin();
	

	// try to solve it
	int evadeIndex = K -1;
	while (list.size() > 1) {

		for (int j = 0; j < K-1; ++j) {
			++iter;

			// if end of list is reached reset it (iterator out of bounds)
			if (iter == list.end()) {
				iter = list.begin();
			}
		}

		// debug output: not really needed..
		std::cout << "removed value of: " << *iter << std::endl;

		// add the evaded index to the evadedList parameter for testing 
		// and erase it from josephus list
		evadedVectorList.push_back(*iter);

		//std::list<int>::iterator tmpIter;
		//if (iter == list.end() || iter == list.end()-1) { tmpIter = list.begin(); }
		//else { tmpIter = iter + 1; }
		iter = list.erase(iter); // iterator is invalid after erase, so TODO here...
		//iter = tmpIter;
		if (iter == list.end()) { iter = list.begin(); }
		
		 
		//eraseVectorAtIndex(list, evadeIndex);
		
		// advance the index for the next iteration
		//evadeIndex += K-1;
		//if (evadeIndex >= list.size()) {
		//	evadeIndex = (evadeIndex % list.size());
		//}
	}

	// return the remainder of the josephus problem
	int remainder = list.front();
	return remainder;
}

#endif /* JOSEPHUS_H_ */


//// :::FRAGENKATALOG:::
// Erzählen sie mal was über sich (10 min) - 
//		hier am besten keine aufzählung; sondern eher die persönliche motivation

// Wie schätzen sie sich ein in c++
//		Relativ gut was die Grundlagen betrifft. oder bessser: solide Grundlagen?
//		Was bibliotheken der STL/STD betrifft so muss ich noch manchmal nachschauen wie das war mit Methodenaufruf xy

// was ist der unterschied zwischen einer klasse und einem objekt
// klasse ist bauplan eines objekts und objekt ist die instanz bzw. ausführung einer klasse, die dann auch Hauptspeicher belegt

// wie kann ich informationen verstecken? 
//		public private protected

// was bedeutet virtual? 
//		virtual ermöglicht es in C++ Objekte dynamisch zu binden; d.h. die Objekte bekommen von ihren Oberklassen virtual definierte Methoden mit 

// was ist der unterschied zwischen python und c++
//		in python wird der code zeilenweise interpretiert

// würden Sie in Betracht ziehen python zu programmieren? würde das Ihnen spaß machen?
//		ja aufjedenfall. In blender hab ich da auch mal was mit python probiert (menger_sponge) und während meiner tätigkeit bei der Bachelorarbeit konnte ich auch bereits einiges über python lernen. 
//		Von dem her denke ich, dass mir die weitere Einarbeitung in python gut umsetzbar ist.

// wozu dienen templates?
//		um einen algorithmus/methode für unterschiedliche arten von typen (uint8, uint16) funktionsfähig zu machen.

// gibt es einen unterschied bei templates in java zu c++
//		habe das in java noch nie so wirklich im detail untersucht
