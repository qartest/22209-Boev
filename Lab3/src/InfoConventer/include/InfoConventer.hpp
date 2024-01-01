#pragma once
#include <vector>
#include <string>


namespace InfoConventer{

struct InfoConventer
{
    std::string name;
    std::vector<std::string> data;
    
    InfoConventer() = default;
    InfoConventer(std::vector<std::string> input);

    InfoConventer(const InfoConventer& pb);
    InfoConventer(InfoConventer&& pb);

    InfoConventer& operator= (const InfoConventer& pb);
    InfoConventer& operator= (InfoConventer&& pb);
    
    virtual ~InfoConventer() = default;
};
}
