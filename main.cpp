#include <iostream>
#include <string>

using namespace std;

// Abstract Pet Base Class
class Pet {
private:
    string name;
    int age;
    double price;

public:
    static int totalPets;

    // Static member function
    static int getTotalPets() {
        return totalPets;
    }

    // Default Constructor
    Pet() : name("Unknown"), age(0), price(0.0) {
        totalPets++;
    }

    // Parameterized Constructor
    Pet(string newName, int newAge, double newPrice) : name(newName), age(newAge), price(newPrice) {
        totalPets++;
    }

    // Destructor
    virtual ~Pet() {
        totalPets--;
    }

    // Accessor and Mutator methods
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getPrice() const {
        return price;
    }

    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    // Virtual function for displaying details
    virtual void getDetails() const {
        cout << "Pet Name: " << getName() << endl;
        cout << "Age: " << getAge() << " years" << endl;
        cout << "Price: $" << getPrice() << endl;
    }

    // Pure virtual function to make this an abstract class
    virtual void makeSound() const = 0;  // Abstract function
};

// Initialize static variable
int Pet::totalPets = 0;

// Dog Class (Hierarchical Inheritance: Inherits from Pet)
class Dog : public Pet {
private:
    string breed;
    bool isTrained;

public:
    static int totalDogs;

    // Static member function
    static int getTotalDogs() {
        return totalDogs;
    }

    // Default Constructor
    Dog() : Pet(), breed("Unknown"), isTrained(false) {
        totalDogs++;
    }

    // Parameterized Constructor
    Dog(string newName, int newAge, double newPrice, string newBreed, bool trained)
        : Pet(newName, newAge, newPrice), breed(newBreed), isTrained(trained) {
        totalDogs++;
    }

    // Destructor
    ~Dog() {
        totalDogs--;
    }

    // Accessor and Mutator methods
    string getBreed() const {
        return breed;
    }

    bool getIsTrained() const {
        return isTrained;
    }

    void setBreed(const string& newBreed) {
        breed = newBreed;
    }

    void setIsTrained(bool trained) {
        isTrained = trained;
    }

    void getDetails() const override {
        Pet::getDetails();
        cout << "Breed: " << getBreed() << endl;
        cout << "Trained: " << (getIsTrained() ? "Yes" : "No") << endl;
    }

    // Override the makeSound function for Dog
    void makeSound() const override {
        cout << "Dog says: Woof Woof!" << endl;
    }
};

// Initialize static variable
int Dog::totalDogs = 0;

// Cat Class (Hierarchical Inheritance: Inherits from Pet)
class Cat : public Pet {
private:
    string furColor;
    bool isIndependent;

public:
    static int totalCats;

    // Static member function
    static int getTotalCats() {
        return totalCats;
    }

    // Default Constructor
    Cat() : Pet(), furColor("Unknown"), isIndependent(false) {
        totalCats++;
    }

    // Parameterized Constructor
    Cat(string newName, int newAge, double newPrice, string newFurColor, bool independent)
        : Pet(newName, newAge, newPrice), furColor(newFurColor), isIndependent(independent) {
        totalCats++;
    }

    // Destructor
    ~Cat() {
        totalCats--;
    }

    // Accessor and Mutator methods
    string getFurColor() const {
        return furColor;
    }

    bool getIsIndependent() const {
        return isIndependent;
    }

    void setFurColor(const string& newColor) {
        furColor = newColor;
    }

    void setIsIndependent(bool independent) {
        isIndependent = independent;
    }

    void getDetails() const override {
        Pet::getDetails();
        cout << "Fur Color: " << getFurColor() << endl;
        cout << "Independent: " << (getIsIndependent() ? "Yes" : "No") << endl;
    }

    // Override the makeSound function for Cat
    void makeSound() const override {
        cout << "Cat says: Meow Meow!" << endl;
    }
};

// Initialize static variable
int Cat::totalCats = 0;

// Parrot Class (Multilevel Inheritance: Inherits from Pet through Bird)
class Parrot : public Pet {
private:
    bool canTalk;

public:
    static int totalParrots;

    // Static member function
    static int getTotalParrots() {
        return totalParrots;
    }

    // Default Constructor
    Parrot() : Pet(), canTalk(false) {
        totalParrots++;
    }

    // Parameterized Constructor
    Parrot(string newName, int newAge, double newPrice, bool talks)
        : Pet(newName, newAge, newPrice), canTalk(talks) {
        totalParrots++;
    }

    // Destructor
    ~Parrot() {
        totalParrots--;
    }

    // Accessor and Mutator methods
    bool getCanTalk() const {
        return canTalk;
    }

    void setCanTalk(bool talks) {
        canTalk = talks;
    }

    void getDetails() const override {
        Pet::getDetails();
        cout << "Can Talk: " << (getCanTalk() ? "Yes" : "No") << endl;
    }

    // Override the makeSound function for Parrot
    void makeSound() const override {
        cout << "Parrot says: Squawk! Hello!" << endl;
    }
};

// Initialize static variable
int Parrot::totalParrots = 0;

// Main function
int main() {
    Dog dog1("Buddy", 3, 300.0, "Golden Retriever", true);
    Cat cat1("Whiskers", 2, 150.0, "Brown", true);
    Parrot parrot1("Polly", 4, 120.0, true);

    // Display details and sounds for each pet
    dog1.getDetails();
    dog1.makeSound();
    
    cat1.getDetails();
    cat1.makeSound();
    
    parrot1.getDetails();
    parrot1.makeSound();

    // Displaying total counts
    cout << "\nTotal Pets: " << Pet::getTotalPets() << endl;
    cout << "Total Dogs: " << Dog::getTotalDogs() << endl;
    cout << "Total Cats: " << Cat::getTotalCats() << endl;
    cout << "Total Parrots: " << Parrot::getTotalParrots() << endl;

    return 0;
}
