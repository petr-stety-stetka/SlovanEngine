#include <iostream>
#include "../../../MyGame/PC/Main.h"

using namespace std;

/**
 * Main method engine.
 */
int main(int argc, char *argv[])
{
    string sArgv[argc];
    for(int i = 0; i < argc; i++)
        sArgv[i] = argv[i];

    Main main;
    main.main(argc, sArgv);
    return 0;
}