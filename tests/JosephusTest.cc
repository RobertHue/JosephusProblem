#define BOOST_TEST_MODULE "JosephusModule"
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>

#include "Josephus.h"
#include <list>

BOOST_AUTO_TEST_CASE(ERASE_VECTOR_AT_INDEX)
{
	BOOST_TEST_MESSAGE("Test the erasing vector at index of");

	std::vector<int> vec1{ 1,2,3,4,5,6 };
	eraseVectorAtIndex(vec1, 2); // removes the 3 at index 2

	BOOST_CHECK(vec1.at(0) == 1);
	BOOST_CHECK(vec1.at(1) == 2);
	BOOST_CHECK(vec1.at(2) == 4);
	BOOST_CHECK(vec1.at(3) == 5);
	BOOST_CHECK(vec1.at(4) == 6);
}


BOOST_AUTO_TEST_CASE( JOSEPHUS_TEST_N5K2 )
{
	BOOST_TEST_MESSAGE("Test the Josephus Algorithm with N=5 and K=2");

	int N = 5;
	int K = 2;
	std::vector<int> evadedList;
	int remainder = Josephus(5, 2, evadedList);
	/// 0 1 2 3 4 => 1 3 0 4 , rem=2

	BOOST_CHECK(evadedList.at(0) == 1);
	BOOST_CHECK(evadedList.at(1) == 3);
	BOOST_CHECK(evadedList.at(2) == 0);
	BOOST_CHECK(evadedList.at(3) == 4);

	BOOST_CHECK(remainder == 2);
} 
