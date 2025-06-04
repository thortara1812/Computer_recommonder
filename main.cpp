#include <iostream>
#include <string>

using namespace std;

struct Laptop {
    string brand;
    string model;
    string useCase;
    double price;
    Laptop* next;
};

class LaptopList {
private:
    Laptop* head;
public:
    LaptopList() : head(nullptr) {}

    void addLaptop(const string& brand, const string& model, const string& useCase, double price) {
        Laptop* newLaptop = new Laptop{brand, model, useCase, price, nullptr};
        if (!head) {
            head = newLaptop;
        } else {
            Laptop* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newLaptop;
        }
    }

    void recommendLaptop(const string& useCase, double budget) {
        Laptop* temp = head;
        bool found = false;
        while (temp) {
            if (temp->useCase == useCase && temp->price <= budget) {
                cout << "Recommended Laptop: " << temp->brand << " " << temp->model << endl;
                cout << "Price: $" << temp->price << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No laptops found for the specified use case and budget." << endl;
        }
    }

    ~LaptopList() {
        while (head) {
            Laptop* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

void sellerInput(LaptopList& laptops) {
    int numLaptops;
    cout << "Enter the number of laptops you want to add: ";
    cin >> numLaptops;

    for (int i = 0; i < numLaptops; ++i) {
        string brand, model, useCase;
        double price;
        cout << "Enter details for laptop " << i + 1 << endl;
        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Use Case (e.g., Gaming, Programming, Business, General Use): ";
        cin >> useCase;
        cout << "Price: $";
        cin >> price;

        laptops.addLaptop(brand, model, useCase, price);
    }
}

void buyerInput(LaptopList& laptops) {
    string useCase;
    double budget;

    cout << "Enter your required use case (e.g., Gaming, Programming, Business, General Use): ";
    cin >> useCase;
    cout << "Enter your budget: $";
    cin >> budget;

    laptops.recommendLaptop(useCase, budget);
}

int main() {
    LaptopList laptops;

    cout << "Seller Input Section:" << endl;
    sellerInput(laptops);

    cout << "\nBuyer Input Section:" << endl;
    buyerInput(laptops);

    return 0;
}
