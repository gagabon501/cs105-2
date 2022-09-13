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

using namespace std;

class VideoGame
{
private:
    string title;
    float price;

public:
    //Setters
    void setTitle(string t) {
        title = t;
    }
    
    void setPrice(float p) {
        price = p;
    }
    
    //Getters
    string getTitle() {
        return title;
    }
    
    float getPrice() {
        return price;
    }
        
    // Display data from the class
    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class ComputerGame: public VideoGame {
    private:
        string os;
    public:
    
        //Setters
        void setOs(string o) {
            os = o;
        }
    
        //Getters
        string getOs() {
            return os;
        }
    
        //Display function
        void display() {
            VideoGame::display(); //call the display function of the base class
            cout << "OS Type: " << os << endl; //then add the derived class' display method
        }
    
    
};

class ConsoleGame: public VideoGame {
    private:
        string os;
    public:
    
        //Setters
        void setOs(string o) {
            os = o;
        }
    
        //Getters
        string getOs() {
            return os;
        }
    
        //Display function
        void display() {
            VideoGame::display(); //call the display function of the base class
            cout << "Console Type: " << os << endl; //then add the derived class' display method
        }
    
    
};

int main()
{
    vector<ComputerGame> computerGames;
    vector<ConsoleGame> consoleGames;
    
    string titleGame;
    float priceGame;
    string osGame;
    
    char choice = 'Y', ch = 'O';
  
    // computerGames.setTitle("Counter Strike");
    // computerGames.setPrice(10.50);
    // computerGames.setOs("Windows");
    // computerGames.display();
    
    // consoleGames.setTitle("Arena Footbal");
    // consoleGames.setPrice(20.50);
    // consoleGames.setOs("X-Box");
    // consoleGames.display();
    
    while(toupper(choice) != 'N') {
        cout << "Do you want to enter data for a Computer Game or a Console Game (o / c): ";
        cin >> ch;
       
        if (toupper(ch) === 'O') {
            cout << "Please enter the title of computer game: ";
            cin.getline(titleGame);
            cout << "Please enter price: ";
            cin >> priceGame;
            cout << "Please enter operating system type: ";
            cin.getline(osGame);
            computerGames.push({titleGame, priceGame, osGame});
        } else {
            if(toupper(ch) === 'C') {
            } else {
                cout << "Please select only 'O' or 'C'" << endl;
            }
        }
        cout << "Do you want to add another item? ";
        cin >> choice;
    }
   
    return 0;
}
