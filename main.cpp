#include <iostream>
#include <cstdlib>

#include "RubiksCube3.cpp"

using namespace std;

void initMenu()
{
    cout<<"Choose: \n1. New cube\n2. Solve cube\n3. Exit\n";
}

void menuDecision(int choice)
{
    switch(choice)
    {
    case 1:
        {
            RubiksCube3 myCube;
            myCube.initialiseCube();
            bool rv=myCube.isCubeSolved();
            if(rv){
                cout<<"Cube is already solved!";
            }
            else{
                cout<<"not solved yet";

            }
            break;
        }
    case 2:
        break;
    case 3:
        break;
    default:
        cout<<"Choose a value!";
    }
}

int main()
{
    int choice;

    do{
        system("cls");
        initMenu();
        cin>>choice;
        menuDecision(choice);

    }while(choice<1 || choice>3);

    return 0;
}
