#include <iostream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    cout << "\nHello, " << name << "!" << endl;
    cout << "Next year, you will be " << age + 1 << " years old." << endl;

    return 0;
}
