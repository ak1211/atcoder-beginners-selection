// ABC049C - Daydream
#include <iostream>
#include <string>
#include <string_view>

bool walk(std::string_view s, std::size_t offset)
{
    static std::string_view words[] = {"dream", "dreamer", "erase", "eraser"};

    if (s.length() == offset)
        return true;
    else if (s.length() < offset)
        return false;
    else
    {
        for (auto w : words)
        {
            const auto len = w.length();
            if (w.compare(0, len, s, offset, len) == 0)
            {
                if (walk(s, offset + len))
                {
                    return true;
                }
            }
        }
        return false;
    }
}

bool solver(std::string_view s)
{
    return walk(s, 0);
}

int main()
{
    std::string s;
    std::cin >> s;
    std::cout << (solver(s) ? "YES" : "NO") << std::endl;
    return 0;
}
