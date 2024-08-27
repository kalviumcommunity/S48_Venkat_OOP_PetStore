#include <iostream>
#include <string>

using namespace std;

// Pet Base Class
class Pet {
public:
    string name;
    int age;
    double price;

    void getDetails() {
        cout << "Pet Name: " << this->name << endl;
        cout << "Age: " << this->age << " years" << endl;
        cout << "Price: $" << this->price << endl;
    }
};

// Dog Class (Inherits from Pet)
class Dog : public Pet {
public:
    string breed;
    bool isTrained;

    void getDetails() {
        Pet::getDetails();
        cout << "Breed: " << this->breed << endl;
        cout << "Trained: " << (this->isTrained ? "Yes" : "No") << endl;
    }
};

// Cat Class (Inherits from Pet)
class Cat : public Pet {
public:
    string furColor;
    bool isIndependent;

    void getDetails() {
        Pet::getDetails();
        cout << "Fur Color: " << this->furColor << endl;
        cout << "Independent: " << (this->isIndependent ? "Yes" : "No") << endl;
    }
};

// Main function
int main() {
    // Create an array of Dog objects
    Dog dogs[2];
    
    dogs[0].name = "Buddy";
    dogs[0].age = 3;
    dogs[0].price = 250.00;
    dogs[0].breed = "Labrador";
    dogs[0].isTrained = true;
    
    dogs[1].name = "Max";
    dogs[1].age = 2;
    dogs[1].price = 200.00;
    dogs[1].breed = "Beagle";
    dogs[1].isTrained = false;

    // Create an array of Cat objects
    Cat cats[2];
    
    cats[0].name = "Whiskers";
    cats[0].age = 2;
    cats[0].price = 150.00;
    cats[0].furColor = "Gray";
    cats[0].isIndependent = true;
    
    cats[1].name = "Mittens";
    cats[1].age = 1;
    cats[1].price = 120.00;
    cats[1].furColor = "White";
    cats[1].isIndependent = false;

    // Display details of all Dogs
    cout << "Dog Details:" << endl;
    for (int i = 0; i < 2; i++) {
        dogs[i].getDetails();
        cout << endl;
    }

    // Display details of all Cats
    cout << "Cat Details:" << endl;
    for (int i = 0; i < 2; i++) {
        cats[i].getDetails();
        cout << endl;
    }

    return 0;
}
