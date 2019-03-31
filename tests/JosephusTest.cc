#define BOOST_TEST_MODULE "JosephusModule"
#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test_parameters.hpp>

#include "Josephus.h"
#include <list>
#include <vector>


BOOST_AUTO_TEST_CASE(ERASE_VECTOR_AT_INDEX)
{
	boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_all_errors);
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
	boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_all_errors);
	int N = 5;
	int K = 2;
	BOOST_TEST_MESSAGE("Test the Josephus Algorithm with N=" << N << " and K= " << K << " !!!");

	std::vector<int> evadedVectorList;
	int remainder = Josephus(N, K, evadedVectorList);
	/// 1 2 3 4 5 => 1 3 4 5 => 1 3 5 (1. durchlauf vorbei) => 3 5 => 3
	// sol : 2 4 1 5 , rem=3
	// math.sol: remainder = 1001 => 00011 = 3

	BOOST_CHECK(evadedVectorList.at(0) == 2);
	BOOST_CHECK(evadedVectorList.at(1) == 4);
	BOOST_CHECK(evadedVectorList.at(2) == 1);
	BOOST_CHECK(evadedVectorList.at(3) == 5);

	BOOST_CHECK(remainder == 3);
} 



BOOST_AUTO_TEST_CASE(JOSEPHUS_TEST_N5K11)
{
	boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_all_errors);
	int N = 5;
	int K = 11;
	BOOST_TEST_MESSAGE("Test the Josephus Algorithm with N=" << N << " and K= "<< K <<" !!!");

	std::vector<int> evadedVectorList;
	int remainder = Josephus(N, K, evadedVectorList);
	// sol : 1  4 2 3  rem 5
	// math.sol: remainder = 5^1 + 5^0 = 5 rem = 5

	BOOST_CHECK(evadedVectorList.at(0) == 1);
	BOOST_CHECK(evadedVectorList.at(1) == 4);
	BOOST_CHECK(evadedVectorList.at(2) == 2);
	BOOST_CHECK(evadedVectorList.at(3) == 3);

	BOOST_CHECK(remainder == 5);
}


BOOST_AUTO_TEST_CASE(JOSEPHUS_TEST_N13K2)
{
	boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_all_errors);
	int N = 13;
	int K = 2;
	BOOST_TEST_MESSAGE("Test the Josephus Algorithm with N=" << N << " and K= " << K << " !!!");

	std::vector<int> evadedVectorList;
	int remainder = Josephus(N, K, evadedVectorList);
	/// 11
	// sol : 2 4 6 8 10 12 (all even positions done) 1 5 9 13 7 3 rem 11
	// math.sol: remainder = 1101 => 1011 = 11 

	BOOST_CHECK(evadedVectorList.at(0) == 2);
	BOOST_CHECK(evadedVectorList.at(1) == 4);
	BOOST_CHECK(evadedVectorList.at(2) == 6);
	BOOST_CHECK(evadedVectorList.at(3) == 8);
	BOOST_CHECK(evadedVectorList.at(4) == 10);
	BOOST_CHECK(evadedVectorList.at(5) == 12);
	BOOST_CHECK(evadedVectorList.at(6) == 1);
	BOOST_CHECK(evadedVectorList.at(7) == 5);
	BOOST_CHECK(evadedVectorList.at(8) == 9);
	BOOST_CHECK(evadedVectorList.at(9) == 13);
	BOOST_CHECK(evadedVectorList.at(10) == 7);
	BOOST_CHECK(evadedVectorList.at(11) == 3);

	BOOST_CHECK(remainder == 11);
}



BOOST_AUTO_TEST_CASE(JOSEPHUS_TEST_N13K3)
{
	boost::unit_test::unit_test_log.set_threshold_level(boost::unit_test::log_all_errors);
	int N = 13;
	int K = 3;
	BOOST_TEST_MESSAGE("Test the Josephus Algorithm with N=" << N << " and K= " << K << " !!!");

	std::vector<int> evadedVectorList;
	int remainder = Josephus(N, K, evadedVectorList);
	///  
	// sol: 3 6 9 12 2  7  11  4 10 5  1  8 rem 13

	// math.sol: remainder = 3^2 + 3^1 + 3^0 = 13 so rem is 13


	BOOST_CHECK(evadedVectorList.at(0) == 3);
	BOOST_CHECK(evadedVectorList.at(1) == 6);
	BOOST_CHECK(evadedVectorList.at(2) == 9);
	BOOST_CHECK(evadedVectorList.at(3) == 12);
	BOOST_CHECK(evadedVectorList.at(4) == 2);
	BOOST_CHECK(evadedVectorList.at(5) == 7);
	BOOST_CHECK(evadedVectorList.at(6) == 11);
	BOOST_CHECK(evadedVectorList.at(7) == 4);
	BOOST_CHECK(evadedVectorList.at(8) == 10);
	BOOST_CHECK(evadedVectorList.at(9) == 5);
	BOOST_CHECK(evadedVectorList.at(10) == 1);
	BOOST_CHECK(evadedVectorList.at(11) == 8);

	BOOST_CHECK(remainder == 13);
}
