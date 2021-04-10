#include <iostream>
#include <fstream>
#include "Container.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);

    cout << "Start" << endl;
    Container c = Container();
    c.In(ifst);
    ofst << "Filled container. " << endl;
    c.Out(ofst);

    ofst << "\n\nSorted container." << endl;
    c.Sort();
    c.Out(ofst);

    ofst << "\n\nFiltered container." << endl;
    c.OutCartoons(ofst);

    c.Clear();
    ofst << "Empty container. " << endl;
    c.Out(ofst);
    cout << "Stop" << endl;

    return 0; 
}