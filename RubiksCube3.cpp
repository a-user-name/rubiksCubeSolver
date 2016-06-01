#include "RubiksCube3.h"
#include <iostream>
#include <iomanip>

using namespace std;

typedef char face[3][3];     //matrix2D

RubiksCube3::RubiksCube3()
{

}

void RubiksCube3::initialiseCube()
{
    initialiseFront();
    initialiseBack();
    initialiseLeft();
    initialiseRight();
    initialiseTop();
    initialiseBottom();
}

void RubiksCube3::initialiseFront()
{
    cout<<"Enter in colors of front face\n";

    cin>>front[0][0];
    cin>>front[0][1];
    cin>>front[0][2];
    cin>>front[1][0];
    cin>>front[1][1];
    cin>>front[1][2];
    cin>>front[2][0];
    cin>>front[2][1];
    cin>>front[2][2];
    cout<<endl;
}

void RubiksCube3::initialiseBack()
{
    cout<<"Enter in colors of back face\n";

    cin>>back[0][0];
    cin>>back[0][1];
    cin>>back[0][2];
    cin>>back[1][0];
    cin>>back[1][1];
    cin>>back[1][2];
    cin>>back[2][0];
    cin>>back[2][1];
    cin>>back[2][2];
    cout<<endl;
}

void RubiksCube3::initialiseLeft()
{
    cout<<"Enter in colors of left face\n";

    cin>>left[0][0];
    cin>>left[0][1];
    cin>>left[0][2];
    cin>>left[1][0];
    cin>>left[1][1];
    cin>>left[1][2];
    cin>>left[2][0];
    cin>>left[2][1];
    cin>>left[2][2];
    cout<<endl;
}

void RubiksCube3::initialiseRight()
{
    cout<<"Enter in colors of right face\n";

    cin>>right[0][0];
    cin>>right[0][1];
    cin>>right[0][2];
    cin>>right[1][0];
    cin>>right[1][1];
    cin>>right[1][2];
    cin>>right[2][0];
    cin>>right[2][1];
    cin>>right[2][2];
    cout<<endl;
}

void RubiksCube3::initialiseTop()
{
    cout<<"Enter in colors of top face\n";

    cin>>top[0][0];
    cin>>top[0][1];
    cin>>top[0][2];
    cin>>top[1][0];
    cin>>top[1][1];
    cin>>top[1][2];
    cin>>top[2][0];
    cin>>top[2][1];
    cin>>top[2][2];
    cout<<endl;
}

void RubiksCube3::initialiseBottom()
{
    cout<<"Enter in colors of bottom face\n";

    cin>>bottom[0][0];
    cin>>bottom[0][1];
    cin>>bottom[0][2];
    cin>>bottom[1][0];
    cin>>bottom[1][1];
    cin>>bottom[1][2];
    cin>>bottom[2][0];
    cin>>bottom[2][1];
    cin>>bottom[2][2];
    cout<<endl;
}

bool RubiksCube3::isCubeSolved()
{
    if((front[0][0]==front[1][1]
       && front[0][1]==front[1][1]
       && front[0][2]==front[1][1]
       && front[1][0]==front[1][1]
       && front[1][2]==front[1][1]
       && front[2][0]==front[1][1]
       && front[2][1]==front[1][1]
       && front[2][2]==front[1][1]) &&
       (back[0][0]==back[1][1]
        && back[0][1]==back[1][1]
        && back[0][2]==back[1][1]
        && back[1][0]==back[1][1]
        && back[1][2]==back[1][1]
        && back[2][0]==back[1][1]
        && back[2][1]==back[1][1]
        && back[2][2]==back[1][1]) &&
       (left[0][0]==left[1][1]
        && left[0][1]==left[1][1]
        && left[0][2]==left[1][1]
        && left[1][0]==left[1][1]
        && left[1][2]==left[1][1]
        && left[2][0]==left[1][1]
        && left[2][1]==left[1][1]
        && left[2][2]==left[1][1]) &&
       (right[0][0]==right[1][1]
        && right[0][1]==right[1][1]
        && right[0][2]==right[1][1]
        && right[1][0]==right[1][1]
        && right[1][2]==right[1][1]
        && right[2][0]==right[1][1]
        && right[2][1]==right[1][1]
        && right[2][2]==right[1][1]) &&
       (top[0][0]==top[1][1]
        && top[0][1]==top[1][1]
        && top[0][2]==top[1][1]
        && top[1][0]==top[1][1]
        && top[1][2]==top[1][1]
        && top[2][0]==top[1][1]
        && top[2][1]==top[1][1]
        && top[2][2]==top[1][1]) &&
       (bottom[0][0]==bottom[1][1]
        && bottom[0][1]==bottom[1][1]
        && bottom[0][2]==bottom[1][1]
        && bottom[1][0]==bottom[1][1]
        && bottom[1][2]==bottom[1][1]
        && bottom[2][0]==bottom[1][1]
        && bottom[2][1]==bottom[1][1]
        && bottom[2][2]==bottom[1][1])){
            return true;
    }
    else{
        return false;
    }
}

