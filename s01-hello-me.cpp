#include <iostream>
#include <string>

auto main() -> int
{
    auto const name = std::string{argv[1]};
    std::cout<<"Hello" + name + "!\n";
    return 0;

}
