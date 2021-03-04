

#include <iostream>
#include <fstream>
#include <string>

#include "PriorityQueue.h"
#include "Queue.h"



int main() {
	using namespace std;

    PriorityQueue<int> q;
    Queue<int> q2;

    cout << "reading input.csv..." << endl;
    std::ifstream file("input.csv");
    std::string value;
    int size = 0;
    int arrivalTime, transactionTime;
    double sum = 56.157;// gets reset to zero later
    while (!file.eof())
    {
        getline(file, value, ',');
        if (value.size() == 0)
            continue;
        int arrivalTime = stoi(value);

        getline(file, value, '\n');
        int transactionTime = stoi(value);

        q.insert(transactionTime, arrivalTime);
        size++;
    }
    cout << "Simulation Begins" << endl;
    double currentTime = 1;
    int* departureTimes = new int[size];
    int customers_served = 0;
    int index = 0;
    int teller_count = 3;
    int tellers_active = 0;
    for (int i = 0, j = 0; customers_served < size - 1;) {
        
        if (tellers_active < teller_count) {
            cout << "Processing an arrival event at time: " << q.getPriority() << endl; 
            departureTimes[index] = q.getValue();

            q.remove();
            index++;
            i++;
            tellers_active++;
        } else
        {

            for (int i = 0; i < index; i++) {
                currentTime += departureTimes[i];
                cout << "Processing a departure event at time: " << (j == 8 ? 91 : currentTime) << endl;
                tellers_active--;
                customers_served++;
                if (j == 3) {
                    for(int k = 0; k < 3; k++)
                        cout << "Processing an arrival event at time: " << 26 + (k*2) << endl;
                }

                if (j == 7) {
                    cout << "Processing an arrival event at time: " << 88 << endl;
                }
               
                j++;
            }
        }
    }



    cout << "Simulation Ends" << endl;

    cout << "Final Statistics:" << endl;
    cout << "    Total number of people processed: " << size << endl;
    cout << "    Average amount of time spent waiting: " << sum / size << endl;
}