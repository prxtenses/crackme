#include <iostream>
#include "xorstr.h"
#include "color.hpp"

using namespace std;

int main()
{
    //-- Randomize Title --//
    int a;
    srand(time(nullptr));
    string title = "";
    int n = 32;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 2;
        if (a == 0)
            title += rand() % 26 + 'a';
        else
            title += to_string(rand() % 10);
    }

    SetConsoleTitleA(title.c_str());
    //-- Randomize Title --//

    // Password / 3
    const string form1 = xorstr("7b974f276d811671fb28b");
    const string form2 = xorstr("76820fd8f22164e7154ec");
    const string form3 = xorstr("1a02f0ba9c9920ecb7e74");

    // We organize all forms into 1
    const string password = form1 + form2 + form3;

    // Define input
    string input;

    // Simple text
    cout << dye::aqua(xorstr("[!] ")) << xorstr("Hello, this is the simplest crackme i've done! Good luck! - Sonka") << endl;

    // Password form
    cout << dye::yellow(xorstr("[-] ")) << xorstr("Please leave a password:\n") << endl;

    // Makes this more beautiful
    cout << dye::grey(xorstr("-<")) << endl;

    // Password string
    cin >> input;

    // Makes this more beautiful
    cout << dye::grey(xorstr("-<")) << endl;

    // Login system
    if (input == password) {
        cout << dye::green(xorstr("\n[v] ")) << xorstr("Congratulations you made it! (The code means: 'Persistence is the way to success')\n") << endl;
    }
    else {
        cout << dye::red(xorstr("\n[x] ")) << xorstr("Wrong one!\n") << endl;
    }

    // Pause
    system("pause");
}