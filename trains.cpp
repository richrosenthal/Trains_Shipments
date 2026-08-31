#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Function to read CSV file and return a 2D vector of strings
vector<vector<string>> readCSV(const string& filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        vector<string> row;
        stringstream ss(line);
        string cell;

        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    return data;
}

int main(){

    // Import rail network, shipments, and shipment priority data from CSV files

    vector<vector<string>> railNetwork = readCSV("rail_network.csv");

    vector<vector<string>> shipments = readCSV("shipments.csv");

    vector<vector<string>> shipmentPriority = readCSV("shipment_priority.csv");

    // Test rail network
    cout << "Rail Network:" << endl;

    for (int row = 0; row < railNetwork.size(); ++row) {
        for (int col = 0; col < railNetwork[row].size(); ++col) {
            cout << railNetwork[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}