#include<iostream>
#include<fstream>
using namespace std;

class FileException
{
    public:
        virtual const char* what() const
        {
            return "FileExceptionError - ";
        }
        virtual ~FileException() {}
};

class FileNotFoundException : public FileException
{
    public:
        const char* what() const override
        {
            return "FileNotFoundException - Cannot Find the file";
        }
};

class PermissionDeniedException : public FileException
{
    public:
        const char* what() const override
        {
            return "PermissionDeniedException - Access Denied";
        }
};

void readFile(const string& fileName)
{
    if(fileName == "secret.txt")
    {
        throw PermissionDeniedException();
    }

    ifstream inFile(fileName);
    if(!inFile)
    {   
        throw FileNotFoundException();
    }

    cout << "Reading File successfully: " << fileName << endl;
    inFile.close();
};

int main()
{
    string filename;
    cout << "Enter filename to read: ";
    cin >> filename;

    try
    {
        readFile(filename);
    }
    catch(const PermissionDeniedException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const FileNotFoundException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const FileException& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}