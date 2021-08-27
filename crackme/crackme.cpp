#include <iostream>
#include "xorstr.h"
#include "color.hpp"

using namespace std;


int main()
{
    //--//
    int a;
    srand(time(nullptr));
    string title = "";
    int n = 32;
    for (int i = 0; i < n; i++)
    {
        a = rand() % 2;
        if (a == 0)
            title += rand() % 26 + 'a';//generates letters
        else
            title += to_string(rand() % 10);//generates numbers
    }

    SetConsoleTitleA(title.c_str());
    //--//

    //Let define this string as password but it wont change anything cuz we're using xorstr
    const string password = xorstr("cGVyc2lzdGVuY2UgaXMgdGhlIHdheSB0byBzdWNjZXNz");
    string input;

    // Simple text
    cout << dye::aqua(xorstr("[!] ")) << xorstr("Hello, this is the simplest crackme i've done! Good luck!") << endl;

    // Password form
    cout << dye::yellow(xorstr("[?] ")) << xorstr("Please leave a password:\n") << endl;

    // Makes this more beautiful
    cout << dye::grey(xorstr("-<")) << endl;

    // Password string
    cin >> input;

    // Makes this more beautiful
    cout << dye::grey(xorstr("-<")) << endl;

    // Login system
    if (input == password) {
        cout << dye::green("\n[v] ") << "Congratulations you made it! (The code means: 'Persistence is the way to success')\n" << endl;
    }
    else {
        cout << dye::red("\n[x] ") << "Wrong one!\n" << endl;
    }

    system("pause");
}