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
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
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
    {
        title = t;
    }

    void setPrice(float p)
    {
        price = p;
    }

    // Getters
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

    ComputerGame *ptrCompGames[10];
    ConsoleGame *ptrConsGames[10];

    string titleGame;
    float priceGame;
    string osGame;
    int i = 0;

    char choice = 'Y', ch = 'O';

    while (choice != 'N' || choice != 'n' || i > 10)
    {
        cout << "Do you want to enter data for a Computer Game or a Console Game (o / c): ";
        cin >> ch;

        if (ch == 'o' || ch == 'O')
        {
            ComputerGame ogames; // define an object for the games

            cout << "Please enter the title of computer game: ";
            getline(cin, titleGame);
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please enter price: ";
            cin >> priceGame;
            cout << "Please enter operating system type: ";
            getline(cin, osGame);
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

            // store data into the object
            ptrCompGames[i] = new ComputerGame;
            ptrCompGames[i]->setTitle(titleGame);
            ptrCompGames[i]->setPrice(priceGame);
            ptrCompGames[i]->setOs(osGame);
        }
        else
        {
            if (ch == 'C' || ch == 'c')
            {
                cout << "Console games";
            }
            else
            {
                cout << "Please select only 'O' or 'C'" << endl;
            }
        }

        cout << "Do you want to add another item? ";
        cin >> choice;
        if (choice == 'N' or choice == 'n')
        {
            break;
        }

        i++;
    }

    for (int i = 0; i < 10; i++)
    {
        ptrCompGames[i]->display();
    }

    return 0;
}