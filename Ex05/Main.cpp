#include <iostream>
#include <zlib.h>

int main()
{
	std::cout << "Hello, C++ zlib world!\n";

	char inputBuffer[] = {
		'a','b','c','d',
		'a','b','c','d',
		'a','b','c','d',
		'a','b','c','d',
		'a','b','c','d',
	};

	size_t inputSize = sizeof(inputBuffer);
	std::cout << "Before compress size: " << inputSize << '\n';
	for (size_t i = 0; i < inputSize; i++)
	{
		std::cout << (int)inputBuffer[i] << ',';
	}

	std::cout << "\n\n";

	// Ask zlib for the max destination size
	int maxDstSize = compressBound(inputSize);
	char* dstBuffer = new char[maxDstSize];

	uLongf resultDstSize = maxDstSize;
	compress(reinterpret_cast<Bytef*>(dstBuffer), &resultDstSize, reinterpret_cast<Bytef*>(inputBuffer), inputSize);

	std::cout << "After compress size: " << resultDstSize << '\n';

	for (size_t i = 0; i < resultDstSize; i++)
	{
		std::cout << (int)dstBuffer[i] << ',';
	}

	return 0;
}
