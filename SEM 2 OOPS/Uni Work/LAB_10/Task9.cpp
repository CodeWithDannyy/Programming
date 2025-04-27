#include<iostream>
#include<fstream>
using namespace std;

class FileHandler
{
    private:
        string fileName;
        ifstream inputFile;
    
    public:
        FileHandler(string fileName) : fileName(fileName)
        {
            inputFile.open(fileName);
            if (!inputFile)
            {
                cout << "Error opening file!" << endl;
                exit(1);
            }
        }

        void readAndShowPos()
        {
            char buffer[11];
            buffer[10] = '\0';

            inputFile.read(buffer,10);
            cout << "First 10 Characters : " << buffer << endl;
            streampos pos1 = inputFile.tellg();
            cout << "Current Position : " << pos1 << endl;

            inputFile.read(buffer, 10);
            cout << "Next 10 Characters : " << buffer << endl;
            streampos pos2 = inputFile.tellg();
            cout << "Current Position : " << pos2 << endl;
        }
        
        void closeFile()
        {
            inputFile.close();
        }
};

int main()
{
    FileHandler file("large_log.txt");
    file.readAndShowPos();
    file.closeFile();
    return 0;
}
