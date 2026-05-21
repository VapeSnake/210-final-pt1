// COMSC_210 | Final Pt 1 | Noel Mier-Luna
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    // Milestone 1 Complete. Map created and file read successful. Map tracks all origin/destination airports and counts # of flights.
    map<string, int> flights;

    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile) {
        cerr << "Unable to open file data.txt";
        return 1; // Exit with error code
    }
    string flight;
    int count;

    while (inFile >> flight) {
        if (flights.find(flight) != flights.end()) {
            flights[flight]++;
            count = flights[flight];
        } else {
            flights[flight] = 1;
        }
        
    }
    inFile.close();

    for (const auto& pair : flights) {
        cout << pair.first << ": " << pair.second << endl;
    }

}