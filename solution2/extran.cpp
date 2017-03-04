#include <iostream>
#include <algorithm>
#include <vector>

int number_elements;
std::vector<int> sequence;
void readSequence()
{
	std::cin >> number_elements;
	sequence.resize(number_elements);
	for (int i = 0; i < number_elements; ++ i)
	{
		std::cin >> sequence[i];
	}
}

int findExcludable()
{
	std::sort(sequence.begin(), sequence.end());
	for (unsigned i = 0; i + 1 < sequence.size(); ++ i)
	{
		if (sequence[i] + 1 != sequence[i + 1])
		{
			return i == 0?
					sequence[0] :
					sequence[i + 1];
		}
	}
	return -1;
}

int main()
{
	int number_scenarios;
	std::cin >> number_scenarios;
	while (number_scenarios --)
	{
		readSequence();
		std::cout << findExcludable() << "\n";
	}
}
