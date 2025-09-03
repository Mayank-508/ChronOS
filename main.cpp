#include <iostream>
#include <vector>
#include "process.h"

void fcfs(std::vector<Process>);
void sjf(std::vector<Process>);
void sjfPreemptive(std::vector<Process>);
void priority(std::vector<Process>);
void priorityPreemptive(std::vector<Process>);
void roundRobin(std::vector<Process>, int);

int main() {
    int n, choice, quantum;
    std::vector<Process> processes;

    std::cout << "Enter number of processes: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        std::cout << "Enter Arrival Time, Burst Time and Priority for Process " << i + 1 << ": ";
        std::cin >> p.arrival_time >> p.burst_time >> p.priority;
        p.pid = i + 1;
        p.remaining_time = p.burst_time;
        processes.push_back(p);
    }

    do {
        std::cout << "\nChoose Scheduling Algorithm:\n";
        std::cout << "1. FCFS\n2. SJF (Non-preemptive)\n3. SJF (Preemptive)\n";
        std::cout << "4. Priority (Non-preemptive)\n5. Priority (Preemptive)\n";
        std::cout << "6. Round Robin\n7. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: fcfs(processes); break;
            case 2: sjf(processes); break;
            case 3: sjfPreemptive(processes); break;
            case 4: priority(processes); break;
            case 5: priorityPreemptive(processes); break;
            case 6:
                std::cout << "Enter Time Quantum: ";
                std::cin >> quantum;
                roundRobin(processes, quantum);
                break;
        }
    } while (choice != 7);

    return 0;
}
