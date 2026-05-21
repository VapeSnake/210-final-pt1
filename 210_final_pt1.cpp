// COMSC_210 | Final Pt 1 | Noel Mier-Luna
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void trafficRange(const map<string, int> &airTraffic, int low, int high);

int main()
{
    // Milestone 1 Complete. Map created and file read successful. Map tracks all origin/destination airports and counts # of flights.
    map<string, int> flights;

    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile)
    {
        cerr << "Unable to open file data.txt";
        return 1; // Exit with error code
    }
    string flight;
    int count;

    while (inFile >> flight)
    {
        if (flights.find(flight) != flights.end())
        {
            flights[flight]++;
            count = flights[flight];
        }
        else
        {
            flights[flight] = 1;
        }
    }
    inFile.close();

    for (const auto &pair : flights)
    {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Milestone 2 Complete. Tracks airports with highest # of flights, handles ties, and displays them all.
    int highestFlights = 0;
    for (const auto &pair : flights)
    {
        if (pair.second > highestFlights)
        {
            highestFlights = pair.second;
        }
    }
    cout << "Highest number of flights: " << highestFlights << endl;
    cout << "Busiest airport(s) with " << highestFlights << " flights:" << endl;
    for (const auto &pair : flights)
    {
        if (pair.second == highestFlights)
        {
            cout << pair.first << endl;
        }
    }
    // Milestone 3 Complete. Displays airports with flight counts within given range.
    trafficRange(flights, 0, 6);
    cout << "\n\n";
    trafficRange(flights, 18, 35);
}
void trafficRange(const map<string, int> &airTraffic, int low, int high)
{
    cout << "Airports with traffic in range [" << low << ", " << high << "]:" << endl;
    for (const auto &pair : airTraffic)
    {
        if (pair.second >= low && pair.second <= high)
        {
            cout << pair.first << " " << pair.second << endl;
        }
    }
}