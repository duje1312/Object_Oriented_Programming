#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>

class container {
private:
    int* niz;     
    int fiz;      
    int kapacitet; 

public:
   
     container(int initial_capacity = 0);

    
    container(const container& other);


    container(container&& other) noexcept;

    
    ~container();

    
    void push_back(int x);
    int size() const;
    int capacity() const;
    int at(int index) const;
    void clear();
};

#endif
