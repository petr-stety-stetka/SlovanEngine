#include <iostream>
#include "../../../Game/PC/Main.h"

using namespace std;

/**
 * Main method engine.
 */
int main(int argc, char *argv[])
{
    vector<string> sArgv;
    for(int i = 0; i < argc; i++)
        sArgv.push_back(argv[i]);

    Main main;
    main.main(argc, sArgv);
    return 0;
}