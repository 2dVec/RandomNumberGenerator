#include <iostream>
#include <random>
#include <vector>
#include <chrono>
#include <sstream>

static std::string random_number(unsigned int size)
{
	if (size > 9 || size < 1)
	{
		return "Put a valid number between 1-9";
	}

	std::vector<char> shuff_rand{ '1','2','3','4','5','6','7','8','9' };

	// Declare seed using chrono clock
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();

	// Shuffles through vector beginning to end using std::default_random_engine and 'seed' as seed
	// to create a fully randomized number everytime
	std::shuffle(shuff_rand.begin(), shuff_rand.end(), std::default_random_engine(seed));

	std::string rand_num;

	for (int i = 0; i < size; i++)
	{
		rand_num.push_back(shuff_rand[i]);
	}

	int x = 0;

	// Convert string to integer
	std::stringstream convert(rand_num);
	convert << x;

	return rand_num;
}

int main()
{
	std::cout << random_number(0);

	return 0;
}

static std::string random_number(unsigned int size);