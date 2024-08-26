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
    // Create a Dog object
    Dog myDog;
    myDog.name = "Buddy";
    myDog.age = 3;
    myDog.price = 250.00;
    myDog.breed = "Labrador";
    myDog.isTrained = true;

    // Create a Cat object
    Cat myCat;
    myCat.name = "Whiskers";
    myCat.age = 2;
    myCat.price = 150.00;
    myCat.furColor = "Gray";
    myCat.isIndependent = true;

    // Display details of the Dog
    cout << "Dog Details:" << endl;
    myDog.getDetails();
    cout << endl;

    // Display details of the Cat
    cout << "Cat Details:" << endl;
    myCat.getDetails();

    return 0;
}
