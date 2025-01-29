#include<iostream>
using namespace std;

typedef struct 
{
    int bookID;
    string title;
    string author;
    int isAvailable;    
}Book;

int main()
{
    Book *books = nullptr;
    int numOfBooks = 0;
    int choice;
    int exit = 1;
    do
    {
        cout << "\n1. Add Book"<<endl;
        cout << "2. Remove Book"<<endl;
        cout << "3. Search for book"<<endl;
        cout << "4. Display All Available books"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice : ";
        cin >> choice;
        bool found = false;
        switch (choice)
        {
            case 1: {
                Book *temp = new Book[numOfBooks+1];
                for (int i = 0; i < numOfBooks; i++)
                {
                    temp[i] = books[i];
                }
                delete[] books;
                books = temp;

                cout << "\nEnter Information for Book "<< numOfBooks+1 <<endl ;
            
                cout << "Enter Book ID : ";
                cin >> books[numOfBooks].bookID;

                cin.ignore();

                cout << "Enter Title : ";
                getline(cin, books[numOfBooks].title);

                cout << "Enter Author : ";
                getline(cin, books[numOfBooks].author);

                cout << "Enter Book Availablity (1 for yes, 0 for No) : ";
                cin >> books[numOfBooks].isAvailable;
                cin.ignore();

                numOfBooks++;
                break;
            }        
            case 2:
                if(numOfBooks == 0)
                {
                    cout << "There are no books to remove";
                    break;
                }
                int removeID;
                cout << "\nEnter Book ID to remove that book : ";
                cin >> removeID;
                for(int i = 0 ; i < numOfBooks;i ++)
                {
                    if(books[i].bookID == removeID)
                    {
                        found = true;
                        for(int j = 0; j < numOfBooks-1;j++)
                        {
                            books[j] = books[j+1];
                        }
                        numOfBooks--;

                        Book *temp = new Book[numOfBooks];
                        for(int i = 0; i < numOfBooks; i++)
                            temp[i] = books[i];
                        delete[] books;
                        books = temp;
                        cout << "Book Removed "<<endl;
                        break;
                    }
                }
                if(!found)
                {
                    cout << "Book Not Found" <<endl;
                }
                break;
            
            case 3:
                if(numOfBooks == 0)
                {
                    cout << "There are no books in the list" << endl;
                    break;
                }

                int searchID;
                cout << "\nEnter Book ID to search that book: ";
                cin >> searchID;

                for (int i = 0; i < numOfBooks; i++)
                {
                    if (books[i].bookID == searchID)
                    {
                        found = true;
                        cout << "Book found : " << endl;
                        cout << "ID : " << books[i].bookID << endl;
                        cout << "Title : " << books[i].title << endl;
                        cout << "Author : " << books[i].author << endl;
                        cout << "Availability : " << (books[i].isAvailable ? "Available" : "Not Available") << endl;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "Book Not Found"<<endl;
                }
                break;
        
            case 4:
                if(numOfBooks == 0)
                {
                    cout << "There are no books in the list" << endl;
                    break;
                }
                
                cout << "All Available Books " << endl;
                for (int i = 0; i < numOfBooks; i++)
                {
                    if (books[i].isAvailable == 1)
                    {
                        cout << "ID: " << books[i].bookID << endl;
                        cout << "Title: " << books[i].title << endl;
                        cout << "Author: " << books[i].author << endl;
                        cout << "Availability: Available" << endl;
                    }
                }
                break;
        
            case 5:
                exit = 0;
                break;
            
            default:
                cout << "Wrong Choice "<<endl;
                break;
        }
    }while(exit);

    delete[] books;

    return 0;

}