#include <iostream>
using namespace std;

class Book {
    public:
        string title;
        string author;
        int pages;

        Book(){ // 2nd constructor
            title = "No title";
            author = "No author";
            pages = 0;
        }

        Book(string aTitle, string aAuthor, int aPages){ //constructor
            title = aTitle;
            author = aAuthor;
            pages= aPages;
        }
};

int main()
{
    Book book1("Harry Potter", "JKL Rowling", 500);
    Book book2("Lord of the Rings", "Tolkein", 700);
    Book book3;


    cout << book3.title << endl;
   
    return 0;
}