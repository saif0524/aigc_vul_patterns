#include <iostream>
#include <vector>
#include <string>

int main()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::vector<std::string> parts;
    std::string temp = "";
    int ones = 0, zeros = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            zeros++;
            temp += '0';
        }
        else
        {
            ones++;
            temp += '1';
        }

        if (ones != zeros)
        {
            if (i == n - 1)
            {
                parts.push_back(temp);
            }
        }
        else
        {
            parts.push_back(temp);
            temp = "";
            ones = 0;
            zeros = 0;
        }
    }

    std::cout << parts.size() << std::endl;
    for (const auto &part : parts)
    {
        std::cout << part << " ";
    }
    return 0;
}