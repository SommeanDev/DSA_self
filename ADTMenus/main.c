#include<stdio.h>
#include "ADTMenus.h"
#include "Stacks.h"

int main(int argc, char const *argv[])
{
    Stack stack;
    menu_stack(&stack);
    sayHi();
    return 0;
}
