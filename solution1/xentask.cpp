#include <vector>
#include <iostream>
#include <algorithm>

int numberOfTasks = 0;
std::vector<int> taskDurations[2];
void readDurations()
{
	for (int girl = 0; girl < 2; ++ girl)
	{
		taskDurations[girl].resize(numberOfTasks);
		for (int i = 0; i < numberOfTasks; ++ i)
		{
			std::cin >> taskDurations[girl][i];
		}
	}
}

void readData()
{
	std::cin >> numberOfTasks;
	readDurations();
}

int alternateStartingFrom(int girl)
{
	int duration = 0, currentGirl = girl;
	for (int task = 0; task < numberOfTasks; ++ task)
	{
		duration += taskDurations[currentGirl][task];
		currentGirl ^= 1;
	}
	return duration;
}

int minimalDuration()
{
	return std::min(alternateStartingFrom(0),
				alternateStartingFrom(1));
}

int main()
{
	int numberOfTest;
	std::cin >> numberOfTest;
	while (numberOfTest --)
	{
		readData();
		std::cout << minimalDuration() << "\n";
	}
}
