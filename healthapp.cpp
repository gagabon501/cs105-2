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
    // Setter function
    void SetFunction(string nameUser, int stepsWalked, float kmsRun)
    {
        walkingSteps = stepsWalked;
        runningDistance = kmsRun;
        name = nameUser;
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
    void GetFunction()
    {
        cout << "Name: " << name << endl;
        cout << "Steps: " << walkingSteps << " steps" << endl;
        cout << "Walking + Running: " << runningDistance << " kms" << endl;
    }
};

int main()
{
    HealthActivity users[5], *ptrUsers; // define an array of users and a pointer to the array of type HealthActivity class
    ptrUsers = users;                   // pointer to the array users of type HealthActivity
    string userName = "";
    int walkSteps = 0, steps = 0;
    float runKms = 0.00, runs = 0.00;
    float averageSteps = 0.00, averageDistance = 0.00;

    // get data inputs
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the name, number of steps and walking + running distance: ";
        cin >> userName;
        cin >> walkSteps;
        cin >> runKms;
        (ptrUsers + i)->SetFunction(userName, walkSteps, runKms); // save the inputted data into the array via the pointer by calling the SetFunction() method from the HealthActivity class
    }

    // display output
    for (int i = 0; i < 5; i++)
    {
        (ptrUsers + i)->GetFunction();       // Display the inputted data via a pointer by calling the GetFunction() method from the HealthActivity class
        steps += (ptrUsers + i)->GetSteps(); // sum the steps from the array of users via a pointer by calling the GetSteps() method from the HealthActivity class
        runs += (ptrUsers + i)->GetRuns();   // sum the distance from the array of users via a pointer by calling the GetRuns() method from the HealthActivity class
    }

    averageSteps = steps / 5;   // Compute the average of 5 users
    averageDistance = runs / 5; // Compute the average of 5 users
    cout << "Average steps of 5 users: " << averageSteps << " steps" << endl;
    cout << "Average distance of walking + running for 5 users: " << averageDistance << " kms" << endl;

    return 0;
}