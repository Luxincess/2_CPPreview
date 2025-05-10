#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{
public:
    Computer(const char* brand,float price);
    Computer(const Computer &rhs);
    Computer &operator=(const Computer &rhs);
    void setBrand(const char *brand);
    void setPrice(float price);
    void print();
    ~Computer();

private:
    char *_brand;
    float _price;
};

#endif
