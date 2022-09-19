/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 2
 * File         : videostore.cpp
 * Purpose      : Section 2 - Question 2: Polymorphism
 *                This program showcases inheritance and polymorphism
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 ************************************************************************************/

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <limits>

using namespace std;

// Base Class
class VideoGame
{
protected:
    string title;
    float price;

public:
    static int videoGameCount; // static data variable whose value is shared across all objects

    // Constructor of the base class
    VideoGame(string t, float p)
    {
        title = t;
        price = p;
    }

    // Display data from the class. Make this function a virtual function to effect dynamic binding
    virtual void display()
    {
        cout << "\n*********************************" << endl;
        cout << "       Title: " << title << endl;
        cout << "       Price: " << price << endl;
    }
};

// Derived Class
class ComputerGame : public VideoGame
{
private:
    string operatingSystemType;

public:
    ComputerGame(string t, float p, string os) : VideoGame(t, p) // Constructor chaining
    {
        this->operatingSystemType = os;
    }

    // Setters and getters
    void setOs(string os)
    {
        this->operatingSystemType = os;
    }

    string getOs()
    {
        return this->operatingSystemType;
    }

    // display() function - function overriding - polymorphism. This display() function has added the display of the OS type.
    void display()
    {
        VideoGame::display();                                    // call the display function of the base class
        cout << "     OS Type: " << operatingSystemType << endl; // then add the derived class' display method
        cout << "*********************************" << endl;
    }
};

// Derived Class
class ConsoleGame : public VideoGame
{
private:
    string consoleType;

public:
    ConsoleGame(string t, float p, string c) : VideoGame(t, p) // Constructor chaining
    {
        this->consoleType = c;
    }

    // Setters and getters
    void setConsole(string console)
    {
        this->consoleType = console;
    }

    string getConsole()
    {
        return this->consoleType;
    }

    // display() function - function overriding - polymorphism. This display() function has added the display of the console type.
    void display()
    {
        VideoGame::display();                            // call the display function of the base class
        cout << "Console Type: " << consoleType << endl; // then add the derived class' display method
        cout << "*********************************" << endl;
    }
};

int VideoGame::videoGameCount = 0;

// Setter Function
void setComputerGame(VideoGame *gamePtr[5], int count)
{
    string title, osType;
    float price;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
    cout << "Please enter title of computer game: ";
    getline(cin, title);
    cout << "Please enter price: ";
    cin >> price;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
    cout << "Please enter operating system type: ";
    getline(cin, osType);
    gamePtr[count] = new ComputerGame(title, price, osType);
};

// Setter Function
void setConsoleGame(VideoGame *gamePtr[5], int count)
{
    string title, consoleType;
    float price;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
    cout << "Please enter title of console game: ";
    getline(cin, title);
    cout << "Please enter price: ";
    cin >> price;
    cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
    cout << "Please enter console type: ";
    getline(cin, consoleType);
    gamePtr[count] = new ConsoleGame(title, price, consoleType);
};

int main()
{

    VideoGame *ptrVideoGames[5]; // Define the array that will contain all the pointer to objects.

    char choice = ' ', ch = ' ';

    cout << "\n**************************************************************************" << endl;
    cout << "                 Video Games Data Entry" << endl;
    cout << "**************************************************************************" << endl;

    while (choice != 'n' || choice != 'N' && VideoGame::videoGameCount < 5)
    {

        cout << "\nDo you want to enter data for a Computer Game [o] or a Console Game [c]: ";

        cin >> ch;

        if (ch == 'o' || ch == 'O')
        {

            setComputerGame(ptrVideoGames, VideoGame::videoGameCount);
            VideoGame::videoGameCount++;
        }
        else
        {
            if (ch == 'c' || ch == 'C')
            {
                setConsoleGame(ptrVideoGames, VideoGame::videoGameCount);
                VideoGame::videoGameCount++;
            }
            else
            {
                cout << "Please select only 'o' or 'c'" << endl;
                continue; // this causes to loop back to the top - avoiding the execution of code below
            }
        }

        cout << "\nDo you want to add another item (y/n)? ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            break;
        }
    };

    cout << "\n*************************************************************************" << endl;
    cout << "                              Video Games List:" << endl;
    cout << "*************************************************************************" << endl;

    for (int j = 0; j < VideoGame::videoGameCount; j++)
    {
        ptrVideoGames[j]->display(); // polymorphism in action! The function display() here calls the relevant display() function based on the kind of object contained in the current element of the array of pointers
    }

    return 0;
}
