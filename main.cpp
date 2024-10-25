#include <iostream>
#include <string>

using namespace std;

// Pet Base Class
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

    virtual void getDetails() const {
        cout << "Pet Name: " << getName() << endl;
        cout << "Age: " << getAge() << " years" << endl;
        cout << "Price: $" << getPrice() << endl;
    }
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
};

// Initialize static variable
int Cat::totalCats = 0;

// Bird Class (New Class for Multilevel Inheritance)
class Bird : public Pet {
private:
    double wingSpan;

public:
    // Default Constructor
    Bird() : Pet(), wingSpan(0.0) {}

    // Parameterized Constructor
    Bird(string newName, int newAge, double newPrice, double newWingSpan)
        : Pet(newName, newAge, newPrice), wingSpan(newWingSpan) {}

    // Accessor and Mutator methods
    double getWingSpan() const {
        return wingSpan;
    }

    void setWingSpan(double newWingSpan) {
        wingSpan = newWingSpan;
    }

    void getDetails() const override {
        Pet::getDetails();
        cout << "Wing Span: " << getWingSpan() << " meters" << endl;
    }
};

// Parrot Class (Multilevel Inheritance: Inherits from Bird)
class Parrot : public Bird {
private:
    bool canTalk;

public:
    // Default Constructor
    Parrot() : Bird(), canTalk(false) {}

    // Parameterized Constructor
    Parrot(string newName, int newAge, double newPrice, double newWingSpan, bool talks)
        : Bird(newName, newAge, newPrice, newWingSpan), canTalk(talks) {}

    // Accessor and Mutator methods
    bool getCanTalk() const {
        return canTalk;
    }

    void setCanTalk(bool talks) {
        canTalk = talks;
    }

    void getDetails() const override {
        Bird::getDetails();
        cout << "Can Talk: " << (getCanTalk() ? "Yes" : "No") << endl;
    }
};

// Main function
int main() {
    int numDogs, numCats, numParrots;

    // Ask for number of pets
    cout << "Enter the number of dogs: ";
    cin >> numDogs;

    cout << "Enter the number of cats: ";
    cin >> numCats;

    cout << "Enter the number of parrots: ";
    cin >> numParrots;

    // Dynamically allocate an array of Dog objects
    Dog* dogs = new Dog[numDogs]; 
    
    // Input details for Dog objects using parameterized constructor
    for (int i = 0; i < numDogs; i++) {
        string name, breed;
        int age;
        double price;
        bool trained;

        cout << "Enter details for Dog " << i + 1 << ":" << endl;
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Price: "; cin >> price;
        cout << "Breed: "; cin >> breed;
        cout << "Trained (1 for Yes, 0 for No): "; cin >> trained;

        dogs[i] = Dog(name, age, price, breed, trained); // Using parameterized constructor
    }

    // Dynamically allocate an array of Cat objects
    Cat* cats = new Cat[numCats]; 
    
    // Input details for Cat objects using parameterized constructor
    for (int i = 0; i < numCats; i++) {
        string name, furColor;
        int age;
        double price;
        bool independent;

        cout << "Enter details for Cat " << i + 1 << ":" << endl;
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Price: "; cin >> price;
        cout << "Fur Color: "; cin >> furColor;
        cout << "Independent (1 for Yes, 0 for No): "; cin >> independent;

        cats[i] = Cat(name, age, price, furColor, independent); // Using parameterized constructor
    }

    // Dynamically allocate an array of Parrot objects
    Parrot* parrots = new Parrot[numParrots]; 
    
    // Input details for Parrot objects using parameterized constructor
    for (int i = 0; i < numParrots; i++) {
        string name;
        int age;
        double price, wingSpan;
        bool canTalk;

        cout << "Enter details for Parrot " << i + 1 << ":" << endl;
        cout << "Name: "; cin >> name;
        cout << "Age: "; cin >> age;
        cout << "Price: "; cin >> price;
        cout << "Wing Span (meters): "; cin >> wingSpan;
        cout << "Can Talk (1 for Yes, 0 for No): "; cin >> canTalk;

        parrots[i] = Parrot(name, age, price, wingSpan, canTalk); // Using parameterized constructor
    }

    // Output Dog details
    cout << "\nDetails of Dogs:" << endl;
    for (int i = 0; i < numDogs; i++) {
        dogs[i].getDetails();
        cout << endl;
    }

    // Output Cat details
    cout << "\nDetails of Cats:" << endl;
    for (int i = 0; i < numCats; i++) {
        cats[i].getDetails();
        cout << endl;
    }

    // Output Parrot details
    cout << "\nDetails of Parrots:" << endl;
    for (int i = 0; i < numParrots; i++) {
        parrots[i].getDetails();
        cout << endl;
    }

    // Free dynamically allocated memory
    delete[] dogs;
    delete[] cats;
    delete[] parrots;

    return 0;
}
