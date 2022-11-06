#include "js.hpp"

namespace GView::Type::JS::Plugins
{
using namespace GView::View::LexicalViewer;

std::string_view MergeStrings::GetName()
{
    return "Merge Strings";
}

std::string_view MergeStrings::GetDescription()
{
    return "Concatenate fragmented strings. Includes inner string variables evaluation and replacement.";
}

bool MergeStrings::CanBeAppliedOn(const GView::View::LexicalViewer::PluginData& data)
{
    for (auto index = data.startIndex; index < data.endIndex; index++)
        {
        if (((data.tokens[index].GetTypeID(TokenType::None) == TokenType::String) || (data.tokens[index].GetTypeID(TokenType::None) == TokenType::Word)) &&
                (data.tokens[index + 1].GetTypeID(TokenType::None) == TokenType::Operator_Plus) &&
                ((data.tokens[index + 2].GetTypeID(TokenType::None) == TokenType::String) || (data.tokens[index + 2].GetTypeID(TokenType::None) == TokenType::Word)))
            {
                return true;
            }
        }
        return false;
}

/* Testing:
    var x = "goo" + "gle";
    var y = "da" + "da";
    var xz = 7;
    var t = "ht" + "tp" + "://";
    var t3 = "non" + "o";
    var t2= ".com";
    var asd = 5;
    var test1 = y + t2;
    var test2 = asd + xz;
    var test3 = asd + t2;
    var test4 = x + xz;
    var z     = t + test4 + t2 + "/something"; // need to run plugin twice for complete merge
    var z     = t + x + t2 + "/something";
    var test5 = t + getSiteName() + t2;  // identifies function and skips replacements
*/
GView::View::LexicalViewer::PluginAfterActionRequest MergeStrings::Execute(GView::View::LexicalViewer::PluginData& data)
{
    // Outer pass: handle eval strings
    // Inner pass: merge const strings - only 1-level, not recursive.
    // Check: numeric only additions

    int32 index = (int32) data.endIndex - 1;
    LocalUnicodeStringBuilder<256> temp;
    
    while (index >= (int32) data.startIndex)
    {
        Token endToken = data.tokens[index];
        if ((endToken.GetTypeID(TokenType::None) == TokenType::String || (endToken.GetTypeID(TokenType::None) == TokenType::Word && data.tokens[index+1].GetTypeID(TokenType::None) != TokenType::ExpressionOpen)) &&
            endToken.Precedent().GetTypeID(TokenType::None) == TokenType::Operator_Plus &&
            (endToken.Precedent().Precedent().GetTypeID(TokenType::None) == TokenType::String ||
             endToken.Precedent().Precedent().GetTypeID(TokenType::None) == TokenType::Word))
        {
            Token start = endToken.Precedent().Precedent();
            while (start.Precedent().GetTypeID(TokenType::None) == TokenType::Operator_Plus &&
                   (start.Precedent().Precedent().GetTypeID(TokenType::None) == TokenType::String || 
                    start.Precedent().Precedent().GetTypeID(TokenType::None) == TokenType::Word) )
            {
                start = start.Precedent().Precedent();
            }
            temp.Clear();
            temp.AddChar('"');
            index            = start.GetIndex();
            auto startOffset = start.GetTokenStartOffset();
            auto endOffset   = endToken.GetTokenEndOffset();
            if (!startOffset.has_value() || !endOffset.has_value())
                return GView::View::LexicalViewer::PluginAfterActionRequest::None;
            auto size = endOffset.value() - startOffset.value();
            int32 countStrings = 0;
            while (start.GetIndex() <= endToken.GetIndex())
            {
                if (start.GetTypeID(TokenType::None) == TokenType::String)
                {
                    countStrings++;
                    auto txt   = start.GetText();
                    auto value = txt.substr(1, txt.length() - 2);
                    if (value.find_first_of('"') == std::u16string_view::npos)
                    {
                        temp.Add(value);
                    }
                    else
                    {
                        for (auto ch : value)
                        {
                            if (ch == '"')
                                temp.AddChar('\\');
                            temp.AddChar(ch);
                        }
                    }
                }
                else
                {
                    auto varName = start.GetText();
                    int32 index2 = (int32) data.startIndex + 1;
                    while (index2 < (index - 6)) // {=, string, ;, var, word, =} => at least 6 preceding tokens.
                    {
                        Token varToken = data.tokens[index2];
                        if (varToken.GetTypeID(TokenType::None) == TokenType::Word && varToken.GetText() == varName)
                        {
                            do
                            {
                                auto txt = data.tokens[index2 + 2].GetText();
                                auto value = txt.substr(1, txt.length() - 2);

                                if (data.tokens[index2 + 2].GetTypeID(TokenType::None) == TokenType::String)
                                {
                                    countStrings++;
                                    if (value.find_first_of('"') == std::u16string_view::npos)
                                    {
                                        temp.Add(value);
                                    }
                                    else
                                    {
                                        for (auto ch : value)
                                        {
                                            if (ch == '"')
                                                temp.AddChar('\\');
                                            temp.AddChar(ch);
                                        }
                                    }
                                }
                                else if (data.tokens[index2 + 2].GetTypeID(TokenType::None) == TokenType::Word)
                                {
                                    value = data.tokens[index2 + 2].GetText();
                                    temp.Add("\" + ");
                                    temp.Add(value);
                                    temp.Add(" + \"");
                                }
                                else { // numeric
                                    value = data.tokens[index2 + 2].GetText();
                                    temp.Add(value);
                                }
                                index2 += 2;
                            } while ((data.tokens[index2 + 1].GetTypeID(TokenType::None) != TokenType::Semicolumn) && (index2 < (index - 6)));
                            break;
                        }
                        index2++;
                    }
                }
                start = start.Next().Next();
            }
            temp.AddChar('"');
            if (countStrings > 0)
            {
                data.editor.Replace(startOffset.value(), size, temp.ToStringView());
            }
        }
        index--;
    }

    return GView::View::LexicalViewer::PluginAfterActionRequest::Rescan;    
}
} // namespace GView::Type::JS::Plugins