void RubiksCube3::f()
{
    //corners on face
    char temp=front[0][0];
    front[0][0]=front[2][0];
    front[2][0]=front[2][2];
    front[2][2]=front[0][2];
    front[0][2]=temp;

    //edges on face
    char temp2=front[0][1];
    front[0][1]=front[1][0];
    front[1][0]=front[2][1];
    front[2][1]=front[1][2];
    front[1][2]=temp2;

    //outside corners 1
    char temp3=top[2][0];
    top[2][0]=left[2][2];
    left[2][2]=bottom[0][2];
    bottom[0][2]=right[0][0];
    right[0][0]=temp3;

    //outside corners 2
    char temp4=top[2][2];
    top[2][2]=left[0][2];
    left[0][2]=bottom[0][0];
    bottom[0][0]=right[2][0];
    right[2][0]=temp4;

    //outside edges
    char temp5=top[2][1];
    top[2][1]=left[1][2];
    left[1][2]=bottom[0][1];
    bottom[0][1]=right[1][0];
    right[1][0]=temp5;
}

void RubiksCube3::b()
{
    //corners on face
    char temp=back[0][0];
    back[0][0]=back[2][0];
    back[2][0]=back[2][2];
    back[2][2]=back[0][2];
    back[0][2]=temp;

    //edges on face
    char temp2=back[0][1];
    back[0][1]=back[1][0];
    back[1][0]=back[2][1];
    back[2][1]=back[1][2];
    back[1][2]=temp2;

    //outside corners 1
    char temp3=bottom[2][2];
    bottom[2][2]=left[2][0];
    left[2][0]=top[0][0];
    top[0][0]=right[0][2];
    right[0][2]=temp3;

    //outside corners 2
    char temp4=right[2][2];
    right[2][2]=bottom[2][0];
    bottom[2][0]=left[0][0];
    left[0][0]=top[0][2];
    top[0][2]=temp4;

    //outside edges
    char temp5=right[1][2];
    right[1][2]=bottom[2][1];
    bottom[2][1]=left[1][0];
    left[1][0]=top[0][1];
    top[0][1]=temp5;
}

void RubiksCube3::l()
{
    //corners on face
    char temp=left[0][0];
    left[0][0]=left[2][0];
    left[2][0]=left[2][2];
    left[2][2]=left[0][2];
    left[0][2]=temp;

    //edges on face
    char temp2=left[0][1];
    left[0][1]=left[1][0];
    left[1][0]=left[2][1];
    left[2][1]=left[1][2];
    left[1][2]=temp2;

    //outside corners 1
    char temp3=front[0][0];
    front[0][0]=top [0][0];
    top[0][0]=back[2][2];
    back[2][2]=bottom[0][0];
    bottom[0][0]=temp3;

    //outside corners 2
    char temp4=top[2][0];
    top[2][0]=back[0][2];
    back[0][2]=bottom[2][0];
    bottom[2][0]=front[2][0];
    front[2][0]=temp4;

    //outside edges
    char temp5=front[1][0];
    front[1][0]=top[1][0];
    top[1][0]=back[1][2];
    back[1][2]=bottom[1][0];
    bottom[1][0]=temp5;
}

