#include "GViewApp.hpp"

using namespace GView::View;

BufferView::BufferView(GView::Object& obj, BufferViewBuilder* setting) : UserControl("d:c"), fileObj(obj)
{
    this->chars.Fill(' ', 1024);
}
void BufferView::WrieLineToChars(unsigned long long offset)
{
    auto buf = this->fileObj.cache.Get(offset, 128);
    auto c   = this->chars.GetBuffer();
    auto s   = buf.data;
    auto e   = s + buf.length;
    while (s < e)
    {
        c->Code = *s;
        c->Color = ColorPair{ Color::White,Color::Black };
        s++;
        c++;
    }
}
void BufferView::Paint(Renderer& renderer)
{
    renderer.Clear(' ', ColorPair{ Color::White,Color::Black });
    for (unsigned int tr = 0; tr < 20; tr++)
    {
        WrieLineToChars(tr*128);
        renderer.WriteSingleLineText(0, tr, chars, ColorPair{ Color::White,Color::Black });
    }
}