#include <iostream>
using namespace std;

class IntArray {
private:
    int* m_data;
    int m_len;

public:
    IntArray(int = 0, int = 0);
    ~IntArray();
    void print(void);
    // Copy constructor
    IntArray(const IntArray& copy);
    // Set function
    void set(int, int);
    
    // Friend functions
    friend void reverse(IntArray&);
    friend void multiply(IntArray&, int);
    friend void negative(IntArray&);
};

IntArray::IntArray(int size, int init) {
    if (size <= 0) {
        m_data = nullptr;
        m_len = 0;
    } else {
        m_data = new int[size];
        m_len = size;
        for (int i = 0; i < m_len; ++i) {
            *(m_data + i) = init;
        }
    }
}

IntArray::~IntArray() {
    delete[] m_data;
}

void IntArray::print() {
    for (int i = 0; i < m_len; ++i) {
        cout << *(m_data + i) << " ";
    }
    cout << std::endl;
}

IntArray::IntArray(const IntArray& copy) {
    m_len = copy.m_len;
    m_data = new int[m_len];
    for (int i = 0; i < m_len; ++i) {
        *(m_data + i) = *(copy.m_data + i); 
    }
}

void IntArray::set(int index, int value) {
    if (index >= 0 && index < m_len) {
        *(m_data + index) = value;
    }
}

void reverse(IntArray& arr) {
    for (int i = 0; i < arr.m_len / 2; ++i) {
        int temp = *(arr.m_data + i);
        *(arr.m_data + i) = *(arr.m_data + arr.m_len - i - 1);
        *(arr.m_data + arr.m_len - i - 1) = temp;
    }
}

void multiply(IntArray& arr, int factor) {
    for (int i = 0; i < arr.m_len; ++i) {
        *(arr.m_data + i) *= factor;
    }
}

void negative(IntArray& arr) {
    for (int i = 0; i < arr.m_len; ++i) {
        *(arr.m_data + i) *= -1;
    }
}

int main() {
    cout << "a1:"; 
    IntArray a1{10,100};
    a1.print();
    cout << "a2:";
    IntArray a2{a1};
    a2.set(3,999);
    a2.set(9,123);
    a2.print();
    cout << endl << "Exercice 2" << endl;

    IntArray a5{5,0};

    for(int idx = 0; idx < 5; ++idx)
        a5.set(idx,100+idx*50);
    cout<<"a5:     ";a5.print();
    reverse(a5);
    cout<<"reverse:     ";a5.print();
    multiply(a5,3);
    cout<<"multiply:        ";a5.print();
    negative(a5);
    cout<<"negative:       ";a5.print();
    return 0;
} 