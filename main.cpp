#include <iostream>
#include <string>

using namespace std;

// Pet Base Class
class Pet {
public:
    string name;
    int age;
    double price;

    // Static variable to count total number of pets (across all types)
    static int totalPets;

    Pet() {
        // Increment the totalPets count whenever a Pet (or derived class) is created
        totalPets++;
    }

    virtual ~Pet() {
        // Decrement totalPets when a pet is deleted
        totalPets--;
    }

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

// Initialize static variable
int Pet::totalPets = 0;

// Dog Class (Inherits from Pet)
class Dog : public Pet {
public:
    string breed;
    bool isTrained;

    // Static variable to count number of Dog objects created
    static int totalDogs;

    Dog() {
        totalDogs++;  // Increment totalDogs count when a Dog is created
    }

    ~Dog() {
        totalDogs--;  // Decrement totalDogs count when a Dog is deleted
    }

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

// Initialize static variable
int Dog::totalDogs = 0;

// Cat Class (Inherits from Pet)
class Cat : public Pet {
public:
    string furColor;
    bool isIndependent;

    // Static variable to count number of Cat objects created
    static int totalCats;

    Cat() {
        totalCats++;  // Increment totalCats count when a Cat is created
    }

    ~Cat() {
        totalCats--;  // Decrement totalCats count when a Cat is deleted
    }

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

// Initialize static variable
int Cat::totalCats = 0;

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

    // Display the total number of Dogs, Cats, and Pets created
    cout << "Total Pets: " << Pet::totalPets << endl;
    cout << "Total Dogs: " << Dog::totalDogs << endl;
    cout << "Total Cats: " << Cat::totalCats << endl;

    // Free the dynamically allocated memory
    delete[] dogs;  // deallocate the memory for the array of Dog objects
    delete[] cats;  // deallocate the memory for the array of Cat objects

    // Display the total after deletion
    cout << "After deletion:" << endl;
    cout << "Total Pets: " << Pet::totalPets << endl;
    cout << "Total Dogs: " << Dog::totalDogs << endl;
    cout << "Total Cats: " << Cat::totalCats << endl;

    return 0;
}
