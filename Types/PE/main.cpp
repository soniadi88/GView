#include "GView.hpp"

using namespace AppCUI;
using namespace AppCUI::Application;
using namespace AppCUI::Controls;

extern "C"
{
    bool PLUGIN_EXPORT Validate(const GView::Buffer &buf, const std::string_view &extension)
    {
        if (buf.length < 2)
            return false;
        return (buf[0] == 'M') && (buf[1] == 'Z');
    }
}

int main()
{
    return 0;
}