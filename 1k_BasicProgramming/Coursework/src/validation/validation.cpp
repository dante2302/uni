#include <string>
#include <vector>
#include <iostream>
#include <functional>

bool custom_stoi(const std::string &str, int &out)
{
    if (str.empty()) return false;
    size_t start = str[0] == '-' || str[0] == '+' ? 1 : 0;

    // reject strings with redundant leading zeros - eg. -00 
    if (str[start] == '0' && str.size() > start + 1)
        return false;

    try
    {
        // default stoi handles chars - eg. 123asd
        out = std::stoi(str);
        return true;
    }
    catch (const std::invalid_argument &)
    {
        return false;
    }
    catch (const std::out_of_range &)
    {
        return false;
    }
}

int get_validated_int(
    const std::string& invalidMessage, 

    // Lambda function optional parameter for additional validation
    std::function<bool(int)> isValid 
) 
{
    std::string input;
    int choice;
    bool isValidNumeric = false;
    bool afterFirst = false;

    do {
        if (afterFirst)
            std::cout << invalidMessage;
        else
            afterFirst = true;

        std::getline(std::cin, input);

        isValidNumeric = custom_stoi(input, choice);

        std::cin.clear();
    } while (!isValidNumeric || !isValid(choice));

    return choice;
}