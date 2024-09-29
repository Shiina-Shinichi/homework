#include <iostream>
#include <cstring>

class Chicken {
private:
    int age;
    char *name;

public:
    // Default constructor
    Chicken() : age(0), name(nullptr) {}

    // Parameterized constructor with age
    Chicken(int _age) : age(_age), name(nullptr) {}

    // Parameterized constructor with age and name
    Chicken(int _age, const char *_name) : age(_age), name(nullptr) {
        setName(_name); // Use setName to avoid code duplication
    }

    // Copy constructor
    Chicken(const Chicken &other) : age(other.age), name(nullptr) {
        if (other.name) {
            setName(other.name); // Use setName to avoid code duplication
        }
    }

    // Copy assignment operator
    Chicken &operator=(const Chicken &other) {
        if (this != &other) {
            setAge(other.age); // Use setAge for consistency
            setName(other.name); // Use setName to avoid code duplication
        }
        return *this;
    }

    // Destructor
    ~Chicken() {
        delete[] name;
    }

    // Method to set age
    void setAge(int _age) {
        age = _age;
    }

    // Method to set name
    void setName(const char *_name) {
        if (_name && name && std::strcmp(_name, name) == 0) {
            // If the new name is the same as the current name, do nothing
            return;
        }
        delete[] name; // Release existing resources
        if (_name) {
            int len = strlen(_name) + 1;
            name = new char[len];
            std::strcpy(name, _name);
        } else {
            name = nullptr;
        }
    }

    // Method to get name
    const char *getName() const {
        return name ? name : "";
    }

    // Method to get age
    int getAge() const {
        return age;
    }
};

int main() {
    // Lambda function for printing a Chicken's details
    auto print = [](const Chicken &c) {
        std::cout << "Hi, everyone! My name is " << c.getName()
                  << ", I am " << c.getAge() << " years old." << std::endl;
    };

    Chicken c(24, "Kunkun");
    print(c);

    Chicken d;
    d = c; // Test copy assignment operator
    print(d);

    Chicken a = c; // Test copy constructor
    print(a);

    c.setName("Xukun Cai"); // Change original object's name
    print(c); // Print changed object
    print(a); // Test deep copy by copy constructor
    print(d); // Test deep copy by copy assignment

    Chicken b;
    b = d = c; // Test chained copy assignment
    print(b);
    print(d);

    return 0;
}