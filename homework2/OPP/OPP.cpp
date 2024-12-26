#include <iostream>

using namespace std;

class Animal {
public:

	Animal() {}

	virtual void makeSound() = 0; //���� ���� �Լ�

	~Animal() {

	}
};

class Dog : public Animal {

	void makeSound() {
		cout << "����" << endl;
	}
};

class Cat : public Animal {

	void makeSound() {
		cout << "�߿�" << endl;
	}
};

class Cow : public Animal {

	void makeSound() {
		cout << "����" << endl;
	}
};

int main() {
	Animal* animalPtr[3];

	animalPtr[0] = new Dog();
	animalPtr[1] = new Cat();
	animalPtr[2] = new Cow();

	for (auto animal : animalPtr) {

		animal->makeSound();
		delete animal;
	}

	//delete[] animalPtr;


	return 0;
}