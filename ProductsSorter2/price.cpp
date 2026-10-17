#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "product.cpp"

using namespace std;

class ProductCollection {
private:
    vector<Product> products;
    int nextOrder = 1;

public:
    void initPrice() {
        products.clear();
        nextOrder = 1;

        products.push_back({ "Green Whiteboard Marker", 17.50, 10, 10, nextOrder++ });
        products.push_back({ "Lined Copybook", 7.50, 10, 20, nextOrder++ });
        products.push_back({ "Blue Pen", 19.95, 5, 25, nextOrder++ });
        products.push_back({ "Grided Copybook", 7.50, 5, 20, nextOrder++ });
        products.push_back({ "Black Pencil", 14.95, 0, 20, nextOrder++ });
        products.push_back({ "Ruler 30cm", 3.50, 0, 50, nextOrder++ });

        cout << "Products initialized successfully.\n";
    }

    void loadPrice() {
        int n;

        cout << "Enter number of products to add: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid number of products.\n";
            return;
        }

        for (int i = 0; i < n; i++) {
            Product p;

            cout << "\nProduct name: ";
            getline(cin >> ws, p.name);

            cout << "Price: ";
            cin >> p.price;

            cout << "Discount (%): ";
            cin >> p.discount;

            cout << "Available quantity: ";
            cin >> p.quantity;

            if (p.price < 0 || p.discount < 0 ||
                p.discount > 100 || p.quantity < 0) {
                cout << "Invalid product data. Product skipped.\n";
                continue;
            }

            p.order = nextOrder++;
            products.push_back(p);
        }
    }

    void showPrice() const {
        if (products.empty()) {
            cout << "No products available. Initialize products first.\n";
            return;
        }

        for (const auto& p : products) {
            cout << p.name << ", $"
                << fixed << setprecision(2) << p.price
                << " (discount " << p.discount
                << "), available " << p.quantity
                << " pcs, popularity " << p.order << '\n';
        }
    }

    void showPriceByAscending() {
        sort(products.begin(), products.end(),
            [](const Product& a, const Product& b) {
                return a.price < b.price;
            });

        showPrice();
    }

    void showPriceByDescending() {
        sort(products.begin(), products.end(),
            [](const Product& a, const Product& b) {
                return a.price > b.price;
            });

        showPrice();
    }

    void showDiscountByAscending() {
        sort(products.begin(), products.end(),
            [](const Product& a, const Product& b) {
                return a.discount < b.discount;
            });

        showPrice();
    }

    void showDiscountByDescending() {
        sort(products.begin(), products.end(),
            [](const Product& a, const Product& b) {
                return a.discount > b.discount;
            });

        showPrice();
    }

    void showPriceByPopularity() {
        sort(products.begin(), products.end(),
            [](const Product& a, const Product& b) {
                return a.order < b.order;
            });

        showPrice();
    }
};