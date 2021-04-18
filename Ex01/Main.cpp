#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main()
{
	const int NUM_FLOATS = 10000;
	// Create two input vectors with 10,000 floats
	std::vector<float> inputA;
	std::vector<float> inputB;

	// Create several destination vector of 10,000 floats 
	std::vector<float> destSeq(NUM_FLOATS);
	std::vector<float> destPar(NUM_FLOATS);
	std::vector<float> destParUnseq(NUM_FLOATS);
	
	// Old way (same as std::execution::seq)
	std::transform(
		inputA.begin(), inputA.end(), // Begin/end of 1st input range
		inputB.begin(), // Begin of 2nd input range
		destSeq.begin(), // Begin of destination range
		[](float x, float y) { return x * y; } // Lambda
	);

	return 0;
}
