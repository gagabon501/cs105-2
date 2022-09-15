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
    // Virtual function to get data inputs from user
    virtual void getVideoData() {
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // this clears the buffer thereby ensuring that any pending newline character does not get fed into variable and eventually causing a skip in the input
        cout << "Please enter the title of computer/console game: ";
        getline(cin, title); //direct straight saving to the object's property
        cout << "Please enter price: ";
        cin >> price; //direct straight saving to the object's property
    }

    // Display data from the class. Make this function a virtual function to effect dynamic binding
    virtual void display()
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

    // Display function - function overriding - polymorphism. This display() function has added the display of the OS type.
    void display()
    {
        VideoGame::display();              // call the display function of the base class
        cout << "OS Type: " << os << endl; // then add the derived class' display method
    }
    
    //Function override
    void getVideoData() {
        VideoGame::getVideoData();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
        cout << "Please enter operating system type: ";
        getline(cin, os); //direct - straight saving to the object's property
    }
    
};

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
    }
    
    //Function override
    void getVideoData() {
        VideoGame::getVideoData();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // clear the buffer
        cout << "Please enter console type: ";
        getline(cin, os); //direct - straight saving to the object's property
    }
};

int main()
{

    vector<VideoGame *> ptrVideoGames;

    ComputerGame *ptrgames;
    ConsoleGame *ptrconsoles;

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
            ptrgames->getVideoData(); //get games input
            ptrVideoGames.push_back(ptrgames); //save into the array of pointers
        }
        else
        {
            if (ch == 2)
            {
                ptrconsoles->getVideoData(); //get console inputs
                ptrVideoGames.push_back(ptrconsoles); //save into the array of pointers
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

      
    for (int j = 0; j < (int)ptrVideoGames.size(); j++)
    {
        ptrVideoGames[j]->display();
    }

    return 0;
}
