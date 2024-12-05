#include <ctime>
#include <string>
using namespace std;

#ifndef RANDOMGEN
#define RANDOMGEN
namespace mr {
class RandomGen {
    protected:
    int random_num;

    public:
        RandomGen() {
            srand(time(0));
            random_num = rand();
        }

        double* doubleArrayGen(int array_size, int max_before_point, int max_after_point) {
            double *arr = new double[array_size];
            string Snumber;
            double number;

            for (int i=0; i < array_size; i++) {
                // generating one random double number
                Snumber = to_string(random_num % max_before_point);
                srand(time(0) + random_num);
                random_num = rand();
                Snumber = Snumber + "." + to_string(random_num % max_after_point);
                srand(time(0) + random_num);
                random_num = rand();

                number = stod(Snumber);

                // now adding this random number to the array
                arr[i] = number;
            }
            return arr;
        }
};
}

#endif