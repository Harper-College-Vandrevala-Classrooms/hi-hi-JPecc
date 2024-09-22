#include <iostream>
#include <string>

int main(void)
{
    const char *s = "hello";
    std::cout << strcmp(s, "bello");
    return 0;
}