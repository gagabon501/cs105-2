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
            cout << "OS Type: " << os << endl;
        }
    
    
};

int main()
{
    ComputerGame cgames;
    cgames.setTitle("Counter Strike");
    cgames.setPrice(10.50);
    cgames.setOs("Windows");
    cgames.display();
   
    return 0;
}
