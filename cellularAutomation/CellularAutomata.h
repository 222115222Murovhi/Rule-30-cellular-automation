#ifndef CELLULARAUTOMATA_H_INCLUDED
#define CELLULARAUTOMATA_H_INCLUDED
#
namespace CellularSpace{
const int ERR_ARG=-1;
const int ERR_CONVERT=-2;

int rule30(int a,int b,int c);
int *randomArray(int size);
int *UserArray(int size);
void cellularAutomaton(int *arr,int r,int size);
int convToInt(std::string str);
}

#endif // CELLULARAUTOMATA_H_INCLUDED
