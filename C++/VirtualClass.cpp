#include <iostream>
#include <string>
using namespace std;
class Animal {
  private:
    string species;
    int age;

  public:
    Animal(string species, int age) : species(species), age(age) {}
    virtual void eat(Animal *animal) {
        cout << this->species << " eats " << animal->species << endl;
    }

    virtual ~Animal() {}
};

class Human : public Animal {
  protected:
    string lastname;
    string firstname;
    string race;
    int age;
    int height;
    int gender; // 0 for female 1 for male
  public:
    Human(string lastname, string firstname, string race, int age, int height, int gender) : lastname(lastname), firstname(firstname), race(race), age(age), height(height), gender(gender), Animal("human", 0) {}

    virtual void printName() {
        cout << firstname << ' ' << lastname << endl;
    }

    virtual void relation(Human *human) {
        cout << firstname << ' ' << lastname << ':' << human->firstname << human->lastname << endl;
    }
    virtual ~Human() {}
};

class Teacher : public Human {
  private:
    int salary;
    string occupation;

  public:
    Teacher(string lastname, string firstname, string race, int age, int height, int gender, int salary, string occupation) : Human(firstname, lastname, race, age, height, gender), salary(salary), occupation(occupation) {}
    void printName() {
        cout << firstname << ' ' << lastname << ',' << "occupation: " << occupation << endl;
    }

    ~Teacher() {}
};

int main() {
    Human *Jose = new Human("Jose", "San", "Latin", 15, 182, 1);
    Human *John = new Teacher("John", "Doe", "Asian", 22, 174, 0, 10200, "Math Prof");
    Jose->relation(John);
    Jose->eat(John);
}