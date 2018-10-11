#include <iostream>
#include "floatfann.h"
#include <armadillo>
#include "carlos.hpp"

using namespace std;
using namespace arma;

int main()
{
        fann_type *calc_out;
        fann_type *calc_out1;
        fann_type input[799];
        string gen[]={"21.txt","22.txt","23.txt","24.txt","91.txt","92.txt","93.txt","94.txt","a1.txt","a2.txt","a3.txt","a4.txt","u1.txt","u2.txt","u3.txt","u4.txt"};


        for(int o=0; o<=15; o++)
        {
                struct fann *ann = fann_create_from_file("carlos.net");

                mat a;
                a.load(gen[o],raw_ascii);

                for(int i=0; i<=799; i++)
                        input[i] = a(i,0);

                calc_out = fann_run(ann, input);

                cout << "salidas -> [" << sign(calc_out[0]) << " " << sign(calc_out[1]) << "]";

                if(sign(calc_out[0]) == -1 && sign(calc_out[1]) == -1)
                {
                        cout << "\t\tcaracter ->  [2]";
                }

                else if(sign(calc_out[0]) == -1 && sign(calc_out[1]) == 1)
                {
                        cout << "\t\tcaracter ->  [9]";
                }

                else if(sign(calc_out[0]) == 1 && sign(calc_out[1]) == -1)
                {
                        cout << "\t\tcaracter ->  [a]";
                }

                else if(sign(calc_out[0]) == 1 && sign(calc_out[1]) == 1)
                {
                        cout << "\t\tcaracter ->  [u]";
                }

                cout << "\t\tmuestra evaluada -> " << gen[o] << endl;

                if((o+1)%4 == 0)
                        cout << endl;


                fann_destroy(ann);
        }
        return 0;
}
