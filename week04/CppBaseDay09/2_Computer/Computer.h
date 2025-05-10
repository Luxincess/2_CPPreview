#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{
public:
    Computer(const char *brand, float price);
    Computer(const Computer &rhs);
    Computer &operator=(const Computer &rhs);
    void setBrand(const char *brand);
    void setPrice(float price);
    void print();
    void print() const;

    ~Computer();

    static void printTotalPrice();
private:
    char *_brand;
    float _price;
    static float _totalPrice;
};

#endif
