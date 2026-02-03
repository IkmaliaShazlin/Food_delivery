#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const double RATE_PER_KM = 0.50;
    const double MIN_DELIVERY = 3.00;
    const double FREE_DELIVERY_LIMIT = 50.00;
    const double SERVICE_TAX = 2.50;

    double distanceKm;
    double foodPrice = 0.0;
    double deliveryFee, subtotal, totalPrice;
    char addMore;
    string foodList = "";

    int itemCount = 0;

    cout << fixed << setprecision(2);

    cout << "=============================\n";
    cout << "    FOOD DELIVERY SYSTEM   \n";
    cout << "=============================\n";
    cout << "Delivery Rate : RM " << RATE_PER_KM << " per km\n";
    cout << "Minimum Fee   : RM " << MIN_DELIVERY << endl;
    cout << "Free Delivery : Orders RM " << FREE_DELIVERY_LIMIT << " and above\n";
    cout << "=============================\n\n";

    // ===== Food Ordering Loop =====
    do {
        string restaurant, foodName;
        double price;

        cout << "\nEnter restaurant name: ";
        getline(cin, restaurant);

        cout << "Enter food name: ";
        getline(cin, foodName);

        // FIXED PRICE INPUT
        cout << "Enter food price (RM): ";
        while (!(cin >> price) || price <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid price. Enter again (RM): ";
        }
        cin.ignore();

        foodPrice += price;
        itemCount++;

        // Format price to 2 decimal places
        char priceStr[20];
        sprintf(priceStr, "%.2f", price);
        foodList += restaurant + " - " + foodName + " : RM " + priceStr + "\n";

        // Add more food
        cout << "Add another food? (y/n): ";
        cin >> addMore;
        cin.ignore();

        while (addMore != 'y' && addMore != 'Y' &&
               addMore != 'n' && addMore != 'N') {
            cout << "Invalid input. Enter y or n: ";
            cin >> addMore;
            cin.ignore();
        }

    } while (addMore == 'y' || addMore == 'Y');

    // FIXED DISTANCE INPUT
    cout << "\nEnter distance (km): ";
    while (!(cin >> distanceKm) || distanceKm <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid distance. Enter again (km): ";
    }
    cin.ignore();

    // ===== Calculations =====
    deliveryFee = RATE_PER_KM * distanceKm;
    if (deliveryFee < MIN_DELIVERY)
        deliveryFee = MIN_DELIVERY;

    subtotal = foodPrice + deliveryFee + SERVICE_TAX;

    double freeDeliveryDiscount = 0.0;
    if (foodPrice >= FREE_DELIVERY_LIMIT) {
        freeDeliveryDiscount = deliveryFee;
    }

    totalPrice = subtotal - freeDeliveryDiscount;

    // ===== Receipt =====
    cout << "\n--------- RECEIPT ---------\n";
    cout << "Food Ordered:\n" << foodList;
    cout << "Items Ordered : " << itemCount << endl;
    cout << "---------------------------\n";
    cout << "Food Price     : RM " << foodPrice << endl;
    cout << "Delivery Fee   : RM " << deliveryFee << endl;
    cout << "Service Tax    : RM " << SERVICE_TAX << endl;
    cout << "---------------------------\n";
    cout << "Subtotal       : RM " << subtotal << endl;

    if (freeDeliveryDiscount > 0) {
        cout << "Free Delivery  : -RM " << freeDeliveryDiscount << endl;
    }

    cout << "---------------------------\n";
    cout << "Total Amount   : RM " << totalPrice << endl;
    cout << "---------------------------\n";

    cout << "\nThank you for supporting our service!\n\n";

    return 0;
}
