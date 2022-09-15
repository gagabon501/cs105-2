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
private:
    string title;
    float price;

public:
    // Virtual function to get data inputs from user. Made this virtual function for dynamic binding
    virtual void getVideoData()
    {
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
        cout << "Enter title of game: ";
        getline(cin, title); // direct straight saving to the class' property
        cout << "        Enter price: ";
        cin >> price; // direct straight saving to the class' property
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
    string os;

public:
    // Display function - function overriding - polymorphism. This display() function has added the display of the OS type.
    void display()
    {
        VideoGame::display();                   // call the display function of the base class
        cout << "     OS Type: " << os << endl; // then add the derived class' display method
        cout << "*********************************" << endl;
    }

    // getVideoData() function - function overriding - polymorphism. This getVideoData() function has added the input for the OS of the game
    void getVideoData()
    {
        VideoGame::getVideoData();                                // call the getVideoData() function of the base class
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
        cout << "   Operating System: ";
        getline(cin, os); // save straight to the class property
    }
};

// Derived Class
class ConsoleGame : public VideoGame
{
private:
    string os;

public:
    // Display function - function overriding - polymorphism. This display() function has added the display of the console type.
    void display()
    {
        VideoGame::display();                   // call the display function of the base class
        cout << "Console Type: " << os << endl; // then add the derived class' display method
        cout << "*********************************" << endl;
    }

    // getVideoData() function - function overriding - polymorphism. This getVideoData() function has added the input for the console type of the game
    void getVideoData()
    {
        VideoGame::getVideoData();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
        cout << "       Console type: ";
        getline(cin, os); // direct - straight saving to the object's property
    }
};

int main()
{

    vector<VideoGame *> ptrVideoGames; // Define the vector array that will contain all the pointer to objects. This is a pointer variable that is a vector of type VideoGame

    ComputerGame *ptrgames;   // Define the pointer to the game objects
    ConsoleGame *ptrconsoles; // Define the pointer to the console objects

    // int choice = 1, ch = 1;
    char choice = ' ', ch = ' ';

    cout << "\n**************************************************************************" << endl;
    cout << "                 Video Games Data Entry" << endl;
    cout << "**************************************************************************" << endl;

    while (true)
    {
        ptrgames = new ComputerGame;   // always create a new object for every iteration
        ptrconsoles = new ConsoleGame; // always create a new object for every iteration

        cout << "Do you want to enter data for a Computer Game [o] or a Console Game [c]: ";

        cin >> ch;

        if (ch == 'o' || ch == 'O')
        {
            ptrgames->getVideoData();          // get games input - made the code cleaner by placing the routine to take user input inside the Base Class and into the Derived Class (the added data to take from user)
            ptrVideoGames.push_back(ptrgames); // save into the array of pointers
        }
        else
        {
            if (ch == 'c' || ch == 'C')
            {
                ptrconsoles->getVideoData();          // get console inputs - made the code cleaner by placing the routine to take user input inside the Base Class and into the Derived Class (the added data to take from user)
                ptrVideoGames.push_back(ptrconsoles); // save into the array of pointers
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
    }

    cout << "\n*************************************************************************" << endl;
    cout << "                              Video Games List:" << endl;
    cout << "*************************************************************************" << endl;

    for (int j = 0; j < (int)ptrVideoGames.size(); j++)
    {
        ptrVideoGames[j]->display(); // polymorphism in action! The function display() here calls the relevant display() function based on the kind of object contained in the current element of the array of pointers
    }

    return 0;
}