void RubiksCube3::r()
{
    //corners on face
    char temp=right[0][0];
    right[0][0]=right[2][0];
    right[2][0]=right[2][2];
    right[2][2]=right[0][2];
    right[0][2]=temp;

    //edges on face
    char temp2=right[0][1];
    right[0][1]=right[1][0];
    right[1][0]=right[2][1];
    right[2][1]=right[1][2];
    right[1][2]=temp2;

    //outside corners 1
    char temp3=top[2][2];
    top[2][2]=front[2][2];
    front[2][2]=bottom[2][2];
    bottom[2][2]=back[0][0];
    back[0][0]=temp3;

    //outside corners 2
    char temp4=front[0][2];
    front[0][2]=bottom[0][2];
    bottom[0][2]=back[2][0];
    back[2][0]=top[0][2];
    top[0][2]=temp4;

    //outside edges
    char temp5=top[1][2];
    top[1][2]=front[1][2];
    front[1][2]=bottom[1][2];
    bottom[1][2]=back[1][0];
    back[1][0]=temp5;
}

void RubiksCube3::u()
{
    //corners on face
    char temp=top[0][0];
    top[0][0]=top[2][0];
    top[2][0]=top[2][2];
    top[2][2]=top[0][2];
    top[0][2]=temp;

    //edges on face
    char temp2=top[0][1];
    top[0][1]=top[1][0];
    top[1][0]=top[2][1];
    top[2][1]=top[1][2];
    top[1][2]=temp2;

    //outside corners 1
    char temp3=front[0][2];
    front[0][2]=right[0][2];
    right[0][2]=back[0][2];
    back[0][2]=left[0][2];
    left[0][2]=temp3;

    //outside corners 2
    char temp4=right[0][0];
    right[0][0]=back[0][0];
    back[0][0]=left[0][0];
    left[0][0]=front[0][0];
    front[0][0]=temp4;

    //outside edges
    char temp5=front[0][1];
    front[0][1]=right[0][1];
    right[0][1]=back[0][1];
    back[0][1]=left[0][1];
    left[0][1]=temp5;
}

void RubiksCube3::d()
{
    //corners on face
    char temp=bottom[0][0];
    bottom[0][0]=bottom[2][0];
    bottom[2][0]=bottom[2][2];
    bottom[2][2]=bottom[0][2];
    bottom[0][2]=temp;

    //edges on face
    char temp2=bottom[0][1];
    bottom[0][1]=bottom[1][0];
    bottom[1][0]=bottom[2][1];
    bottom[2][1]=bottom[1][2];
    bottom[1][2]=temp2;

    //outside corners 1
    char temp3=front[2][0];
    front[2][0]=left[2][0];
    left[2][0]=back[2][0];
    back[2][0]=right[2][0];
    right[2][0]=temp3;

    //outside corners 2
    char temp4=left[2][2];
    left[2][2]=back[2][2];
    back[2][2]=right[2][2];
    right[2][2]=front[2][2];
    front[2][2]=temp4;

    //outside edges
    char temp5=front[2][1];
    front[2][1]=left[2][1];
    left[2][1]=back[2][1];
    back[2][1]=right[2][1];
    right[2][1]=temp5;
}

void RubiksCube3::fPrime()
{
    //corners on face
    char temp=front[0][0];
    front[0][0]=front[0][2];
    front[0][2]=front[2][2];
    front[2][2]=front[2][0];
    front[2][0]=temp;

    //edges on face
    char temp2=front[0][1];
    front[0][1]=front[1][2];
    front[1][2]=front[2][1];
    front[2][1]=front[1][0];
    front[1][2]=temp2;


    //outside corners 1
    char temp3=right[0][0];
    right[0][0]=bottom[0][2];
    bottom[0][2]=left[2][2];
    left[2][2]=top[2][0];
    top[2][0]=temp3;

    //outside corners 2
    char temp4=right[2][0];
    right[2][0]=bottom[0][0];
    bottom[0][0]=left[0][2];
    left[0][2]=top[2][2];
    top[2][2]=temp4;

    //outside edges
    char temp5=right[1][0];
    right[1][0]=bottom[0][1];
    bottom[0][1]=left[1][2];
    left[1][2]=top[2][1];
    top[2][1]=temp5;
}

