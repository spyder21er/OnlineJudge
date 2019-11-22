#include <bits/stdc++.h>
using namespace std;

typedef string Title;
typedef string Author;
typedef pair<Author, Title> Book;

bool operator < (const Book &a, const Book &b)
{
    return lexicographical_compare(a.first.begin(), a.first.end(), b.first.begin(), b.first.end()) ||
            lexicographical_compare(a.second.begin(), a.second.end(), b.second.begin(), b.second.end());
}

Book create_book(string input)
{
    string delim = "\" by ";
    Author a = input.substr(input.find(delim) + delim.length(), input.length());
    Title t = input.substr(1, input.find(delim) - 1);
    return make_pair(a, t);
}

int main()
{
    set<Book> shelf, desk;
    map<Title, Book> library;
    string input, command;
    getline(cin, input);
    while (input != "END")
    {
        Book book = create_book(input);
        shelf.insert(book);
        library[book.second] = book;
        getline(cin, input);
    }

    while (true)
    {
        getline(cin, input);
        if (input == "END") break;
        command = input.substr(0, input.find("\"") - 1);
        if (command != "SHELVE")
        {
            Title title = input.substr(input.find("\"") + 1, input.length());
            title = title.substr(0, title.find("\""));

            if (command == "BORROW")
            {
                shelf.erase(library[title]);
            }
            if (command == "RETURN")
            {
                desk.insert(library[title]);
            }
        } 
        else 
        {
            for (set<Book>::iterator it = desk.begin(); it != desk.end(); ++it)
            {
                pair<set<Book>::iterator, bool> ret = shelf.insert(library[it->second]);
                set<Book>::iterator jt = ret.first;
                cout << "Put \"" << jt->second;
                if (jt == shelf.begin())
                    cout << "\" first" << endl;
                else
                {
                    jt--;
                    cout << "\" after \"" << jt->second << "\"" << endl;
                }
            }
            desk.clear();

            cout << "END" << endl;
        }
    }

    return 0;
}