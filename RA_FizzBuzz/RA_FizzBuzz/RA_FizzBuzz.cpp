#include <iostream>
#include <ctype.h>
// #include <stdlib.h> (If we wanted to exit).

using namespace std;    //This can cause potential compile errors due to conflicts in definitions, but in this case it's fine. 

int main()
{
    int int_fizz = 3;   //Our fizz integer
    int int_buzz = 5;   //Our buzz integer

    int n = 100;    //Our maximum integer we'll be looping until. In this example, the user is not given the option to change it.

    int int_fizzcheck = 0;  //The integer we'll be checking against our fizz.
    int int_buzzcheck = 0;  //The integer we'll be checking against our buzz.

    cout << "Please enter your fizz number: ";  //OUTPUT: asking the user to enter a number.

    while (!(cin >> int_fizz)){ //While the input is not an integer. Note that inputs such as 3a or 3.5 can still be inputted.
        cin.clear();    //Clear the error flag on our console input so that future I/O operators will work correctly.
        cin.ignore(256,'\n');   //Discarding / skipping characters in the input stream until a newline character is read, to avoid another parse failure.
        cout << "Error, enter a number: ";  //OUTPUT: asking the user to enter another number.
    }

    cout << "Please enter your buzz number: ";  //Repeating the above validation for our buzz integer.

    while (!(cin >> int_buzz)) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Error, enter a number: ";
    }
    cout << endl << "-----OUTPUT START-----" << endl << endl;   //Just for decoration.

    for (int i = 1; i <= n; i++)    //While integer "i" (starting at 1) is less than our integer "n" (our maximum integer).
    {
        int_fizzcheck++;    //Incrementing our fizz and buzz check variables. These will respectively get set back 0 if fizz or buzz is found.
        int_buzzcheck++;

        string fb_str_container = "";   //A string to contain fizz and buzz, set to what we will use as empty (""(neither fizz nor buzz)).

        if (int_fizzcheck == int_fizz)  //Checking if our fizz check variable equals our user declared fizz integer.
        {
            fb_str_container += "Fizz"; //If the above is true, add "Fizz" to the fizz buzz string container.
            int_fizzcheck = 0;  //Set our fizz check back to zero.
        }

        if (int_buzzcheck == int_buzz)  //Repeating the above for Buzz.
        {
            fb_str_container += "Buzz";
            int_buzzcheck = 0;
        }

        if (fb_str_container == "") cout << i << endl;  //We'll check if the string is empty, and if so, output i (our current loop count).
        else cout << fb_str_container << "(" << i << ")" << endl;   //If not empty, output whatever combination of fizz and / or buzz.
    }

    cout << endl << "-----OUTPUT END-----" << endl << endl; //Just for decoration again.
    
    //At this point we can add a basic I/O asking the user if they wanted to repeat, calling main(); on yes, and exit(EXIT_SUCCESS) otherwise;
}

/* Note that non-trailing whitespace has been inlcuded for presentation purposes.
Whilst this might increase compile times, it shouldn't dramatically impact run speed. */ 

/* I have chosen not to use an approach that adopts the Modulo operator (%) as this is expensive. */