void RubiksCube3::bPrime()
{
    //corners on face
    char temp=back[0][2];
    back[0][2]=back[2][2];
    back[2][2]=back[2][0];
    back[2][0]=back[0][0];
    back[0][0]=temp;

    //edges on face
    char temp2=back[1][2];
    back[1][2]=back[2][1];
    back[2][1]=back[1][0];
    back[1][0]=back[0][1];
    back[0][1]=temp2;

    //outside corners 1
    char temp3=right[0][2];
    right[0][2]=top[0][0];
    top[0][0]=left[2][0];
    left[2][0]=bottom[2][2];
    bottom[2][2]=temp3;

    //outside corners 2
    char temp4=top[0][2];
    top[0][2]=left[0][0];
    left[0][0]=bottom[2][0];
    bottom[2][0]=right[2][2];
    right[2][2]=temp4;

    //outside edges
    char temp5=top[0][1];
    top[0][1]=left[1][0];
    left[1][0]=bottom[2][1];
    bottom[2][1]=right[1][2];
    right[1][2]=temp5;
}

void RubiksCube3::lPrime()
{
    //corners on face
    char temp=left[0][2];
    left[0][2]=left[2][2];
    left[2][2]=left[2][0];
    left[2][0]=left[0][0];
    left[0][0]=temp;

    //edges on face
    char temp2=left[1][2];
    left[1][2]=left[2][1];
    left[2][1]=left[1][0];
    left[1][0]=left[0][1];
    left[0][1]=temp2;

    //outside corners 1
    char temp3=bottom[0][0];
    bottom[0][0]=back[2][2];
    back[2][2]=top[0][0];
    top[0][0]=front[0][0];
    front[0][0]=temp3;

    //outside corners 2
    char temp4=front[2][0];
    front[2][0]=bottom[2][0];
    bottom[2][0]=back[0][2];
    back[0][2]=top[2][0];
    top[2][0]=temp4;

    //outside edges
    char temp5=bottom[1][0];
    bottom[1][0]=back[1][2];
    back[1][2]=top[1][0];
    top[1][0]=front[1][0];
    front[1][0]=temp5;
}

void RubiksCube3::rPrime()
{
    //corners on face
    char temp=right[0][2];
    right[0][2]=right[2][2];
    right[2][2]=right[2][0];
    right[2][0]=right[0][0];
    right[0][0]=temp;

    //edges on face
    char temp2=right[1][2];
    right[1][2]=right[2][1];
    right[2][1]=right[1][0];
    right[1][0]=right[0][1];
    right[0][1]=temp2;

    //outside corners 1
    char temp3=back[0][0];
    back[0][0]=bottom[2][2];
    bottom[2][2]=front[2][2];
    front[2][2]=top[2][2];
    top[2][2]=temp3;

    //outside corners 2
    char temp4=top[0][2];
    top[0][2]=back[2][0];
    back[2][0]=bottom[0][2];
    bottom[0][2]=front[0][2];
    front[0][2]=temp4;


    //outside edges
    char temp5=back[1][0];
    back[1][0]=bottom[1][2];
    bottom[1][2]=front[1][2];
    front[1][2]=top[1][2];
    top[1][2]=temp5;

}

void RubiksCube3::uPrime()
{
    //corners on face
    char temp=top[0][2];
    top[0][2]=top[2][2];
    top[2][2]=top[2][0];
    top[2][0]=top[0][0];
    top[0][0]=temp;

    //edges on face
    char temp2=top[1][2];
    top[1][2]=top[2][1];
    top[2][1]=top[1][0];
    top[1][0]=top[0][1];
    top[0][1]=temp2;

    //outside corners 1
    char temp3=left[0][2];
    left[0][2]=back[0][2];
    back[0][2]=right[0][2];
    right[0][2]=front[0][2];
    front[0][2]=temp3;

    //outside corners 2
    char temp4=front[0][0];
    front[0][0]=left[0][0];
    left[0][0]=back[0][0];
    back[0][0]=right[0][0];
    right[0][0]=temp4;

    //outside edges
    char temp5=left[0][1];
    left[0][1]=back[0][1];
    back[0][1]=right[0][1];
    right[0][1]=front[0][1];
    front[0][1]=temp5;
}

