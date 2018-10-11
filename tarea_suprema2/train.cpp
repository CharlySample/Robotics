#include <fann.h>

int main()
{
        int num_input = 800;
        int num_output = 2;
        int num_layers = 5;
        int num_neurons_hidden = 400;
        int num_neurons_hidden2 = 200;
        int num_neurons_hidden3 = 100;
        float desired_error = (float) 0.000000001;
        int max_epochs = 50000;
        int epochs_between_reports = 1000;

        struct fann *ann = fann_create_standard(num_layers, num_input,
                                                num_neurons_hidden, 
num_neurons_hidden2, num_neurons_hidden3, num_output);

        fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
        fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

        fann_train_on_file(ann, "carlos.data", max_epochs,
                           epochs_between_reports, desired_error);

        fann_save(ann, "carlos.net");

        fann_destroy(ann);

        return 0;
}
