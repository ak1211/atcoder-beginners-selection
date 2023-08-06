// ABC086A - Product
#include <iostream>

int main()
{
    long a, b;
    std::cin >> a >> b;
    std::cout << (a * b % 2 ? "Odd" : "Even") << std::endl;
    return 0;
}
