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

int createSlayer()
{
    int x;

    x = rand () % 20;

    return x;
}

int main()
{
    system("Color 00");
    system("Color 0A");


    ifstream file;
    string line;

    file.open("doomguy.txt");

    while(getLine(file,line))
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



    cout << "******//WELCOME TO THE GAME SLAYER! WHAT SHOULD WE CALL YOU? :";

    cin >>slayerName;

    cout << "\n\nHow many demons you can take down" << slayerName << "?" << endl;

    cin >> amountOfDemons;


    cout <<"Game will be started in 5 seconds...." << endl;

    sleep(5);

    while(amountOfDemons!=0 && aliveSlayer)
    {
        int skilledDemon = createDemon();

        int skilledSlayer = createSlayer();

        if(skilledDemon <=5 )
        {
             ifstream file2;
             string line3;

             file2.open("normalzombie.txt");

             while(getLine(file2,line3))
               {
                 cout << line3 << endl;
               }

             file2.close();

             cout << "YOU HAVE ENCOUNTERED A ZOMBIE! GET READY!" << endl;

             sleep(3);


        }
        else if (skilledDemon >5 && skilledDemon <=15)
        {
            ifstream file3;
            string line4;

            file3.open("cacodemon.txt");

            while(getLine(file3,line4))
            {
                cout << line4 << endl;
            }

            file3.close();

            cout << "YOU HAVE ENCOUNTERED A CACODEMON! GET READY!" << endl;

            sleep(3);
        }
        else
        {
            ifstream file4;
            string line5;

            file4.open("marauder.txt");

            while(getLine(file4,line5))
            {
                cout << line5 << endl;
            }

            file4.close();

            cout << "YOU HAVE ENCOUNTERED A MARAUDER! GET READY AND START PRAYING TO YOUR GODS!" << endl;

            sleep(3);
        }


        if(skilledSlayer >= skilledDemon)
        {
            cout << "GOOD JOB SLAYER! HERE'S ANOTHER ONE...\n" << endl;

            slayerScore =*2;

            killedDemons++;

            amountOfDemons--;

            sleep(2);
        }
        else
        {
            cout << "YOU HAVE DIED SLAYER...TRY IT NEXT TIME...\n\n\n" << endl;

            aliveSlayer == false;

        }
    }

    cout <<"YOU FINISHED THE SIMULATION SLAYER! HERE'S YOUR SCORES : \n\n\n" <<endl;


    cout <<"Your total score :" << slayerScore <<endl;

    cout << "You killed " << killedDemons << "demons."<< endl;

//Currently program is not working because of cant recognizing the getLine command.

}