void RubiksCube3::dPrime()
{
    //corners on face
    char temp=bottom[0][2];
    bottom[0][2]=bottom[2][2];
    bottom[2][2]=bottom[2][0];
    bottom[2][0]=bottom[0][0];
    bottom[0][0]=temp;

    //edges on face
    char temp2=bottom[1][2];
    bottom[1][2]=bottom[2][1];
    bottom[2][1]=bottom[1][0];
    bottom[1][0]=bottom[0][1];
    bottom[0][1]=temp2;

    //outside corners 1
    char temp3=right[2][0];
    right[2][0]=back[2][0];
    back[2][0]=left[2][0];
    left[2][0]=front[2][0];
    front[2][0]=temp3;

    //outside corners 2
    char temp4=front[2][2];
    front[2][2]=right[2][2];
    right[2][2]=back[2][2];
    back[2][2]=left[2][2];
    left[2][2]=temp4;

    //outside edges
    char temp5=right[2][1];
    right[2][1]=back[2][1];
    back[2][1]=left[2][1];
    left[2][1]=front[2][1];
    front[2][1]=temp5;
}

void RubiksCube3::outputFrontLayer()
{
    //output outside
    cout<<endl<<"Top three (left to right): "
    <<top[2][0]<<", "<<top[2][1]<<", "<<top[2][2]<<endl
    <<"Right three (top to bottom): "
    <<right[0][0]<<", "<<right[1][0]<<", "<<right[2][0]<<endl
    <<"Bottom three (left to right): "
    <<bottom[0][0]<<", "<<bottom[0][1]<<", "<<bottom[0][2]<<endl
    <<"Left three (top to bottom): "
    <<left[0][2]<<", "<<left[1][2]<<", "<<left[2][2]<<endl<<endl;

    //output inside
    cout<<"Front face:\n\n"
    <<setw(4)<<front[0][0]<<setw(4)<<front[0][1]<<setw(4)<<front[0][2]<<endl
    <<setw(4)<<front[1][0]<<setw(4)<<front[1][1]<<setw(4)<<front[1][2]<<endl
    <<setw(4)<<front[2][0]<<setw(4)<<front[2][1]<<setw(4)<<front[2][2]<<endl<<endl;
}

void RubiksCube3::outputBackLayer()
{
    //output outside
    cout<<endl<<"Top three (left to right): "
    <<top[0][0]<<", "<<top[0][1]<<", "<<top[0][2]<<endl
    <<"Left three (top to bottom): "
    <<left[0][0]<<", "<<left[1][0]<<", "<<left[2][0]<<endl
    <<"Bottom three (left to right): "
    <<bottom[2][0]<<", "<<bottom[2][1]<<", "<<bottom[2][2]<<endl
    <<"Right three (top to bottom): "
    <<right[0][2]<<", "<<right[1][2]<<", "<<right[2][2]<<endl<<endl;

    //output inside
    cout<<"Back face:\n\n"
    <<setw(4)<<back[0][0]<<setw(4)<<back[0][1]<<setw(4)<<back[0][2]<<endl
    <<setw(4)<<back[1][0]<<setw(4)<<back[1][1]<<setw(4)<<back[1][2]<<endl
    <<setw(4)<<back[2][0]<<setw(4)<<back[2][1]<<setw(4)<<back[2][2]<<endl<<endl;
}

