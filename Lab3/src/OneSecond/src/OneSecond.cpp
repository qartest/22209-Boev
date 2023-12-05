#include "OneSecond.hpp"



namespace OneSecond
{
    OneSecond :: OneSecond() = default;

    std::vector<one_sample> OneSecond :: GiveData(){
        return data;
    }

    void OneSecond :: SetSecond(std::vector<one_sample> second){
        data = second;
    }

    int OneSecond :: GiveSize(){
        return data.size();
    }

}