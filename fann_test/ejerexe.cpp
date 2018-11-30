#include <stdio.h>
#include "floatfann.h"

int main()
{
    fann_type *calc_out;
    fann_type *calc_out1;
    fann_type input[7];
    fann_type input1[7];

    struct fann *ann = fann_create_from_file("ejerexe.net");

    input[0] = 0;
    input1[0] = 0;
    input[1] = 1;
    input1[1] = 1;
    input[2] = 10;
    input1[2] = 9;
    input[3] = 10;
    input1[3] = 10;
    input[4] = 20;
    input1[4] = 25;
    input[5] = 20;
    input1[5] = 23;
    input[6] = 20;
    input1[6] = 5;
    input[7] = 19;
    input1[7] = 6;

    for(int i=0;i<=7;i++)
{
    calc_out = fann_run(ann, input);
    calc_out1 = fann_run(ann, input1);


    printf("tabla (%f,%f) -> %f\t %f\n", input[i], input1[i], calc_out[0], calc_out1[0]);
printf("\n");


}
 

    fann_destroy(ann);
    return 0;
}
