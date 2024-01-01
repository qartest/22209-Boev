#include <Controller.hpp>

char kok[] = {"kok"};
char kok1[] = {"-h"};
char kok2[] = {"-c"};
char kok3[] = {"/home/qartest/work/projects/ok/config.txt"};
char kok4[] = {"/home/qartest/work/projects/ok/out.wav"};
char kok5[] = {"/home/qartest/work/projects/ok/origin.wav"};
char kok6[] = {"/home/qartest/work/projects/ok/severe_tire_damage.wav"};

int main(int argc, char *argv[])
{   
    char* allkok[7];

    allkok[0] = kok;
    allkok[1] = kok1;
    allkok[2] = kok2;
    allkok[3] = kok3;
    allkok[4] = kok4;
    allkok[5] = kok5;
    allkok[6] = kok6;

    Controller Processor;
    return Processor.Start(7, allkok);

}