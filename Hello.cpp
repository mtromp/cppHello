#include "HelloConfig.h"
#include "Greetings/Greetings.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    Greetings greetings;
    cout <<  greetings.hello() << endl;
    return 0;
}