void RubiksCube3::outputLeftLayer()
{
    //output outside
    cout<<endl<<"Front three (top to bottom): "
    <<front[0][0]<<", "<<front[1][0]<<", "<<front[0][0]<<endl
    <<"Top three (left to right): "
    <<top[0][0]<<", "<<top[1][0]<<", "<<top[2][0]<<endl
    <<"Back three (top to bottom): "
    <<back[0][2]<<", "<<back[1][2]<<", "<<back[2][2]<<endl
    <<"Bottom three (left to right): "
    <<bottom[2][0]<<", "<<bottom[1][0]<<", "<<bottom[0][0]<<endl<<endl;

    //output inside
    cout<<"Left face:\n\n"
    <<setw(4)<<left[0][0]<<setw(4)<<left[0][1]<<setw(4)<<left[0][2]<<endl
    <<setw(4)<<left[1][0]<<setw(4)<<left[1][1]<<setw(4)<<left[1][2]<<endl
    <<setw(4)<<left[2][0]<<setw(4)<<left[2][1]<<setw(4)<<left[2][2]<<endl<<endl;
}

void RubiksCube3::outputRightLayer()
{
    //output outside
    cout<<endl<<"Top three (left to right): "
    <<top[2][2]<<", "<<top[1][2]<<", "<<top[0][2]<<endl
    <<"Back three (top to bottom): "
    <<back[0][0]<<", "<<back[1][0]<<", "<<back[2][0]<<endl
    <<"Bottom three (left to right): "
    <<bottom[0][2]<<", "<<bottom[1][2]<<", "<<bottom[2][2]<<endl
    <<"Front three (top to bottom): "
    <<front[0][2]<<", "<<front[1][2]<<", "<<front[2][2]<<endl<<endl;

    //output inside
    cout<<"Right face:\n\n"
    <<setw(4)<<right[0][0]<<setw(4)<<right[0][1]<<setw(4)<<right[0][2]<<endl
    <<setw(4)<<right[1][0]<<setw(4)<<right[1][1]<<setw(4)<<right[1][2]<<endl
    <<setw(4)<<right[2][0]<<setw(4)<<right[2][1]<<setw(4)<<right[2][2]<<endl<<endl;
}

void RubiksCube3::outputTopLayer()
{
    //output outside
    cout<<endl<<"Front three (left to right): "
    <<front[0][0]<<", "<<front[0][1]<<", "<<front[0][2]<<endl
    <<"Right three (left to right): "
    <<right[0][0]<<", "<<right[0][1]<<", "<<right[0][2]<<endl
    <<"Back three (left to right): "
    <<back[0][0]<<", "<<back[0][1]<<", "<<back[0][2]<<endl
    <<"Left three (left to right): "
    <<left[0][0]<<", "<<left[0][1]<<", "<<left[0][2]<<endl<<endl;

    //output inside
    cout<<"Top face:\n\n"
    <<setw(4)<<top[0][0]<<setw(4)<<top[0][1]<<setw(4)<<top[0][2]<<endl
    <<setw(4)<<top[1][0]<<setw(4)<<top[1][1]<<setw(4)<<top[1][2]<<endl
    <<setw(4)<<top[2][0]<<setw(4)<<top[2][1]<<setw(4)<<top[2][2]<<endl<<endl;
}

void RubiksCube3::outputBottomLayer()
{
    //output outside
    cout<<endl<<"Front three (left to right): "
    <<front[2][0]<<", "<<front[2][1]<<", "<<front[2][2]<<endl
    <<"Left three (left to right): "
    <<left[2][0]<<", "<<left[2][1]<<", "<<left[2][2]<<endl
    <<"Back three (left to right): "
    <<back[2][0]<<", "<<back[2][1]<<", "<<back[2][2]<<endl
    <<"Right three (left to right): "
    <<right[2][0]<<", "<<right[2][1]<<", "<<right[2][2]<<endl<<endl;

    //output inside
    cout<<"Bottom face:\n\n"
    <<setw(4)<<bottom[0][0]<<setw(4)<<bottom[0][1]<<setw(4)<<bottom[0][2]<<endl
    <<setw(4)<<bottom[1][0]<<setw(4)<<bottom[1][1]<<setw(4)<<bottom[1][2]<<endl
    <<setw(4)<<bottom[2][0]<<setw(4)<<bottom[2][1]<<setw(4)<<bottom[2][2]<<endl<<endl;
}

void RubiksCube3::firstAlg()
{
    //R' D' R D
    rPrime();
    dPrime();
    r();
    d();
}

