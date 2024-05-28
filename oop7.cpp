#include <iostream>
#include <string>
using namespace std;

// User-defined exception for age criterion
class AgeException : public exception {
public:
    const char* what() const throw() {
        return "Age should be between 18 and 55.";
    }
};

// User-defined exception for income criterion
class IncomeException : public exception {
public:
    const char* what() const throw() {
        return "Income should be between Rs. 50,000 and Rs. 1,00,000 per month.";
    }
};

// User-defined exception for city criterion
class CityException : public exception {
public:
    const char* what() const throw() {
        return "User should stay in Pune, Mumbai, Bangalore, or Chennai.";
    }
};

// User-defined exception for vehicle criterion
class VehicleException : public exception {
public:
    const char* what() const throw() {
        return "User should have a 4-wheeler.";
    }
};

int main() {
    int age;
    float income;
    string city;
    bool hasFourWheeler;

    cout << "Enter age: ";
    cin >> age;
    cout << "Enter income (in Rs.): ";
    cin >> income;
    cin.ignore(); // Ignore newline character left in the buffer
    cout << "Enter city: ";
    getline(cin, city);
    cout << "Do you have a 4-wheeler? (1 for Yes, 0 for No): ";
    cin >> hasFourWheeler;

    try {
        // Check age criterion
        if (age < 18 || age > 55) {
            throw AgeException();
        }

        // Check income criterion
        if (income < 50000 || income > 100000) {
            throw IncomeException();
        }

        // Check city criterion
        if (city != "Pune" && city != "Mumbai" && city != "Bangalore" && city != "Chennai") {
            throw CityException();
        }

        // Check vehicle criterion
        if (!hasFourWheeler) {
            throw VehicleException();
        }

        cout << "User meets all criteria." << endl;
    } catch (const exception& ex) {
        cout << "Exception: " << ex.what() << endl;
    }

    return 0;
}

