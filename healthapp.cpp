/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 2
 * File         : healthapp.cpp
 * Purpose      : Section 1 - Question 1: Pointer to Objects
 *                This program showcases the use of pointer to objects.
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 ************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

// define the class
class HealthActivity
{
private:
    int walkingSteps;
    float runningDistance;
    string name;

public:
    HealthActivity(string username, int steps, float distance) // class constructor
    {
        name = username;
        walkingSteps = steps;
        runningDistance = distance;
    }

    // Getter functions
    string GetName()
    {
        return name;
    }
    int GetSteps()
    {
        return walkingSteps;
    }
    float GetRuns()
    {
        return runningDistance;
    }
    // Display data from the class
    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Steps: " << walkingSteps << " steps" << endl;
        cout << "Walking + Running: " << runningDistance << " kms" << endl;
    }
};

// this setFunction() receives an array of pointers to objects from the class HealthActivity
void setFunction(HealthActivity *ptrUsers[5])
{
    int walkSteps = 0;
    float runKms = 0.00;
    string name = "";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the name, number of steps and walking + running distance: ";
        cin >> name;
        cin >> walkSteps;
        cin >> runKms;
        ptrUsers[i] = new HealthActivity(name, walkSteps, runKms); // create the object and save the address of that object to the array
    }
}

// this getFunction() receives an arra of pointers to objects from the class HealthActivity
void getFunction(HealthActivity *ptrUsers[5])
{
    int sumSteps = 0;
    float sumDistance = 0.00, avgSteps = 0.00, avgDistance = 0.00;
    for (int i = 0; i < 5; i++)
    {
        ptrUsers[i]->displayData();            // call the method to display the data of the current object
        sumSteps += ptrUsers[i]->GetSteps();   // accumulate the number of steps taken
        sumDistance += ptrUsers[i]->GetRuns(); // accumulate the distance taken
    }
    avgSteps = sumSteps / 5;       // computer for the average of the number of steps taken
    avgDistance = sumDistance / 5; // compute for the average of the distances taken
    cout << "Average steps of 5 users: " << avgSteps << " steps" << endl;
    cout << "Average distance of walking + running for 5 users: " << avgDistance << " kms" << endl;
}

int main()
{
    HealthActivity *ptrUsers[5]; // define an array of pointers to objects
    setFunction(ptrUsers);       // get user inputs
    getFunction(ptrUsers);       // display outputs

    return 0;
}