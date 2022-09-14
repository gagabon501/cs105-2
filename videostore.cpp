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

class VideoGame
{
private:
    string title;
    float price;

public:
    // Setters
    void setTitle(string t)
    // void setTitle(int t)
    {
        title = t;
    }

    void setPrice(float p)
    {
        price = p;
    }

    // Getters
    // int getTitle()
    string getTitle()

    {
        return title;
    }

    float getPrice()
    {
        return price;
    }

    // Display data from the class
    void display()
    {
        cout << "\n*********************************" << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class ComputerGame : public VideoGame
{
private:
    string os;

public:
    // Setters
    void setOs(string o)

    {
        os = o;
    }

    // Getters
    string getOs()
    {
        return os;
    }

    // Display function - function overriding - polymorphism. This display() function has added the display of the OS type.
    void display()
    {
        VideoGame::display();              // call the display function of the base class
        cout << "OS Type: " << os << endl; // then add the derived class' display method
    }
};

class ConsoleGame : public VideoGame
{
private:
    string os;

public:
    // Setters
    void setOs(string o)
    {
        os = o;
    }

    // Getters
    string getOs()
    {
        return os;
    }

    // Display function - function overriding - polymorphism. This display() function has added the display of the console type.
    void display()
    {
        VideoGame::display();                   // call the display function of the base class
        cout << "Console Type: " << os << endl; // then add the derived class' display method
    }
};

int main()
{

    vector<ComputerGame *> ptrCompGames; // use vector arrays for variable number of entries. This is an array of pointers to objects of the class ComputerGame
    vector<ConsoleGame *> ptrConsGames;  // use vector arrays for variable number of entries. This is an array of pointers to objects of the class ConsoleGame

    ComputerGame *ptrgames;
    ConsoleGame *ptrconsoles;

    string titleGame;
    float priceGame;
    string osGame;

    int choice = 1, ch = 1;

    cout << "              Video Games Data Entry" << endl;
    cout << "************************************************" << endl;
    cout << "\n\n";
    while (choice != 0)
    {
        ptrgames = new ComputerGame;   // always create a new object for every iteration
        ptrconsoles = new ConsoleGame; // always create a new object for every iteration

        cout << "Do you want to enter data for a [1] Computer Game or a [2] Console Game: ";
        cin >> ch;

        if (ch == 1)
        {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
            cout << "Please enter the title of computer game: ";
            getline(cin, titleGame);
            ptrgames->setTitle(titleGame); // save immediately before any clearing the buffer command is encountered.

            cout << "Please enter price: ";
            cin >> priceGame;
            ptrgames->setPrice(priceGame);

            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
            cout << "Please enter operating system type: ";
            getline(cin, osGame);
            ptrgames->setOs(osGame); // save immediately before any clearing the buffer command is encountered.

            ptrCompGames.push_back(ptrgames); // save the pointer into the vector array that holds every pointer to an object from the class ComputerGame. Using a vector means unlimited number of entries.
        }
        else
        {
            if (ch == 2)
            {
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
                cout << "Please enter the title of console game: ";
                getline(cin, titleGame);
                ptrconsoles->setTitle(titleGame); // save immediately before any clearing the buffer command is encountered.

                cout << "Please enter price: ";
                cin >> priceGame;
                ptrconsoles->setPrice(priceGame);

                cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
                cout << "Please enter console type: ";
                getline(cin, osGame);
                ptrconsoles->setOs(osGame); // save immediately before any clearing the buffer command is encountered.

                ptrConsGames.push_back(ptrconsoles); // save the pointer into the vector array that holds every pointer to an object from the class ComputerGame. Using a vector means unlimited number of entries.
            }
            else
            {
                cout << "Please select only '1' or '2'" << endl;
            }
        }

        cout << "Do you want to add another item (1=Yes/0=No)? ";
        cin >> choice;
        if (choice == 0)
        {
            break;
        }
    }

    cout << "Video Games List:" << endl;
    cout << "****************************************" << endl;

    for (int j = 0; j < (int)ptrCompGames.size(); j++)
    {
        ptrCompGames[j]->display();
    }

    for (int j = 0; j < (int)ptrConsGames.size(); j++)
    {
        ptrConsGames[j]->display();
    }

    return 0;
}