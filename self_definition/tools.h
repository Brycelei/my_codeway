#include <string>
std::string myrepalace(std::string &str)
{
    for (auto &x : str)
    {
        if (x == '[')
            x = '{';
        if (x == ']')
            x = '}';
    }
    return str;
}