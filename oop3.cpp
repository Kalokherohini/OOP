#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char* name;
    int rollNumber;
    char* className;
    char division;
    char* dateOfBirth;
    char* bloodGroup;
    char* contactAddress;
    char* telephoneNumber;
    char* drivingLicenseNumber;

public:
    // Constructors
    Student() {
        name = NULL;
        rollNumber = 0;
        className = NULL;
        division = '\0';
        dateOfBirth = NULL;
        bloodGroup = NULL;
        contactAddress = NULL;
        telephoneNumber = NULL;
        drivingLicenseNumber = NULL;
    }

    Student(const char* _name, int _rollNumber, const char* _className, char _division,
            const char* _dateOfBirth, const char* _bloodGroup, const char* _contactAddress,
            const char* _telephoneNumber, const char* _drivingLicenseNumber) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        rollNumber = _rollNumber;
        className = new char[strlen(_className) + 1];
        strcpy(className, _className);
        division = _division;
        dateOfBirth = new char[strlen(_dateOfBirth) + 1];
        strcpy(dateOfBirth, _dateOfBirth);
        bloodGroup = new char[strlen(_bloodGroup) + 1];
        strcpy(bloodGroup, _bloodGroup);
        contactAddress = new char[strlen(_contactAddress) + 1];
        strcpy(contactAddress, _contactAddress);
        telephoneNumber = new char[strlen(_telephoneNumber) + 1];
        strcpy(telephoneNumber, _telephoneNumber);
        drivingLicenseNumber = new char[strlen(_drivingLicenseNumber) + 1];
        strcpy(drivingLicenseNumber, _drivingLicenseNumber);
    }

    // Copy constructor
    Student(const Student& obj) {
        name = new char[strlen(obj.name) + 1];
        strcpy(name, obj.name);
        rollNumber = obj.rollNumber;
        className = new char[strlen(obj.className) + 1];
        strcpy(className, obj.className);
        division = obj.division;
        dateOfBirth = new char[strlen(obj.dateOfBirth) + 1];
        strcpy(dateOfBirth, obj.dateOfBirth);
        bloodGroup = new char[strlen(obj.bloodGroup) + 1];
        strcpy(bloodGroup, obj.bloodGroup);
        contactAddress = new char[strlen(obj.contactAddress) + 1];
        strcpy(contactAddress, obj.contactAddress);
        telephoneNumber = new char[strlen(obj.telephoneNumber) + 1];
        strcpy(telephoneNumber, obj.telephoneNumber);
        drivingLicenseNumber = new char[strlen(obj.drivingLicenseNumber) + 1];
        strcpy(drivingLicenseNumber, obj.drivingLicenseNumber);
    }

    // Destructor
    ~Student() {
        delete[] name;
        delete[] className;
        delete[] dateOfBirth;
        delete[] bloodGroup;
        delete[] contactAddress;
        delete[] telephoneNumber;
        delete[] drivingLicenseNumber;
    }

    // Static member function
    static void displayHeader() {
        cout << "Name\tRoll Number\tClass\tDivision\tDate of Birth\tBlood Group\tContact Address\tTelephone Number\tDriving License Number\n";
    }

    // Member function to display student information
    void display() {
        cout << name << "\t" << rollNumber << "\t" << className << "\t" << division << "\t"
             << dateOfBirth << "\t" << bloodGroup << "\t" << contactAddress << "\t" << telephoneNumber
             << "\t" << drivingLicenseNumber << endl;
    }

    // Friend class
    friend class Database;
};

class Database {
private:
    Student* students;
    int numStudents;

public:
    Database(int size) {
        numStudents = size;
        students = new Student[size];
    }

    // Destructor
    ~Database() {
        delete[] students;
    }

    // Member function to add student to the database
    void addStudent(const Student& s, int index) {
        if (index >= 0 && index < numStudents) {
            students[index] = s;
        }
    }

    // Member function to display all students in the database
    void displayStudents() {
        Student::displayHeader();
        for (int i = 0; i < numStudents; ++i) {
            students[i].display();
        }
    }
};

int main() {
    Database db(2);

    // Adding students to the database
    Student s1("John Doe", 101, "12th", 'A', "01/01/2000", "O+", "123 Main St", "1234567890", "DL123456");
    Student s2("Jane Smith", 102, "12th", 'B', "02/02/2001", "AB-", "456 Elm St", "0987654321", "DL654321");

    db.addStudent(s1, 0);
    db.addStudent(s2, 1);

    // Displaying all students in the database
    db.displayStudents();

    return 0;
}

