#include <Conventers/IConventer.hpp>

namespace Conventers
{
class MuteConventer : public IConventer
{
private:
    int time_begin_;
    int time_end_;
public:
    void Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files) override;
    MuteConventer();
    MuteConventer(std::vector<int> params);
};
}