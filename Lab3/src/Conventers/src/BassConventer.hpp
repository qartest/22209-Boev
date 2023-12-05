#include <Conventers/IConventer.hpp>

namespace Conventers
{
class BassConventer : public IConventer
{
private:
    int first_;
    int second_;
public:
    void Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::string> input_files) override;
    BassConventer();
    BassConventer(int first, int second);
};
}