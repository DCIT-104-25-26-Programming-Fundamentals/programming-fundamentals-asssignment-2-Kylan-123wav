// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// This program performs basic arithmetic operations using functions.
// It displays a menu repeatedly until the user chooses to quit.
//
// Operations:
// 1. Addition
// 2. Subtraction
// 3. Multiplication
// 4. Division
// 5. Modulus
// 6. Exponentiation
// 7. Quit
//
// Requirements Met:
// - Each operation is implemented in its own function.
// - Uses a loop so the calculator keeps running.
// - Handles division/modulus by zero safely.
// - Displays decimal answers using fixed and setprecision(2).
// - Handles invalid menu choices.
// - Uses pow() from <cmath> for exponentiation.
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// ===========================
// Function Declarations
// ===========================

// Returns the sum of two numbers
double add(double a, double b)
{
    return a + b;
}

// Returns the difference of two numbers
double subtract(double a, double b)
{
    return a - b;
}

// Returns the product of two numbers
double multiply(double a, double b)
{
    return a * b;
}

// Returns the quotient of two numbers
double divide(double a, double b)
{
    return a / b;
}

// Returns the remainder of two integers
int modulus(int a, int b)
{
    return a % b;
}

// Returns a raised to the power of b
double exponent(double a, double b)
{
    return pow(a, b);
}

// ===========================
// Main Function
// ===========================

int main()
{
    int choice;
    double num1, num2;

    // Display decimal values with two decimal places
    cout << fixed << setprecision(2);

    do
    {
        // Display Menu
        cout << "\n=================================\n";
        cout << "       SIMPLE CALCULATOR\n";
        cout << "=================================\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Exponentiation\n";
        cout << "7. Quit\n";
        cout << "Select an operation (1-7): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "\nEnter first number : ";
                cin >> num1;

                cout << "Enter second number: ";
                cin >> num2;

                cout << "Result: "
                     << num1 << " + " << num2
                     << " = " << add(num1, num2) << endl;
                break;

            case 2:
                cout << "\nEnter first number : ";
                cin >> num1;

                cout << "Enter second number: ";
                cin >> num2;

                cout << "Result: "
                     << num1 << " - " << num2
                     << " = " << subtract(num1, num2) << endl;
                break;

            case 3:
                cout << "\nEnter first number : ";
                cin >> num1;

                cout << "Enter second number: ";
                cin >> num2;

                cout << "Result: "
                     << num1 << " * " << num2
                     << " = " << multiply(num1, num2) << endl;
                break;

            case 4:
                cout << "\nEnter first number : ";
                cin >> num1;

                cout << "Enter second number: ";
                cin >> num2;

                if (num2 == 0)
                {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                else
                {
                    cout << "Result: "
                         << num1 << " / " << num2
                         << " = " << divide(num1, num2) << endl;
                }
                break;

            case 5:
            {
                int a, b;

                cout << "\nEnter first number : ";
                cin >> a;

                cout << "Enter second number: ";
                cin >> b;

                if (b == 0)
                {
                    cout << "Error: Cannot divide by zero." << endl;
                }
                else
                {
                    cout << "Result: "
                         << a << " % " << b
                         << " = " << modulus(a, b) << endl;
                }

                break;
            }

            case 6:
                cout << "\nEnter first number : ";
                cin >> num1;

                cout << "Enter second number: ";
                cin >> num2;

                cout << "Result: "
                     << num1 << " ^ " << num2
                     << " = " << exponent(num1, num2) << endl;
                break;

            case 7:
                cout << "\nGoodbye!" << endl;
                break;

            default:
                cout << "\nInvalid choice! Please select a number between 1 and 7." << endl;
        }

    } while (choice != 7);

    return 0;
}