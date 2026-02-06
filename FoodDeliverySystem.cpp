#include <iostream>      // For input and output
#include <iomanip>       // For output formatting (setprecision)
#include <string>        // For string data type

using namespace std;

int main() {

    // ===== Constant values (delivery rules) =====
    const double RATE_PER_KM = 0.50;          // Delivery charge per kilometer
    const double MIN_DELIVERY = 3.00;         // Minimum delivery fee
    const double FREE_DELIVERY_LIMIT = 50.00; // Minimum order for free delivery
    const double SERVICE_TAX = 2.50;          // Fixed service tax

    // ===== Variable declarations =====
    double distanceKm;        // Distance entered by user
    double foodPrice = 0.0;   // Total food price
    double deliveryFee;       // Calculated delivery fee
    double subtotal;          // Subtotal before discount
    double totalPrice;        // Final amount to pay

    char addMore;             // User choice to add more food
    string foodList = "";     // Stores ordered food details
    int itemCount = 0;        // Counts number of food items ordered

    // Format output to 2 decimal places
    cout << fixed << setprecision(2);

    // ===== Program header =====
    cout << "=============================\n";
    cout << "    FOOD DELIVERY SYSTEM   \n";
    cout << "=============================\n";
    cout << "Delivery Rate : RM " << RATE_PER_KM << " per km\n";
    cout << "Minimum Fee   : RM " << MIN_DELIVERY << endl;
    cout << "Free Delivery : Orders RM " << FREE_DELIVERY_LIMIT << " and above\n";
    cout << "=============================\n\n";

    // ===== Food Ordering Loop =====
    // Allows user to enter multiple food items
    do {
        string restaurant, foodName;
        double price;

        cout << "\nEnter restaurant name: ";
        getline(cin, restaurant);

        cout << "Enter food name: ";
        getline(cin, foodName);

        // Input validation for food price
        cout << "Enter food price (RM): ";
        while (!(cin >> price) || price <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid price. Enter again (RM): ";
        }
        cin.ignore();

        // Add price to total and increment item count
        foodPrice += price;
        itemCount++;

        // Store food details with formatted price
        char priceStr[20];
        sprintf(priceStr, "%.2f", price);
        foodList += restaurant + " - " + foodName + " : RM " + priceStr + "\n";

        // Ask user if they want to add another food item
        cout << "Add another food? (y/n): ";
        cin >> addMore;
        cin.ignore();

        // Validate y/n input
        while (addMore != 'y' && addMore != 'Y' &&
               addMore != 'n' && addMore != 'N') {
            cout << "Invalid input. Enter y or n: ";
            cin >> addMore;
            cin.ignore();
        }

    } while (addMore == 'y' || addMore == 'Y');

    // ===== Distance Input =====
    // Input validation for delivery distance
    cout << "\nEnter distance (km): ";
    while (!(cin >> distanceKm) || distanceKm <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid distance. Enter again (km): ";
    }
    cin.ignore();

    // ===== Calculations =====
    // Calculate delivery fee based on distance
    deliveryFee = RATE_PER_KM * distanceKm;

    // Apply minimum delivery fee if necessary
    if (deliveryFee < MIN_DELIVERY)
        deliveryFee = MIN_DELIVERY;

    // Calculate subtotal
    subtotal = foodPrice + deliveryFee + SERVICE_TAX;

    // Check for free delivery eligibility
    double freeDeliveryDiscount = 0.0;
    if (foodPrice >= FREE_DELIVERY_LIMIT) {
        freeDeliveryDiscount = deliveryFee;
    }

    // Calculate final total price
    totalPrice = subtotal - freeDeliveryDiscount;

    // ===== Receipt Output =====
    cout << "\n--------- RECEIPT ---------\n";
    cout << "Food Ordered:\n" << foodList;
    cout << "Items Ordered : " << itemCount << endl;
    cout << "---------------------------\n";
    cout << "Food Price     : RM " << foodPrice << endl;
    cout << "Delivery Fee   : RM " << deliveryFee << endl;
    cout << "Service Tax    : RM " << SERVICE_TAX << endl;
    cout << "---------------------------\n";
    cout << "Subtotal       : RM " << subtotal << endl;

    // Display free delivery discount if applicable
    if (freeDeliveryDiscount > 0) {
        cout << "Free Delivery  : -RM " << freeDeliveryDiscount << endl;
    }

    cout << "---------------------------\n";
    cout << "Total Amount   : RM " << totalPrice << endl;
    cout << "---------------------------\n";

    cout << "\nThank you for supporting our service!\n\n";

    return 0;
}
