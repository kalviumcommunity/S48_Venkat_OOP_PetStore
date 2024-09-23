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

    void inputDetails() {
        cout << "Enter Pet Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Price: ";
        cin >> price;
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

    void inputDetails() {
        Pet::inputDetails();  // Get the base pet details
        cout << "Enter Breed: ";
        cin >> breed;
        cout << "Is the dog trained? (1 for Yes, 0 for No): ";
        cin >> isTrained;
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

    void inputDetails() {
        Pet::inputDetails();  // Get the base pet details
        cout << "Enter Fur Color: ";
        cin >> furColor;
        cout << "Is the cat independent? (1 for Yes, 0 for No): ";
        cin >> isIndependent;
    }
};

// Main function
int main() {
    int numDogs, numCats;

    // Asking for number of pets to input
    cout << "Enter the number of dogs: ";
    cin >> numDogs;

    cout << "Enter the number of cats: ";
    cin >> numCats;

    // Dynamically allocate an array of Dog objects
    Dog* dogs = new Dog[numDogs]; // using new to allocate memory for Dog objects dynamically
    
    // Take input from the user for Dog objects
    for (int i = 0; i < numDogs; i++) {
        cout << "Enter details for Dog " << i + 1 << ":" << endl;
        dogs[i].inputDetails();
        cout << endl;
    }

    // Dynamically allocate an array of Cat objects
    Cat* cats = new Cat[numCats]; // using new to allocate memory for Cat objects dynamically
    
    // Take input from the user for Cat objects
    for (int i = 0; i < numCats; i++) {
        cout << "Enter details for Cat " << i + 1 << ":" << endl;
        cats[i].inputDetails();
        cout << endl;
    }

    // Display details of all Dogs
    cout << "Dog Details:" << endl;
    for (int i = 0; i < numDogs; i++) {
        dogs[i].getDetails();
        cout << endl;
    }

    // Display details of all Cats
    cout << "Cat Details:" << endl;
    for (int i = 0; i < numCats; i++) {
        cats[i].getDetails();
        cout << endl;
    }

    // Free the dynamically allocated memory
    delete[] dogs;  // deallocate the memory for the array of Dog objects
    delete[] cats;  // deallocate the memory for the array of Cat objects

    return 0;
}
