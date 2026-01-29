#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double distanceKm;
    double foodPrice;
    double deliveryFee;
    double totalPrice;

    // Input
    cout << "Enter distance km: ";
    cin >> distanceKm;

    cout << "Enter food price in (RM): ";
    cin >> foodPrice;

    // Calculation
    deliveryFee = 0.50 * distanceKm;
    totalPrice = foodPrice + deliveryFee;

    // Output
    cout << fixed << setprecision(2);
    cout << "\nDelivery Fee: RM " << deliveryFee << endl;
    cout << "Total Price: RM " << totalPrice << endl;

    return 0;
}

