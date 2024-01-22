#include <Conventers/IConventer.hpp>


namespace Conventers
{
class BassConventer : public IConventer
{
private:
    int time_begin_;
    int time_end_;
public:
    void Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files) override;
    BassConventer();
    BassConventer(std::vector<int> params);
};
}