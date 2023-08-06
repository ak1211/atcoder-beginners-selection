// ABC081A - Placing Marbles
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << std::count(s.begin(), s.end(), '1') << std::endl;
    return 0;
}
