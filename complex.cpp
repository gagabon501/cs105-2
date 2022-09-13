/***********************************************************************************
 * Title        : CS-105 Development Principles-2 Assessment 2
 * File         : complex.cpp
 * Purpose      : Section 2 - Question 3: Operator Overloading
 *                This program showcases operator overloading for '+', '-', '*' and using this on complex numbers
 * Parameters   : N/A
 * Returns      : N/A
 * Author       : Gilberto Gabon - Student No.: 270204759
 ************************************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Complex
{
private:
    int a, b;

public:
    Complex(int var1, int var2)
    {
        a = var1;
        b = var2;
    }

    string GetComplexNum()
    {
        return to_string(a) + " + " + to_string(b) + "i";
    };

    // Overload the '+' operator to add two complex number and return the sum in a string format
    string operator+(Complex const &otherNum)
    {
        string retVal = "";
        int sumA = 0, sumB = 0;

        sumA = this->a + otherNum.a;
        sumB = this->b + otherNum.b;

        retVal = to_string(sumA) + " + " + to_string(sumB) + "i";

        return retVal;
    }

    // Overload the '-' operator to add two complex number and return the sum in a string format
    string operator-(Complex const &otherNum)
    {
        string retVal = "", optrString = " + ";
        int diffA = 0, diffB = 0;

        diffA = this->a - otherNum.a;
        diffB = this->b - otherNum.b;
        optrString = diffB < 0 ? " - " : " + ";

        retVal = to_string(abs(diffA)) + optrString + to_string(abs(diffB)) + "i";

        return retVal;
    }
    string operator*(Complex const &otherNum)
    {
        string retVal = "", optrString = " + ";
        int prodA = 0, prodB = 0;

        prodA = (this->a * otherNum.a) - (this->b * otherNum.b);
        prodB = (this->a * otherNum.b) + (this->b * otherNum.a);

        retVal = to_string(prodA) + optrString + to_string(prodB) + "i";

        return retVal;
    }
};

void displayAddition(Complex num1, Complex num2)
{
    cout << "Addition" << endl;
    cout << "C1: " << num1.GetComplexNum() << endl;
    cout << "C2: " << num2.GetComplexNum() << endl;
    cout << "C3: " << num1 + num2 << endl; // add two complex numbers with the '+' operator as an overloaded operator
}

void displaySubtraction(Complex num1, Complex num2)
{
    cout << "Subtraction" << endl;
    cout << "C1: " << num1.GetComplexNum() << endl;
    cout << "C2: " << num2.GetComplexNum() << endl;
    cout << "C3: " << num1 - num2 << endl; // add two complex numbers with the '+' operator as an overloaded operator
}

void displayMultiplication(Complex num1, Complex num2)
{
    cout << "Multiplication" << endl;
    cout << "C1: " << num1.GetComplexNum() << endl;
    cout << "C2: " << num2.GetComplexNum() << endl;
    cout << "C3: " << num1 * num2 << endl; // add two complex numbers with the '+' operator as an overloaded operator
}

int main()
{
    Complex num1(3, 2); // initialize first complex number;
    int realNum, imaginaryNum;
    int choice = 0;

    cout << "1st Complex number: " << num1.GetComplexNum() << endl
         << endl;

    cout << "Enter 2nd Complex number values:" << endl;
    cout << "Enter real value: ";
    cin >> realNum;
    cout << "Enter imaginary value: ";
    cin >> imaginaryNum;

    Complex num2(realNum, imaginaryNum); // define complex number2

    while (choice != 4)
    {
        cout << "\nChoose Operation from Menu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Exit" << endl;
        cout << "\nPlease enter your option: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayAddition(num1, num2);
            break;
        case 2:
            displaySubtraction(num1, num2);
            break;
        case 3:
            displayMultiplication(num1, num2);
            break;

        default:
            break;
        }
    }

    return 0;
}