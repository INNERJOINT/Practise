//
//  Useless.cpp
//  CXX11
//
//  Created by Yukun on 2021/9/11.
//

#include "Useless.hpp"

int Useless::ct = 0;

Useless::Useless()
{
    ++ct;
    n = 0;
    pc = nullptr;
    std::cout << "default constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}

Useless::Useless(int k) : n(k)
{
    ++ct;
    pc = new char[n];
    std::cout << "int constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}

Useless::Useless(int k, char ch) : n(k)
{
    ++ct;
    std::cout << "int, char constructor called; number of objects: " << ct << std::endl;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = ch;
    }
    ShowObject();
}

Useless::Useless(const Useless & f) : n(f.n)
{
    ++ct;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = f.pc[i];
    }
    std::cout << "copy constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}

Useless::Useless(Useless && f) : n(f.n)
{
    ++ct;
    pc = f.pc;
    f.pc = nullptr;
    f.n = 0;
    std::cout << "move constructor called; number of objects: " << ct << std::endl;
    ShowObject();
}

Useless::~Useless()
{
    std::cout << " destructor called; number of objects: " << --ct << std::endl;
    std::cout << "delete object:\n";
    ShowObject();
    delete [] pc;
}

Useless Useless::operator+(const Useless &f) const
{
    std::cout << "Enter operator+()\n";
    Useless temp = Useless(n + f.n);
    for (int i = 0; i < n; i++) {
        temp.pc[i] = pc[i];
    }
    for (int i = n; i < temp.n; i++) {
        temp.pc[i] = f.pc[i - n];
    }
    std::cout << "temp Object:\n";
    std::cout << "Leaving operator+()\n";
    return temp;
}

Useless & Useless::operator=(const Useless &f)
{
    std::cout << "copy assignment operator called.\n";
    if(this == &f) return *this;
    delete [] pc;
    n = f.n;
    pc = new char[n];
    for (int i = 0; i < n; i++) {
        pc[i] = f.pc[i];
    }
    return *this;
}

Useless & Useless::operator=(Useless &&f)
{
    std::cout << "move assignment operator called.\n";
    if(this == &f) return *this;
    delete [] pc;
    n = f.n;
    pc = f.pc;
    f.pc = nullptr;
    return *this;
}

void Useless::ShowObject() const
{
    std::cout << "Number of elements: " << n;
    std::cout << " Data Addr: " << (void *) pc << std::endl;
}

void Useless::ShowData() const
{
    if (n == 0) std::cout << "(object empty)\n";
    else{
        for (int i = 0; i < n; i++) {
            std::cout << pc[i];
        }
        std::cout << "\n";
    }
}
