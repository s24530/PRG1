#include <iostream>
#include <string>

auto ask_user_for_intiger(std::string prompt) -> int
{
    std:cout<<prompt<< " int:";
    auto n =  std::string{};
    std::getline(std::cin, n);
}

auto main() -> int
{
    auto const a = ask_user_for_intiger("a =  ");
    auto const a = ask_user_for_intiger("b =  ");
    std::cout<<(a*b)<<"\n";
    return 0;

}
