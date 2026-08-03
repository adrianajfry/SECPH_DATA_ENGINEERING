#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

class Vector {
private:
    int* items;
    int size;

public:
    
    Vector() : items(NULL), size(0) {}

    
    Vector(int size) : size(size) {
        items = new int[size]();
    }


    Vector(int size, int* items) : size(size) {
        this->items = new int[size];
        for (int i = 0; i < size; ++i) {
            this->items[i] = items[i];
        }
    }


    Vector(const std::string& str) {
        size = str.size();
        items = new int[size];
        for (int i = 0; i < size; ++i) {
            items[i] = str[i] - '0';
        }
    }

    
    Vector(const Vector& other) : size(other.size) {
        items = new int[size];
        for (int i = 0; i < size; ++i) {
            items[i] = other.items[i];
        }
    }

    
    ~Vector() {
        delete[] items;
    }

    
    operator int() const {
        return size;
    }

    
    operator double() const {
        double sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += items[i] * items[i];
        }
        return std::sqrt(sum);
    }

    
    operator std::string() const {
        std::ostringstream oss;
        for (int i = 0; i < size; ++i) {
            if (i > 0) oss << ",";
            oss << items[i];
        }
        return oss.str();
    }

    
    Vector operator*(int value) const {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result.items[i] = items[i] * value;
        }
        return result;
    }

    
    Vector operator+(const Vector& other) const {
        int newSize = std::max(size, other.size);
        Vector result(newSize);
        for (int i = 0; i < newSize; ++i) {
            result.items[i] = (i < size ? items[i] : 0) + (i < other.size ? other.items[i] : 0);
        }
        return result;
    }

    
    Vector operator+(int value) const {
        Vector result(size + 1);
        for (int i = 0; i < size; ++i) {
            result.items[i] = items[i];
        }
        result.items[size] = value;
        return result;
    }

    
    int& operator[](int index) {
        return items[index];
    }

    
    bool operator==(const Vector& other) const {
        if (size != other.size) return false;
        for (int i = 0; i < size; ++i) {
            if (items[i] != other.items[i]) return false;
        }
        return true;
    }

    
    bool operator>(const Vector& other) const {
        return double(*this) > double(other);
    }

    
    friend void printVector(const std::string& title, const Vector& v);

};


void printVector(const std::string& title, const Vector& v) {
    std::cout << title << ": ((" << std::string(v) << "), s: " << int(v) << ", m: " << double(v) << ")\n";
}

int main() {
    
    int itemsA[] = {6, 7, 8, 9};
    
    Vector a(4, itemsA); 
    Vector b("678"); 
    Vector c(b);
    Vector* d = new Vector(b);
    Vector e = *d + 1;
    Vector f = e * 2;
    Vector g = a + e;

    
    printVector("a", a);
    printVector("b", b);
    printVector("c", c);
    printVector("d", *d);
    printVector("e", e);
    printVector("f", f);
    printVector("g", g);

    
    std::cout << "a is " << (a == b ? "equivalent to" : "not equivalent to") << " b\n";

    
    std::cout << "e is " << (e > a ? "greater than" : "not greater than") << " a\n";

    
    delete d;

    return 0;
}
