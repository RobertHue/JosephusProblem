# Josephus Problem

A simple method using a list iterator to solve the josephus problem which is already solved mathematically.
But the mathematical solution only finds out the remainder of the problem (a save spot; the candidate which does not get evicted).
Hence, here is a solution, which finds out the sequence in which the candidates are evicted from the ring buffer inside the josephus problem.

## Implementation Prototype

/// @brief method which solves the josephus problem
/// @param0		N	the number of people
/// @param1		K	the people being removed on the table
/// @param2		evadedVectorList	the ordered list of evaded people
/// @ret		the remainder of the josephus problem
int Josephus(int N, int K, std::vector<int>& evadedVectorList);