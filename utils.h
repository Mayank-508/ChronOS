#ifndef UTILS_H
#define UTILS_H
#include <vector>
#include "process.h"

void printGanttChart(const std::vector<std::pair<int, int>>& timeline);
void showStats(std::vector<Process>& processes, const std::vector<std::pair<int, int>>& timeline);

#endif