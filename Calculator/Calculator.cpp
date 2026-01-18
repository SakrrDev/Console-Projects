#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Operation {
public:
    virtual double execute(double a, double b) = 0;
    virtual string name() = 0;
    virtual ~Operation() {}
};

class Add : public Operation {
public:
    double execute(double a, double b){
        return a + b;
    }
    string name()  {
        return "Addition";
    }
};

class Subtract : public Operation {
public:
    double execute(double a, double b)  {
        return a - b;
    }
    string name()   {
        return "Subtraction";
    }
};

class Multiply : public Operation {
public:
    double execute(double a, double b)   {
        return a * b;
    }
    string name()   {
        return "Multiplication";
    }
};

class Divide : public Operation {
public:
    double execute(double a, double b)   {
        if (b == 0){
            cout << "Division by zero is not allowed" << endl;
        } else {

            return a / b;
        }
    }
    string name()   {
        return "Division";
    }
};

class Power : public Operation {
public:
    double execute(double a, double b)   {
        return pow(a, b);
    }
    string name()   {
        return "Power";
    }
};

class History {
private:
    string records[100];
    int count;

public:
    History() : count(0) {}

    void add(const string& record) {
        if (count < 100)
            records[count++] = record;
    }

    void show() const {
        if (count == 0) {
            cout << "No operations yet.\n";
            return;
        }
        for (int i = 0; i < count; i++)
            cout << i + 1 << ") " << records[i] << endl;
    }
};

class Calculator {
private:
    History history;

public:
    double calculate(Operation* op, double a, double b) {
        double result = op->execute(a, b);
        history.add(op->name());
        return result;
    }

    void showHistory() const {
        history.show();
    }
};

int main() {
    Calculator calc;

    Add add;
    Subtract sub;
    Multiply mul;
    Divide div;
    Power pow;

    int choice;
    double a, b;

    while (true) {
        cout << "\n==== Calculator Menu ====\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Power\n";
        cout << "6. Show History\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 6) {
            calc.showHistory();
            continue;
        }

        cout << "Enter first number: "; cin >> a;
        cout << "Enter second number: "; cin >> b;

        try {
            double result;

            switch (choice) {
            case 1:
                result = calc.calculate(&add, a, b);
                break;
            case 2:
                result = calc.calculate(&sub, a, b);
                break;
            case 3:
                result = calc.calculate(&mul, a, b);
                break;
            case 4:
                result = calc.calculate(&div, a, b);
                break;
            case 5:
                result = calc.calculate(&pow, a, b);
                break;
            default:
                cout << "Invalid choice\n";
                continue;
            }

            cout << "Result = " << result << endl;
        }
        catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
