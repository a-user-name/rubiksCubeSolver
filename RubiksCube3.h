#ifndef RUBIKSCUBE3_H
#define RUBIKSCUBE3_H

typedef char face[3][3];

class RubiksCube3
{
    public:
        RubiksCube3();

        void initialiseCube();      //
        void initialiseFront();     //
        void initialiseBack();      //
        void initialiseLeft();      //
        void initialiseRight();     //
        void initialiseTop();       //
        void initialiseBottom();    //

        bool edgeIsSolved(face);    //checks to see if any edges @param face is solved
        bool cornerIsSolved(face);  //checks to see if any corners @param face is solved
        bool isCubeSolved();        //returns true if cube is solved. false otherwise           //

        void f();                   //
        void b();                   //
        void l();                   //
        void r();                   //
        void u();                   //
        void d();                   //
        void fPrime();              //
        void bPrime();              //
        void lPrime();              //
        void rPrime();              //
        void uPrime();              //
        void dPrime();              //

        void outputFrontLayer();    //
        void outputBackLayer();     //
        void outputLeftLayer();     //
        void outputRightLayer();    //
        void outputTopLayer();      //
        void outputBottomLayer();   //

        void firstAlg();            //
        void leftAlg();             //
        void rightAlg();            //
        void topCrossAlg1();        //
        void topCrossAlg2();        //
        void topCornersAlg();       //

        void outputFirstLayer();
        void outputSecondLayer();
        void outputLastLayer();

        void displayCube();         //
        void outputFront();         //
        void outputBack();          //
        void outputLeft();          //
        void outputRight();         //
        void outputTop();           //
        void outputBottom();        //


    private:
        face top;
        face bottom;
        face right;
        face left;
        face front;
        face back;
};

#endif // RUBIKSCUBE3_H
