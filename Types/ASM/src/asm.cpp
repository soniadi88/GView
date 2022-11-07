#include "asm.hpp"

using namespace AppCUI;
using namespace AppCUI::Utils;
using namespace AppCUI::Application;
using namespace AppCUI::Controls;
using namespace GView::Utils;
using namespace GView::Type;
using namespace GView;
using namespace GView::View;

extern "C"
{
    PLUGIN_EXPORT bool Validate(const AppCUI::Utils::BufferView& buf, const std::string_view& extension)
    {
        // all good
        return true;
    }
    PLUGIN_EXPORT TypeInterface* CreateInstance()
    {
        return new ASM::ASMFile();
    }
    PLUGIN_EXPORT bool PopulateWindow(Reference<WindowInterface> win)
    {
        auto a = win->GetObject()->GetContentType<ASM::ASMFile>();
        a->Update();

        LexicalViewer::Settings settings;
        settings.SetParser(a.ToObjectRef<LexicalViewer::ParseInterface>());

        settings.SetMaxTokenSize({ 30u, 5u });

        settings.AddPlugin(&a->plugins.removeComments);
        win->CreateViewer("Lexical", settings);

        win->CreateViewer<TextViewer::Settings>("Text View");
        win->CreateViewer<BufferViewer::Settings>("Buffer View");

        // add panels
        win->AddPanel(Pointer<TabPage>(new ASM::Panels::Information(a)), true);

        return true;
    }
    PLUGIN_EXPORT void UpdateSettings(IniSection sect)
    {
        sect["Extension"]   = "asm";
        sect["Priority"]    = 1;
        sect["Description"] = "ASM / Assembly language source file (*.asm)";
    }
}

int main()
{
    return 0;
}
