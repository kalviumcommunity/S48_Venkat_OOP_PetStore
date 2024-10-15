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

// Dog Class (Inherits from Pet)
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

// Cat Class (Inherits from Pet)
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

// Main function
int main() {
    int numDogs, numCats;

    // Ask for number of pets
    cout << "Enter the number of dogs: ";
    cin >> numDogs;

    cout << "Enter the number of cats: ";
    cin >> numCats;

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

    // Display Dog details
    cout << "\nDog Details:\n";
    for (int i = 0; i < numDogs; i++) {
        dogs[i].getDetails();
        cout << endl;
    }

    // Display Cat details
    cout << "Cat Details:\n";
    for (int i = 0; i < numCats; i++) {
        cats[i].getDetails();
        cout << endl;
    }

    // Total counts
    cout << "Total Pets: " << Pet::getTotalPets() << endl;
    cout << "Total Dogs: " << Dog::getTotalDogs() << endl;
    cout << "Total Cats: " << Cat::getTotalCats() << endl;

    // Free dynamically allocated memory
    delete[] dogs;
    delete[] cats;

    return 0;
}
