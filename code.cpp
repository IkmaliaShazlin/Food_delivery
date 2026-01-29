#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char choice;

    do {
        double distanceKm;
        double foodPrice = 0.0;
        double deliveryFee, totalPrice;
        int menuChoice;
        char addMore;

        string foodList = "";

        const double RATE_PER_KM = 0.50;
        const double MIN_DELIVERY = 3.00;
        const double FREE_DELIVERY_LIMIT = 50.00;

        cout << "=============================\n";
        cout << "    FOOD DELIVERY SYSTEM   \n";
        cout << "=============================\n";
        cout << fixed << setprecision(2);
        cout << "Delivery Rate : RM " << RATE_PER_KM << " per km\n";
        cout << "Minimum Fee   : RM " << MIN_DELIVERY << endl;
        cout << "Free Delivery : Orders RM " << FREE_DELIVERY_LIMIT << " and above\n";
        cout << "=============================\n\n";

        // Input distance
        cout << "Enter distance (km): ";
        cin >> distanceKm;

        // Food ordering loop
        do {
            cout << "\n------ Malay Food Menu ------\n";
            cout << "1. Nasi Lemak         - RM 3.50\n";
            cout << "2. Teh O Ais         - RM 2.50\n";
            cout << "3. Ayam Goreng + Rice - RM 8.00\n";
            cout << "-----------------------------\n";
            cout << "Choose menu (1-3): ";
            cin >> menuChoice;

            if (menuChoice == 1) {
                foodPrice += 3.50;
                foodList += "Nasi Lemak\n";
            } 
            else if (menuChoice == 2) {
                foodPrice += 2.50;
                foodList += "Teh O Ais\n";
            } 
            else if (menuChoice == 3) {
                foodPrice += 8.00;
                foodList += "Ayam Goreng + Rice\n";
            } 
            else {
                cout << "Invalid choice. Item not added.\n";
            }

            cout << "Add another food? (y/n): ";
            cin >> addMore;

        } while (addMore == 'y' || addMore == 'Y');

        // Calculate delivery fee
        deliveryFee = RATE_PER_KM * distanceKm;

        if (deliveryFee < MIN_DELIVERY) {
            deliveryFee = MIN_DELIVERY;
        }

        if (foodPrice >= FREE_DELIVERY_LIMIT) {
            deliveryFee = 0.00;
        }

        totalPrice = foodPrice + deliveryFee;

        // Receipt
        cout << "\n--------- RECEIPT ---------\n";
        cout << "Food Ordered:\n" << foodList;
        cout << "---------------------------\n";
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
