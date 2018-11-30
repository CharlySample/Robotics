#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

int main() {
        double i=0.0,dato=0.0;

        for(;;)
        {
                ofstream fp("data.txt");

                i+=0.001;
                dato +=0.0005;

                usleep(500000);
                if (fp.is_open())
                {

                        fp << i << ", " << dato << endl;
                        cout << i << endl;

                        fp.close();
                }
        }
        return 0;
}
