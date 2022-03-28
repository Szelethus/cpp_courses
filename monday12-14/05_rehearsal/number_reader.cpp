#include <iostream>
#include <vector>
#include <cmath>
#include <cerrno>
#include <fstream>
#include <cstring> 

std::vector<int> readNumbers(std::istream& stream);
void writeResult(std::ostream& stream, const std::vector<int>& numbers);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::vector<int> inVector = readNumbers(std::cin);
        writeResult(std::cout, inVector);
    }
    else
    {
        std::ifstream input(argv[1]);
        if (!input)
        {
            std::setlocale(LC_MESSAGES, "hu_HU.UTF8");
            std::cerr << argv[1] << ": " << std::strerror(errno) << '\n';
            return 1;
        }
        else
        {
            std::vector<int> inVector = readNumbers(input);
            std::ofstream output("output.txt");
            if (!output)
            {
                std::setlocale(LC_MESSAGES, "hu_HU.UTF8");
                std::cerr << argv[1] << ": " << std::strerror(errno) << '\n';
                return 2;
            }
            else
            {
                writeResult(output, inVector);
            }
        }
    }

    return 0;
}

std::vector<int> readNumbers(std::istream& stream)
{
    std::vector<int> numbers;
    int current;
    while (stream >> current)
    {
        numbers.push_back(current);
    }

    return numbers;
}

void writeResult(std::ostream& stream, const std::vector<int>& numbers)
{
    stream << "Raising all numbers to the 3rd power:" << std::endl;

    for (size_t i = 0; i < numbers.size(); ++i)
    {
        stream << std::pow(numbers.at(i), 3) << std::endl;
    }
}
