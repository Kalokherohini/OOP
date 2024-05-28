#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string author;
    string title;
    float price;
    string publisher;
    int stockPosition;

public:
    // Constructor
    Book(const string& _author, const string& _title, float _price, const string& _publisher, int _stockPosition) {
        author = _author;
        title = _title;
        price = _price;
        publisher = _publisher;
        stockPosition = _stockPosition;
    }

    // Function to check availability and display book details
    void searchBook(const string& _title, const string& _author) {
        if (_title == title && _author == author) {
            cout << "Book Details:" << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: " << price << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Stock Position: " << stockPosition << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    // Function to sell books
    void sellBook(int numCopies) {
        if (numCopies <= stockPosition) {
            cout << "Total cost: " << (price * numCopies) << endl;
            stockPosition -= numCopies;
        } else {
            cout << "Required copies not in stock." << endl;
        }
    }
};

int main() {
    // Creating book objects
    Book book1("John Doe", "Introduction to Programming", 25.0, "ABC Publications", 10);
    Book book2("Jane Smith", "Data Structures and Algorithms", 30.0, "XYZ Publishers", 5);

    // Example of searching for a book
    cout << "Searching for a book:" << endl;
    book1.searchBook("Introduction to Programming", "John Doe");

    // Example of selling a book
    cout << "\nSelling a book:" << endl;
    book2.searchBook("Data Structures and Algorithms", "Jane Smith");
    book2.sellBook(3); // Sell 3 copies

    // Check stock position after selling
    cout << "\nStock position after selling:" << endl;
    book2.searchBook("Data Structures and Algorithms", "Jane Smith");

    return 0;
}

