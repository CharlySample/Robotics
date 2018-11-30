#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
        double i=0.0,dato=0.0;

        string line;

        for(;;)
        {
                ifstream fp("data.txt");

                if (fp.is_open())
                {
                        while ( getline (fp,line) )
                        {
                                usleep(400000);
                                cout << line << endl;
                        }
                        fp.close();
                }
        }
        return 0;
}
