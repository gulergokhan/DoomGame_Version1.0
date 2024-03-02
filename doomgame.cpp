#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <fstream>



using namespace std;

int createDemon()
{
    int x;

    x = rand() % 20;

    return x;
}

int main()
{
    system("Color 00");
    system("Color 0A");

    ifstream file;

    string line;

    file.open("doomguy.txt");

    while(getline(file,line))
        {
            cout << line << endl;
        }

     file.close();

    srand(time(NULL));

    string slayerName;

    int slayerScore = 1;

    int killedDemons = 0;

    int amountOfDemons;

    bool aliveSlayer = true;

    int skilledSlayer = 12;



    cout << "******//WELCOME TO THE GAME SLAYER! WHAT SHOULD WE CALL YOU?\\****** : ";

    cin >> slayerName;

    cout << "\n\nHow many demons you can take down " << slayerName << "?";

    cin >> amountOfDemons;


    cout <<"Game will be started in 5 seconds...." << endl;

    sleep(5);

    while(amountOfDemons!=0 && aliveSlayer == true)
    {
        int skilledDemon = createDemon();


        if(skilledDemon > skilledSlayer)
        {
            cout << "You died Slayer...Try it next time." << endl;
            

            aliveSlayer = false;

        }
        else
        {
          if(skilledDemon <= 5)
          {
              file.open("zombie.txt");

              while(getline(file,line))
              {
                  cout << line << endl;
              }

              file.close();

              cout << "You have encountered with a zombie! Prepare for a fight!" << endl;

              sleep(2);
          }

          else if(skilledDemon > 5 && skilledDemon <=15)
          {
              file.open("cacodemon.txt");

              while(getline(file,line))
              {
                  cout << line << endl;
              }

              file.close();

              cout << "You have encountered with a cacodemon! Prepare for a fight!" << endl;

              sleep(2);

          }
          else
          {
              file.open("marauder.txt");

              while(getline(file,line))
              {
                  cout << line << endl;
              }

              file.close();

              cout << "You have encountered with a marauder...Good luck with that..."<< endl;

              sleep(2);
          }

          slayerScore = slayerScore * 2;

          killedDemons++;

          amountOfDemons--;

        }
    }


        cout << "The game has just ended " << slayerName << "!|\n\n";

        cout << "Here's your stats :\n" << endl;


        cout << "Score : " << slayerScore << endl;

        cout << "Killed Zombies : " << killedDemons << endl;

        return(0);

    }