void RubiksCube3::leftAlg()
{
    //U’ L’ U L U F U’ F’
    uPrime();
    lPrime();
    u();
    l();
    u();
    f();
    uPrime();
    fPrime();
}

void RubiksCube3::rightAlg()
{
    //U R U' R' U' F' U F
    u();
    r();
    uPrime();
    rPrime();
    uPrime();
    fPrime();
    u();
    f();
}

void RubiksCube3::topCrossAlg1()
{
    //F R U R' U' F'
    f();
    r();
    u();
    rPrime();
    uPrime();
    fPrime();
}

void RubiksCube3::topCrossAlg2()
{
    //R U R’ U R U U R’ U
    r();
    u();
    rPrime();
    u();
    r();
    u();
    u();
    rPrime();
    u();
}

void RubiksCube3::topCornersAlg()
{
    //U R U’ L’ U R’ U’ L
    u();
    r();
    uPrime();
    lPrime();
    u();
    rPrime();
    uPrime();
    l();
}

void RubiksCube3::displayCube()
{
    outputFront();
    outputBack();
    outputLeft();
    outputRight();
    outputTop();
    outputBottom();
}

void RubiksCube3::outputFront()
{
    cout<<"Front face:\n\n"
    <<setw(4)<<front[0][0]<<setw(4)<<front[0][1]<<setw(4)<<front[0][2]<<endl
    <<setw(4)<<front[1][0]<<setw(4)<<front[1][1]<<setw(4)<<front[1][2]<<endl
    <<setw(4)<<front[2][0]<<setw(4)<<front[2][1]<<setw(4)<<front[2][2]<<endl<<endl;
}

void RubiksCube3::outputBack()
{
    cout<<"Back face:\n\n"
    <<setw(4)<<back[0][0]<<setw(4)<<back[0][1]<<setw(4)<<back[0][2]<<endl
    <<setw(4)<<back[1][0]<<setw(4)<<back[1][1]<<setw(4)<<back[1][2]<<endl
    <<setw(4)<<back[2][0]<<setw(4)<<back[2][1]<<setw(4)<<back[2][2]<<endl<<endl;
}

void RubiksCube3::outputLeft()
{
    cout<<"Left face:\n\n"
    <<setw(4)<<left[0][0]<<setw(4)<<left[0][1]<<setw(4)<<left[0][2]<<endl
    <<setw(4)<<left[1][0]<<setw(4)<<left[1][1]<<setw(4)<<left[1][2]<<endl
    <<setw(4)<<left[2][0]<<setw(4)<<left[2][1]<<setw(4)<<left[2][2]<<endl<<endl;
}

void RubiksCube3::outputRight()
{
    cout<<"Right face:\n\n"
    <<setw(4)<<right[0][0]<<setw(4)<<right[0][1]<<setw(4)<<right[0][2]<<endl
    <<setw(4)<<right[1][0]<<setw(4)<<right[1][1]<<setw(4)<<right[1][2]<<endl
    <<setw(4)<<right[2][0]<<setw(4)<<right[2][1]<<setw(4)<<right[2][2]<<endl<<endl;
}

void RubiksCube3::outputTop()
{
    cout<<"Top face:\n\n"
    <<setw(4)<<top[0][0]<<setw(4)<<top[0][1]<<setw(4)<<top[0][2]<<endl
    <<setw(4)<<top[1][0]<<setw(4)<<top[1][1]<<setw(4)<<top[1][2]<<endl
    <<setw(4)<<top[2][0]<<setw(4)<<top[2][1]<<setw(4)<<top[2][2]<<endl<<endl;
}

void RubiksCube3::outputBottom()
{
    cout<<"Bottom face:\n\n"
    <<setw(4)<<bottom[0][0]<<setw(4)<<bottom[0][1]<<setw(4)<<bottom[0][2]<<endl
    <<setw(4)<<bottom[1][0]<<setw(4)<<bottom[1][1]<<setw(4)<<bottom[1][2]<<endl
    <<setw(4)<<bottom[2][0]<<setw(4)<<bottom[2][1]<<setw(4)<<bottom[2][2]<<endl<<endl;
}
