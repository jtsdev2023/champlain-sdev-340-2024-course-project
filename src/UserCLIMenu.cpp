// user-cli-menu.cpp


#include <string>
#include <variant>
#include <iostream>

// move this to the device class... good idea ?
// #include "ReadCSVFile.cpp"


#include "../include/Device.h"
#include "../include/TV.h"
#include "../include/Thermostat.h"
#include "../include/Lights.h"
#include "../include/SecuritySystem.h"

/*

- thinking about selections similar to:
    1. Selection 1 - power on and register smart devices which reads smart device CSV file
    2. Selection 2 - thermostat
    3. Selection 3 - TV
    4. Selection 4 - lighting
    5. Selection 5 - security system
    6. Quit

- if i have enough time maybe add some functionality to list devices and/or device info
- if i have enough time maybe make the CLI menu dynamic and generated by the devices
  read from the CSV file or something

- if i were doing this for real, i'd probably make use of IP multicast, wireless, or maybe
  bluetooth and attempt to register the smart devices with the controller if they had
  a valid license or something

- what about loading the smart devices on startup? seems like a good idea.

- can use c++ i/o file that contains latests device settings or defaults etc.

*/
void displayMenu();
void selection1();
void selection2();
void selection3();
void selection4();
void selection5();
void selection6();
void quit();

// need to decide where to put these functions
// i think the menu will call the classes ?
// then the classes will call these functions ?
// void getTVChannel();
// void getTVVolume();
// void getSecurityCode();
// void getThermostatTemp();
// void writeToCSVFile();


void menuRun()
{
    // wanted to let userSelection be of any type
    // this was super hard... so much easier in python
    // couldn't get it to work so just going with type int
    int userSelection = 0;
    int loopCounter = 0;

    while (true)
    {
        
        displayMenu();
        std::cin >> userSelection;

        loopCounter++;

        // i have a bug
        // if userSelection is not an int, it goes into an infinite loop
        // haven't been able to fix it yet
        // i think the problem is with "default"
        // i've tried adding logic to "default" that would fix it but not working
        if (loopCounter > 10)
        {
            std::cout << "Loop Counter Exceeded... Exiting..." << std::endl;
            return;
        }

        switch (userSelection)
        {
        case 1:
            selection1();
            break;
        case 2:
            selection2();
            break;
        case 3:
            selection3();
            break;
        case 4:
            selection4();
            break;
        case 5:
            selection5();
            break;
        case 6:
            selection6();
            return;
        default:
            std::cin.clear();
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Invalid Selection... Please Make a Different Selection or Enter Option \"6\" to Exit the Menu." << std::endl;
            std::cin >> userSelection;
        }

        // std::cout << std::endl;
        // std::cout << std::endl;
    }

}


// run menu
void displayMenu()
{
    std::cout << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "=          Main Menu          =" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << std::endl;
    std::cout << "1. Selection 1: Power on and register smart devices" << std::endl;
    std::cout << "2. Selection 2: Thermostat" << std::endl;
    std::cout << "3. Selection 3: TV" << std::endl;
    std::cout << "4. Selection 4: Lighting" << std::endl;
    std::cout << "5. Selection 5: Security system" << std::endl;
    std::cout << "6. Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Please Make a Selection: ";

}


// smart device functions
// void getTVChannel()
// {
//     std::cout << std::endl;
//     std::cout << "Enter TV Channel: ";
//     int tvChannel;
//     std::cin >> tvChannel;
//     std::cout << "TV Channel: " << tvChannel << std::endl;
// }


// selection 1 power on
void selection1()
{
    std::cout << std::endl;
    std::cout << "Selection 1: Power on and register smart devices";
    std::cout << std::endl << std::endl;
    // moved to device class
    // readCSVFile();
}

// selection 2 TV
void selection2()
{
    std::cout << std::endl;
    std::cout << "Selection 2: TV" << std::endl;
}

// selection 3 thermostat
void selection3()
{
    std::cout << std::endl;
    std::cout << "Selection 3: Thermostat" << std::endl;
}

// selection 4 lighting
void selection4()
{
    std::cout << std::endl;
    std::cout << "Selection 4: Lighting" << std::endl;
}

// selection 5 security system
void selection5()
{
    std::cout << std::endl;
    std::cout << "Selection 5: Security system" << std::endl;
}

// quit
void selection6()
{
    std::cout << std::endl;
    std::cout << "Quitting..." << std::endl;
    std::cout << std::endl;
}
