#include <iostream>
#include "bulls.h"

int main()
{
    std::setlocale(LC_ALL, "Russian");
    std::string secret = generateSecret();
    playGuessing(secret);

    char again = 'n';
    std::cout << "ׁûדנאעü וש¸ נאח? (y/n): ";
    std::cin >> again;

    if (again == 'y' || again == 'Y')
    {

        do {
            secret = generateSecret();
            playGuessing(secret);
            std::cout << "ׁûדנאעü וש¸ נאח? (y/n): ";
            std::cin >> again;
        } while (again == 'y' || again == 'Y');
    }

    return 0;
}
