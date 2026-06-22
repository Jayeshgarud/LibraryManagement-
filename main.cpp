#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int bookId;
    string title;
    string author;
    bool isIssued;

    Book(int id, string t, string a) {
        bookId = id;
        title = t;
        author = a;
        isIssued = false;
    }
};

class Member {
public:
    int memberId;
    string memberName;

    Member(int id, string name) {
        memberId = id;
        memberName = name;
    }
};

vector<Book> books;
vector<Member> members;

void addBook() {
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books.push_back(Book(id, title, author));

    cout << "Book Added Successfully!\n";
}

void viewBooks() {
    if (books.empty()) {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << "\n----- BOOK LIST -----\n";

    for (auto &book : books) {
        cout << "Book ID: " << book.bookId << endl;
        cout << "Title: " << book.title << endl;
        cout << "Author: " << book.author << endl;
        cout << "Status: "
             << (book.isIssued ? "Issued" : "Available")
             << endl;
        cout << "---------------------\n";
    }
}

void addMember() {
    int id;
    string name;

    cout << "\nEnter Member ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Member Name: ";
    getline(cin, name);

    members.push_back(Member(id, name));

    cout << "Member Added Successfully!\n";
}

void viewMembers() {
    if (members.empty()) {
        cout << "\nNo Members Found.\n";
        return;
    }

    cout << "\n----- MEMBER LIST -----\n";

    for (auto &member : members) {
        cout << "Member ID: " << member.memberId << endl;
        cout << "Name: " << member.memberName << endl;
        cout << "-----------------------\n";
    }
}

void issueBook() {
    int id;

    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (auto &book : books) {
        if (book.bookId == id) {

            if (book.isIssued) {
                cout << "Book Already Issued!\n";
                return;
            }

            book.isIssued = true;
            cout << "Book Issued Successfully!\n";
            return;
        }
    }

    cout << "Book Not Found!\n";
}

void returnBook() {
    int id;

    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (auto &book : books) {
        if (book.bookId == id) {

            if (!book.isIssued) {
                cout << "Book Already Available!\n";
                return;
            }

            book.isIssued = false;
            cout << "Book Returned Successfully!\n";
            return;
        }
    }

    cout << "Book Not Found!\n";
}

void searchByTitle() {
    string title;

    cin.ignore();

    cout << "\nEnter Title: ";
    getline(cin, title);

    bool found = false;

    for (auto &book : books) {
        if (book.title == title) {
            cout << "\nBook Found\n";
            cout << "Book ID: " << book.bookId << endl;
            cout << "Author: " << book.author << endl;
            cout << "Status: "
                 << (book.isIssued ? "Issued" : "Available")
                 << endl;

            found = true;
        }
    }

    if (!found)
        cout << "Book Not Found!\n";
}

void searchByAuthor() {
    string author;

    cin.ignore();

    cout << "\nEnter Author Name: ";
    getline(cin, author);

    bool found = false;

    for (auto &book : books) {
        if (book.author == author) {
            cout << "\nBook ID: " << book.bookId << endl;
            cout << "Title: " << book.title << endl;
            cout << "Status: "
                 << (book.isIssued ? "Issued" : "Available")
                 << endl;

            found = true;
        }
    }

    if (!found)
        cout << "No Books Found!\n";
}

int main() {

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Add Member\n";
        cout << "4. View Members\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Search By Title\n";
        cout << "8. Search By Author\n";
        cout << "9. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                addMember();
                break;

            case 4:
                viewMembers();
                break;

            case 5:
                issueBook();
                break;

            case 6:
                returnBook();
                break;

            case 7:
                searchByTitle();
                break;

            case 8:
                searchByAuthor();
                break;

            case 9:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 9);

    return 0;
}
