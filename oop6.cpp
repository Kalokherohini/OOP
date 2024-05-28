#include <iostream>
#include <string>
using namespace std;

// Personal Record class
class PersonalRecord {
protected:
    string name;
    int age;
    string address;

public:
    PersonalRecord() : name(""), age(0), address("") {}

    void setPersonalInfo(const string& _name, int _age, const string& _address) {
        name = _name;
        age = _age;
        address = _address;
    }

    void printPersonalInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

// Professional Record class
class ProfessionalRecord {
protected:
    string company;
    string designation;
    int experience;

public:
    ProfessionalRecord() : company(""), designation(""), experience(0) {}

    void setProfessionalInfo(const string& _company, const string& _designation, int _experience) {
        company = _company;
        designation = _designation;
        experience = _experience;
    }

    void printProfessionalInfo() const {
        cout << "Company: " << company << endl;
        cout << "Designation: " << designation << endl;
        cout << "Experience: " << experience << " years" << endl;
    }
};

// Academic Record class
class AcademicRecord {
protected:
    string degree;
    string university;
    int yearOfPassing;

public:
    AcademicRecord() : degree(""), university(""), yearOfPassing(0) {}

    void setAcademicInfo(const string& _degree, const string& _university, int _yearOfPassing) {
        degree = _degree;
        university = _university;
        yearOfPassing = _yearOfPassing;
    }

    void printAcademicInfo() const {
        cout << "Degree: " << degree << endl;
        cout << "University: " << university << endl;
        cout << "Year of Passing: " << yearOfPassing << endl;
    }
};

// Employee Bio-data class using multiple inheritance
class EmployeeBioData : public PersonalRecord, public ProfessionalRecord, public AcademicRecord {
public:
    void setBioData(const string& _name, int _age, const string& _address,
                    const string& _company, const string& _designation, int _experience,
                    const string& _degree, const string& _university, int _yearOfPassing) {
        setPersonalInfo(_name, _age, _address);
        setProfessionalInfo(_company, _designation, _experience);
        setAcademicInfo(_degree, _university, _yearOfPassing);
    }

    void printBioData() const {
        cout << "----- Employee Bio-data -----" << endl;
        printPersonalInfo();
        cout << endl;
        printProfessionalInfo();
        cout << endl;
        printAcademicInfo();
        cout << "----------------------------" << endl;
    }
};

int main() {
    // Creating an EmployeeBioData object
    EmployeeBioData employee;

    // Setting employee bio-data
    employee.setBioData("John Doe", 30, "123 Main St, City", "ABC Inc.", "Software Engineer", 5,
                        "Bachelor of Engineering", "XYZ University", 2015);

    // Printing employee bio-data
    employee.printBioData();

    return 0;
}

