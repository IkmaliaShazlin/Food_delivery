#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        double distanceKm, foodPrice;
        double deliveryFee, totalPrice;

        const double RATE_PER_KM = 0.50;
        const double MIN_DELIVERY = 3.00;
        const double FREE_DELIVERY_LIMIT = 50.00;

        cout << "=============================\n";
        cout << "   🍔 FOOD DELIVERY SYSTEM   \n";
        cout << "=============================\n";
        cout << fixed << setprecision(2);
        cout << "Delivery Rate : RM " << RATE_PER_KM << " per km\n";
        cout << "Minimum Fee   : RM " << MIN_DELIVERY << endl;
        cout << "Free Delivery : Orders RM " << FREE_DELIVERY_LIMIT << " and above\n";
        cout << "=============================\n\n";

        // Input
        cout << "Enter distance (km): ";
        cin >> distanceKm;

        cout << "Enter food price (RM): ";
        cin >> foodPrice;

        // Calculate delivery fee
        deliveryFee = RATE_PER_KM * distanceKm;

        if (deliveryFee < MIN_DELIVERY) {
            deliveryFee = MIN_DELIVERY;
        }

        if (foodPrice >= FREE_DELIVERY_LIMIT) {
            deliveryFee = 0.00;
        }

        totalPrice = foodPrice + deliveryFee;

        // Output
        cout << "\n--------- RECEIPT ---------\n";
        cout << "Food Price     : RM " << foodPrice << endl;
        cout << "Delivery Fee   : RM " << deliveryFee << endl;
        cout << "---------------------------\n";
        cout << "Total Amount   : RM " << totalPrice << endl;
        cout << "---------------------------\n";

        cout << "\nPlace another order? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using our service! 🚀\n";

    return 0;
}
