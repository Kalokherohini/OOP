#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}
    Publication(const string& _title, float _price) : title(_title), price(_price) {}

    virtual void getData() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void displayData() const {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}
    Book(const string& _title, float _price, int _pageCount) : Publication(_title, _price), pageCount(_pageCount) {}

    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void displayData() const override {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}
    Tape(const string& _title, float _price, float _playingTime) : Publication(_title, _price), playingTime(_playingTime) {}

    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void displayData() const override {
        Publication::displayData();
        cout << "Playing Time (minutes): " << playingTime << endl;
    }
};

int main() {
    try {
        Book book;
        Tape tape;

        cout << "Enter details for the book:" << endl;
        book.getData();

        cout << "\nEnter details for the tape:" << endl;
        tape.getData();

        cout << "\nDetails of the book:" << endl;
        book.displayData();

        cout << "\nDetails of the tape:" << endl;
        tape.displayData();
    } catch (...) {
        // If an exception occurs, replace all data member values with zero values
        Book book;
        Tape tape;

        cout << "An exception occurred. All data member values have been replaced with zero values." << endl;

        cout << "\nDetails of the book:" << endl;
        book.displayData();

        cout << "\nDetails of the tape:" << endl;
        tape.displayData();
    }

    return 0;
}

