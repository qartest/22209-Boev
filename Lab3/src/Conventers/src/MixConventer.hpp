#include <Conventers/IConventer.hpp>

namespace Conventers
{
class MixConventer : public IConventer
{
private:
    int input_digit_;
    int time_begin_;
public:
    void Do(int now_second, OneSecond :: OneSecond& second, std::deque<std::shared_ptr<Stream :: Stream>> input_files) override;
    MixConventer();
    MixConventer(int first, int second);
};
}