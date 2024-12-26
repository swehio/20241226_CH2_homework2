#include <iostream>

#include<cstdlib>
#include<ctime>

using namespace std;

class Animal {
public:

	Animal() {}

	virtual void makeSound() = 0; //���� ���� �Լ�

	~Animal() {

	}
};

class Dog : public Animal {
public:
	Dog(){
		cout << "\nDog visits our Zoo!" << endl;
	}

	void makeSound() {
		cout << "Dog barks: Woof! Woof!" << endl;
	}
};

class Cat : public Animal {
public:
	Cat() {
		cout << "\nCat visits our Zoo!" << endl;
	}

	void makeSound() {
		cout << "Cat meows: Meow! Meow!" << endl;
	}
};

class Cow : public Animal {
public:
	Cow() {
		cout << "\nCow visits our Zoo!" << endl;
	}

	void makeSound() {
		cout << "Cow moos: Moo~~" << endl;
	}
};

class Zoo {
private:
	Animal* animals[10];
	int animalCount = 0;

public:
	Zoo() {
		cout << "Welcome to the Zoo!" << endl;
	}

	void addAnimal(Animal* animal) {
		if (animalCount >= 10) {
			cout << "Sorry but Zoo is full!";
			return;
		}
		cout << "New friend joins!" << endl;
		animals[animalCount] = animal;
		animalCount++;

	}

	void performAction() {
		cout << "\nAll animals make sound!" << endl;
		for (int i = 0; i<animalCount; i++)
		{
			animals[i]->makeSound();
		}
	}

	~Zoo() {
		cout << "See you Again!" << endl;
		for (int i = 0; i < animalCount; i++)
		{
			delete animals[i]; 
		}
		//delete[] animals
		//�迭 �޸� ���� �õ��ߴ��� �ߴ��� ����� ����Ǿ��ٴ� ���� �߻�
	}
};

Animal* createRandomAnimal() {
	Animal* randomAnimal;
	int randNum;
	int animalType =3;

	srand(time(NULL));
	randNum = rand() % animalType;

	if (randNum == 0)
		randomAnimal = new Dog();
	else if (randNum == 1)
		randomAnimal = new Cat();
	else
		randomAnimal = new Cow();

	return randomAnimal;
}

void Input(int &input) {
	cout << "\n�ൿ�� �Է����ּ���.\n1 : Add animal\n2 : make animals sound\n3 :Quit\n>�Է� :";
	cin >> input;
}



int main() {
	cout << "�ʼ� ��� ����" << endl;
	Animal* animalPtr[3];

	animalPtr[0] = new Dog();
	animalPtr[1] = new Cat();
	animalPtr[2] = new Cow();

	for (auto animal : animalPtr) {

		animal->makeSound();
		delete animal;
	}

	cout << "\n���� ��� ����" << endl;
	Zoo* zoo1 = new Zoo();
	int input = 0;

	while (true) {
		Input(input);

		if (input == 1)
			zoo1->addAnimal(createRandomAnimal());
		else if (input == 2)
			zoo1->performAction();
		else if (input == 3)
			break;
		else
			cout << "�߸��� �Է��Դϴ�." << endl;
	}

	delete zoo1;

	return 0;
}