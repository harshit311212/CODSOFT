// Simple Calculator

#include <iostream>
using namespace std;
int main()
{
    int num1, num2;  //declaring numbers for calculation
    char op;  //declaring a variable for operator
    cout << "Enter the first digit:";
    cin >> num1;  //input of first number
    cout << "Enter the second digit:";
    cin >> num2;  //input of second number
    cout << "Enter the operator:";
    cin >> op;  //input of the operator
    switch (op)  //switch to toggle between operators
    {
    case '+':  //statement to perform addition
    cout << num1 << "+" << num2 << "=" << (num1 + num2);
    break;
    case '*':  //statement to perform multiplication
    cout << num1 << "*" << num2 << "=" << (num1 * num2);
    break;
    case '/':  //statement to perform division
    cout << num1 << "/" << num2 << "=" << (num1 / num2);
    break;
    case '-':  //statement to perform subtraction
    cout << num1 << "-" << num2 << "=" << (num1 - num2);
    break;
    default:  //Statement to show if any other input is performed
    cout << "Invalid operator!";
        break;
    }
}
