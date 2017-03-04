#ifndef XENTASK
#define XENTASK
#include <vector>

extern int numberOfTasks;
extern std::vector<int> taskDurations[2];
void readData();
int alternateStartingFrom(int girl);

#endif
