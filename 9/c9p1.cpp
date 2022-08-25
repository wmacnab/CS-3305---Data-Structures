/*
Write a function that produces the following
output:
This was written by call number 1.
This was written by call number 2.
This was written by call number 3.
This was written by call number 4.
This ALSO written by call number 4.
This ALSO written by call number 3.
This ALSO written by call number 2.
This ALSO written by call number 1.
In this example, the recursion stopped when it
reached four levels deep, but your function should
be capable of continuing to any specified level.
*/
#include <iostream>

void recursive_print(int n, int count = 1)
{
    std::cout << "This was written by call number " << count << ".\n";
    if (count < n) recursive_print(n, count + 1);
    std::cout << "This ALSO written by call number " << count << ".\n";
}
void better_rp(int n)
{
    std::cout << "This was written by call number " << n << ".\n";
    if (n == 1) return;
    else
    {
        better_rp(n - 1);
    }
}
int main()
{
    recursive_print(4);
    return EXIT_SUCCESS;
}