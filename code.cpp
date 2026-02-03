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
    bool validInput = true;   

    cout << fixed << setprecision(2);

    cout << "=============================\n";
    cout << "    FOOD DELIVERY SYSTEM   \n";
    cout << "=============================\n";
    cout << "Delivery Rate : RM " << RATE_PER_KM << " per km\n";
    cout << "Minimum Fee   : RM " << MIN_DELIVERY << endl;
    cout << "Free Delivery : Orders RM " << FREE_DELIVERY_LIMIT << " and above\n";
    cout << "=============================\n\n";

    // Food ordering loop
    do {
        string restaurant, foodName;
        double price;

        cout << "\nEnter restaurant name: ";
        getline(cin, restaurant);

        cout << "Enter food name: ";
        getline(cin, foodName);

        cout << "Enter food price (RM): ";
        cin >> price;
        cin.ignore();

        if (cin.fail() || price <= 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid price. Please enter a valid amount.\n";
    continue;   // restart loop without counting item
}

        foodPrice += price;

        itemCount++;   // Count number of items ordered

        // FIX: use sprintf to format to 2 decimals
        char priceStr[20];
        sprintf(priceStr, "%.2f", price);
        foodList += restaurant + " - " + foodName + " : RM " + priceStr + "\n";

        cout << "Add another food? (y/n): ";
        cin >> addMore;
        cin.ignore();

    } while (addMore == 'y' || addMore == 'Y');

    cout << "\nEnter distance (km): ";
    cin >> distanceKm;
    cin.ignore();

    // Calculate delivery fee
    deliveryFee = RATE_PER_KM * distanceKm;
    if (deliveryFee < MIN_DELIVERY) deliveryFee = MIN_DELIVERY;

    // Calculate subtotal
    subtotal = foodPrice + deliveryFee + SERVICE_TAX;

    // Free delivery check
    double freeDeliveryDiscount = 0.0;
    if (foodPrice >= FREE_DELIVERY_LIMIT) {
        freeDeliveryDiscount = deliveryFee;
    }
    totalPrice = subtotal - freeDeliveryDiscount;

    // Print receipt
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
