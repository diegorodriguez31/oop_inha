#include <iostream>
using namespace std;

const int MAX_BOOK = 100;

class Book {
private:
    string title;
    string ISBN;
    double price;
public:
    Book() {
        title = "Book";
        ISBN = "unknown";
        price = 0.0;
    }
    Book(string title, string ISBN, double price) {
        this->title = title;
        this->ISBN = ISBN;
        this->price = price;
    }
    ~Book() {
        cout << "Book destructor called." << endl;
    }
    string getTitle(){return title;}
    string getISBN(){return ISBN;}
    double getPrice(){return price;}
    void setTitle(string title){this->title = title;}
    void setISBN(string ISBN){this->ISBN = ISBN;}
    void setPrice(double price){this->price = price;}
    void ShowBookInfo() {
        cout<<"Title: "<<title<<endl;
        cout<<"ISBN: "<<ISBN<<endl;
        cout<<"Price: "<<price<<endl;
    }
};

class EBook : public Book {
private:
    string DRMkey;
    string format;
public:
    EBook(string title, string ISBN, double price, string DRMkey) : Book(title, ISBN, price) {
        this->DRMkey = DRMkey;
        format = "my_ebook_format";
    }

    EBook(string title, string ISBN, double price, string DRMkey, string format) : Book(title, ISBN, price) {
        this->DRMkey = DRMkey;
        this->format = format;        
    }

    void ShowEBookInfo() {
        ShowBookInfo();
        cout<<"DRMkey: "<< DRMkey <<endl;
        cout<<"Format: "<< format <<endl;
    }
};

// New class that contains multiple EBooks and show all information of the stored eBooks
class EBookLibrary {
private:
    EBook* m_books[MAX_BOOK];
    int m_cnt;
public:
    EBookLibrary() {
        m_cnt = 0;
    }
    ~EBookLibrary() {
        for (int i = 0; i < m_cnt; i++) {
            delete m_books[i];
        }
    }
    void AddBook(EBook* book) {
        if (m_cnt < MAX_BOOK) {
            m_books[m_cnt] = book;
        }
        m_cnt++;
    }
    void ShowAllBooks() {
        for (int i = 0; i < m_cnt; i++) {
            m_books[i]->ShowEBookInfo();
            cout << endl;
        }
    }
};

int main() {
    Book book("Modern C++ Programming Cookbook","1800208987",49.99);
    book.ShowBookInfo();
    cout<<endl;
    
    EBook ebook("Modern C++ Programming Cookbook(ebook)","1800208987",34.99,"dkb34x!@*~");
    ebook.ShowEBookInfo();

    cout << endl << endl << "Exercise 4" << endl;
    EBookLibrary elib;
    elib.AddBook(new EBook{"Book1","1234567890",10.99,"AAAAAA","ePub"});
    elib.AddBook(new EBook{"Book2","2345678901",20.99,"BBBBBB"});
    elib.AddBook(new EBook{"Book3","3456789012",30.99,"CCCCCC","ePub"});
    elib.AddBook(new EBook{"Book4","4567890123",40.99,"DDDDDD"});
    elib.ShowAllBooks();
    
    return 0;
}