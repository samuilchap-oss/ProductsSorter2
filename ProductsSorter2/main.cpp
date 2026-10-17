#include <iostream>
#include "price.cpp"

using namespace std;

int main() {
    ProductCollection collection;
    int choice;

    do {
        cout << "\n1: init price\n";
        cout << "2: load price\n";
        cout << "3: show price by popularity\n";
        cout << "4: show price by ascending\n";
        cout << "5: show price by descending\n";
        cout << "6: show discount by ascending\n";
        cout << "7: show discount by descending\n";
        cout << "0: exit\n";
        cout << "> ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            break;
        }

        switch (choice) {
        case 1:
            collection.initPrice();
            break;
        case 2:
            collection.loadPrice();
            break;
        case 3:
            collection.showPriceByPopularity();
            break;
        case 4:
            collection.showPriceByAscending();
            break;
        case 5:
            collection.showPriceByDescending();
            break;
        case 6:
            collection.showDiscountByAscending();
            break;
        case 7:
            collection.showDiscountByDescending();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}