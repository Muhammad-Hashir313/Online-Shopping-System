#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    string publisher;
    int year;
    int quantity;

public:
    Book(string t, string a, string p, int y, int q) : title(t), author(a), publisher(p), year(y), quantity(q) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getPublisher() const { return publisher; }
    int getYear() const { return year; }
    int getQuantity() const { return quantity; }

    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year: " << year << endl;
        cout << "Quantity: " << quantity << endl;
    }

    void reduceQuantity() {
        if (quantity > 0)
            quantity--;
    }
};

class ShoppingCart {
private:
    vector<Book*> books;

public:
    bool addBook(Book* book) {
        if (book->getQuantity() > 0) {
            books.push_back(book);
            book->reduceQuantity();
            cout << "Book added to cart: " << book->getTitle() << endl;
            return true;
        }
        else {
            cout << "Sorry, " << book->getTitle() << " is out of stock." << endl;
            return false;
        }
    }

    void displayCart() {
        cout << "Books in cart:" << endl;
        for (Book* book : books) {
            cout << "-------------------------" << endl;
            book->display();
        }
        cout << "-------------------------" << endl;
    }

    void checkout() {
        cout << "Checking out..." << endl;
        books.clear();
    }
};

int main() {
    vector<Book> inventory = {
        Book("The Adventures of Tom Sawyer", "Mark Twain", "Harper & Brothers", 1876, 5),
        Book("Pride and Prejudice", "Jane Austen", "T. Egerton, Whitehall", 1813, 3),
        Book("1984", "George Orwell", "Secker & Warburg", 1949, 7),
        Book("To Kill a Mockingbird", "Harper Lee", "J. B. Lippincott & Co.", 1960, 2)
    };

    ShoppingCart cart;
    int choice;

    cout << "Welcome to our bookstore!" << endl;

    do {
        cout << "-------------------------" << endl;
        cout << "Available Books:" << endl;
        for (int i = 0; i < inventory.size(); ++i) {
            cout << i + 1 << ". ";
            inventory[i].display();
            cout << "-------------------------" << endl;
        }
        cout << "1. Add book to cart" << endl;
        cout << "2. View cart" << endl;
        cout << "3. Checkout" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int bookIndex;
            cout << "Enter the index of the book you want to add to cart: ";
            cin >> bookIndex;
            if (bookIndex >= 1 && bookIndex <= inventory.size()) {
                cart.addBook(&inventory[bookIndex - 1]);
            }
            else {
                cout << "Invalid book index!" << endl;
            }
            break;
        }
        case 2:
            cart.displayCart();
            break;
        case 3:
            cart.checkout();
            cout << "Thank you for shopping with us!" << endl;
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}
