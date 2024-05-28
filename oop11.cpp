#include <iostream>
#include <map>
#include <string>

int main() {
    // Define a map to store state populations
    std::map<std::string, long long> statePopulations;

    // Populate the map with state names and populations
    statePopulations["California"] = 39538223;  // Example population for California
    statePopulations["Texas"] = 29145505;       // Example population for Texas
    // Add more states and populations as needed

    // Prompt the user to enter a state name
    std::cout << "Enter the name of a state: ";
    std::string stateName;
    std::cin >> stateName;

    // Check if the entered state name exists in the map
    auto it = statePopulations.find(stateName);
    if (it != statePopulations.end()) {
        // State found, display its population
        std::cout << "Population of " << stateName << " is: " << it->second << std::endl;
    } else {
        // State not found
        std::cout << "Population data for " << stateName << " not found." << std::endl;
    }

    return 0;
}


