#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Person record structure
struct PersonRecord {
    string name;
    string dob;
    string telephoneNumber;

    // Constructor
    PersonRecord(const string& _name, const string& _dob, const string& _telephoneNumber)
        : name(_name), dob(_dob), telephoneNumber(_telephoneNumber) {}
};

// Item record structure
struct ItemRecord {
    int itemCode;
    string name;
    float cost;
    int quantity;

    // Constructor
    ItemRecord(int _itemCode, const string& _name, float _cost, int _quantity)
        : itemCode(_itemCode), name(_name), cost(_cost), quantity(_quantity) {}
};

// Comparator function for sorting person records by name
bool comparePersonByName(const PersonRecord& p1, const PersonRecord& p2) {
    return p1.name < p2.name;
}

// Comparator function for sorting item records by item code
bool compareItemByItemCode(const ItemRecord& i1, const ItemRecord& i2) {
    return i1.itemCode < i2.itemCode;
}

int main() {
    // Vector of person records
    vector<PersonRecord> personRecords = {
        {"John Doe", "1990-01-01", "1234567890"},
        {"Jane Smith", "1985-05-15", "9876543210"},
        {"Alice Johnson", "1978-11-30", "4567890123"}
    };

    // Sorting person records by name
    sort(personRecords.begin(), personRecords.end(), comparePersonByName);

    // Displaying sorted person records
    cout << "Sorted Person Records by Name:" << endl;
    for (const auto& person : personRecords) {
        cout << "Name: " << person.name << ", DOB: " << person.dob
             << ", Telephone Number: " << person.telephoneNumber << endl;
    }
    cout << endl;

    // Vector of item records
    vector<ItemRecord> itemRecords = {
        {101, "Laptop", 1500.0, 10},
        {102, "Smartphone", 800.0, 20},
        {103, "Tablet", 500.0, 15}
    };

    // Sorting item records by item code
    sort(itemRecords.begin(), itemRecords.end(), compareItemByItemCode);

    // Displaying sorted item records
    cout << "Sorted Item Records by Item Code:" << endl;
    for (const auto& item : itemRecords) {
        cout << "Item Code: " << item.itemCode << ", Name: " << item.name
             << ", Cost: " << item.cost << ", Quantity: " << item.quantity << endl;
    }

    return 0;
}

