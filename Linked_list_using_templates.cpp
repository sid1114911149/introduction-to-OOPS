#include <iostream>
#include <string>
#include <complex>

using namespace std;

// Node class template
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

// Linked List class template
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        Node<T>* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node<T>* current = head;
        while (current) {
            Node<T>* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Student record struct
struct Student {
    string name;
    string rollNo;
    int year;
    char gender;
    float cgpa;
    string regnNo;

    // Overloading the << operator for easy display
    friend ostream& operator<<(ostream& os, const Student& student) {
        os << "Name: " << student.name << ", Roll No: " << student.rollNo
           << ", Year: " << student.year << ", Gender: " << student.gender
           << ", CGPA: " << student.cgpa << ", Regn No: " << student.regnNo<<"\n";
        return os;
    }
};

int main() {
    // Integer linked list
    LinkedList<int> intList;
    intList.append(1);
    intList.append(2);
    intList.append(3);
    cout << "Integer Linked List: ";
    intList.display();

    // Character linked list
    LinkedList<char> charList;
    charList.append('a');
    charList.append('b');
    charList.append('c');
    cout << "Character Linked List: ";
    charList.display();

    // Float linked list
    LinkedList<float> floatList;
    floatList.append(1.1f);
    floatList.append(2.2f);
    floatList.append(3.3f);
    cout << "Float Linked List: ";
    floatList.display();

    // Complex number linked list
    LinkedList<complex<float>> complexList;
    complexList.append(complex<float>(1.0f, 2.0f));
    complexList.append(complex<float>(3.0f, 4.0f));
    complexList.append(complex<float>(5.0f, 6.0f));
    cout << "Complex Number Linked List: ";
    complexList.display();

    // Student record linked list
    LinkedList<Student> studentList;
    studentList.append({"siddardha", "101", 2, 'M', 8.5f, "23CS8005"});
    studentList.append({"RAJESH", "102", 3, 'M', 9.8f, "23CS8008"});
    studentList.append({"SURYA", "103", 1, 'F', 7.2f, "23CS8077"});
    cout << "Student Record Linked List: " << endl;
    studentList.display();
    return 0;
}
	

