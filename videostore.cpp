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
    void setOs(int o)
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

    ComputerGame *ptrCompGames[10];
    ConsoleGame *ptrConsGames[10];

    string titleGame;
    float priceGame;
    string osGame;
    int i = 0;

    int choice = 1, ch = 1;
    ComputerGame ogames; // define an object for the games
    ComputerGame *ptrgames;

    while (choice != 0 || i > 10)
    {
        ptrgames = new ComputerGame;
        cout << "Do you want to enter data for a Computer Game or a Console Game (1 / 2): ";
        cin >> ch;

        if (ch == 1)
        {
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please enter the title of computer game: ";
            getline(cin, titleGame);
            ptrgames->setTitle(titleGame);

            cout << "Please enter price: ";
            cin >> priceGame;
            ptrgames->setPrice(priceGame);

            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please enter operating system type: ";
            getline(cin, osGame);
            ptrgames->setOs(osGame);

            ptrCompGames[i] = ptrgames;
        }
        else
        {
            if (ch == 2)
            {
                cout << "Console games";
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

        i++;
    }
    cout << "i: " << i << endl;

    for (int j = 0; j <= i; j++)
    {
        ptrCompGames[j]->display();
        // cout << ptrCompGames[j] << endl;
    }

    return 0;
}