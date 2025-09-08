#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// Define the Book struct with the required fields
struct Book {
    string title;
    string author;
    int year;
    int pages;
    string isbn;
};

void print_book(int index, const char* title, const char* author, int year, int pages, const char* isbn) {
    cout << "Book[" << index << "]: "
         << "title=" << title << ", "
         << "author=" << author << ", "
         << "year=" << year << ", "
         << "pages=" << pages << ", "
         << "isbn=" << isbn << "\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    int num_books;
    input >> num_books;
    input.ignore(); // skip newline after reading number of books

    // Create an array of Book to store the books
    Book books[num_books];

    // Read books data from the input file
    for (int i = 0; i < num_books; ++i) {
        // Read the book data from the file and populate the books array
        getline(input, books[i].title);
        getline(input, books[i].author);
        input >> books[i].year;
        input >> books[i].pages;
        input.ignore(); // skip the newline after reading pages
        getline(input, books[i].isbn);
    }

    // Print the books using the print_book function
    for (int i = 0; i < num_books; ++i) {
        print_book(i, books[i].title.c_str(), books[i].author.c_str(), books[i].year, books[i].pages, books[i].isbn.c_str());
    }

    return 0;
}
