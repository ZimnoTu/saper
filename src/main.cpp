#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include "game.h"
#include "menu.h"
#include <chrono>
#include <time.h>

int timer()
{
   int time = 0;
   for(int i = 11; i<22; ++i)
   {
       std::cout << i <<"\t";
    std::this_thread::sleep_for (std::chrono::seconds(1));
   }
   return ++time;
}
void petla()
{
    std::cout << "countdown:\n";
     for (int i=10; i>0; --i) {
       std::cout << i << std::endl;
       std::this_thread::sleep_for (std::chrono::seconds(1));
     }
     std::cout << "Lift off!\n";
}


int main()
{
    srand(time(0));

    Menu menu;

    //std::thread t1 ([&]{menu.probaWywolaniaWatku();});
    /*lstd::thread t1 (petla);
    t1.join();
    */
    menu.displayMenu();
   /* std::thread t2 (timer);
    std::thread t3 (petla);
    t2.join();
    t3.join();*/



    return 0;
}
