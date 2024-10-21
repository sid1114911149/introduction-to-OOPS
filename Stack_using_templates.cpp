#include <iostream>
#include <vector>
#include <complex>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    void pop() {
        if (!isEmpty()) {
            elements.pop_back();
        } else {
            cerr << "Stack is empty, cannot pop." << endl;
        }
    }

    T top() const {
        if (!isEmpty()) {
            return elements.back();
        } else {
            throw out_of_range("Stack is empty.");
        }
    }

    bool isEmpty() const {
        return elements.empty();
    }
    void display(){
        if(!elements.empty()){
            for(int i=0;i<elements.size();i++){
                cout<<elements[i]<<" ";
            }
            cout<<"\n";
        }
    }
    size_t size() const {
        return elements.size();
    }
};

// Student Record Structure
struct Student {
    string name;
    string rollNo;
    int year;
    char gender;
    float cgpa;
    string regnNo;

    void display() const {
        cout << "Name: " << name 
             << ", Roll No: " << rollNo 
             << ", Year: " << year 
             << ", Gender: " << gender 
             << ", CGPA: " << cgpa 
             << ", Regn No: " << regnNo << endl;
    }
};

int main() {
    // Stack of integers
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    cout<<"integer stack is:";
    intStack.display();
    cout << "Top of intStack: " << intStack.top() << endl;
    intStack.pop();
    // Stack of characters
    Stack<char> charStack;
    charStack.push('A');
    charStack.push('B');
    cout<<"character stack is:";
    charStack.display();
    cout << "Top of charStack: " << charStack.top() << endl;
    charStack.pop();

    // Stack of floats
    Stack<float> floatStack;
    floatStack.push(3.14f);
    floatStack.push(2.71f);
    cout<<"float stack is: ";
    floatStack.display();
    cout << "Top of floatStack: " << floatStack.top() << endl;
    floatStack.pop();

    // Stack of complex numbers
    Stack<complex<float>> complexStack;
    complexStack.push(complex<float>(1.0f, 2.0f));
    complexStack.push(complex<float>(3.0f, 4.0f));
    cout<<"complex stack is:";
    complexStack.display();
    cout << "Top of complexStack: " << complexStack.top() << endl;
    complexStack.pop();

    // Stack of student records
    Stack<Student> studentStack;
    Student student1 = {"SIDDARDHA", "123", 2, 'M', 8.5f, "23CS8005"};
    Student student2 = {"RAJESH", "456", 3, 'F', 9.8f, "23CS8008"};
    
    studentStack.push(student1);
    studentStack.push(student2);
    cout<<"student stack is: ";
    studentStack.top().display();
    studentStack.pop();
    studentStack.top().display();
    return 0;
}
	

