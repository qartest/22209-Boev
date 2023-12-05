#pragma once
#include <vector>

typedef unsigned short int one_sample;

namespace OneSecond{
class OneSecond
{
private:
    std::vector<one_sample> data;

public:
    OneSecond();
    void SetSecond(std::vector<one_sample> second);
    int GiveSize();
    std::vector<one_sample> GiveData();
};
}