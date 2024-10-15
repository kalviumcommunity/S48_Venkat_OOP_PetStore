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
    // Static variable to count total number of pets (across all types)
    static int totalPets;

    // Static member function to get total number of pets
    static int getTotalPets() {
        return totalPets;
    }

    Pet() {
        totalPets++;
    }

    virtual ~Pet() {
        totalPets--;
    }

    // Accessor methods
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    double getPrice() const {
        return price;
    }

    // Mutator methods
    void setName(const string& newName) {
        name = newName;
    }

    void setAge(int newAge) {
        age = newAge;
    }

    void setPrice(double newPrice) {
        price = newPrice;
    }

    void getDetails() const {
        cout << "Pet Name: " << getName() << endl;
        cout << "Age: " << getAge() << " years" << endl;
        cout << "Price: $" << getPrice() << endl;
    }

    void inputDetails() {
        string inputName;
        int inputAge;
        double inputPrice;

        cout << "Enter Pet Name: ";
        cin >> inputName;
        setName(inputName);

        cout << "Enter Age: ";
        cin >> inputAge;
        setAge(inputAge);

        cout << "Enter Price: ";
        cin >> inputPrice;
        setPrice(inputPrice);
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
    // Static variable to count number of Dog objects created
    static int totalDogs;

    // Static member function to get total number of dogs
    static int getTotalDogs() {
        return totalDogs;
    }

    Dog() {
        totalDogs++;
    }

    ~Dog() {
        totalDogs--;
    }

    // Accessor methods
    string getBreed() const {
        return breed;
    }

    bool getIsTrained() const {
        return isTrained;
    }

    // Mutator methods
    void setBreed(const string& newBreed) {
        breed = newBreed;
    }

    void setIsTrained(bool trained) {
        isTrained = trained;
    }

    void getDetails() const {
        Pet::getDetails();
        cout << "Breed: " << getBreed() << endl;
        cout << "Trained: " << (getIsTrained() ? "Yes" : "No") << endl;
    }

    void inputDetails() {
        Pet::inputDetails();  // Get the base pet details

        string inputBreed;
        bool inputIsTrained;

        cout << "Enter Breed: ";
        cin >> inputBreed;
        setBreed(inputBreed);

        cout << "Is the dog trained? (1 for Yes, 0 for No): ";
        cin >> inputIsTrained;
        setIsTrained(inputIsTrained);
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
    // Static variable to count number of Cat objects created
    static int totalCats;

    // Static member function to get total number of cats
    static int getTotalCats() {
        return totalCats;
    }

    Cat() {
        totalCats++;
    }

    ~Cat() {
        totalCats--;
    }

    // Accessor methods
    string getFurColor() const {
        return furColor;
    }

    bool getIsIndependent() const {
        return isIndependent;
    }

    // Mutator methods
    void setFurColor(const string& newColor) {
        furColor = newColor;
    }

    void setIsIndependent(bool independent) {
        isIndependent = independent;
    }

    void getDetails() const {
        Pet::getDetails();
        cout << "Fur Color: " << getFurColor() << endl;
        cout << "Independent: " << (getIsIndependent() ? "Yes" : "No") << endl;
    }

    void inputDetails() {
        Pet::inputDetails();  // Get the base pet details

        string inputFurColor;
        bool inputIsIndependent;

        cout << "Enter Fur Color: ";
        cin >> inputFurColor;
        setFurColor(inputFurColor);

        cout << "Is the cat independent? (1 for Yes, 0 for No): ";
        cin >> inputIsIndependent;
        setIsIndependent(inputIsIndependent);
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

    // Display the total number of Dogs, Cats, and Pets using static member functions
    cout << "Total Pets: " << Pet::getTotalPets() << endl;
    cout << "Total Dogs: " << Dog::getTotalDogs() << endl;
    cout << "Total Cats: " << Cat::getTotalCats() << endl;

    return 0;
}
