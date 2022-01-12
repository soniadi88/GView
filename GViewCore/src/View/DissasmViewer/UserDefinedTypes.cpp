#include "DissasmViewer.hpp"

using namespace GView::View::DissasmViewer;
using namespace AppCUI::Input;

#define INTERNAL_SETTINGS ((SettingsData*) this->data)

const std::map<std::string_view, InternalDissasmType> types = { { "UInt8", InternalDissasmType::UInt8 },
                                                                { "UInt16", InternalDissasmType::UInt16 },
                                                                { "UInt32", InternalDissasmType::UInt32 },
                                                                { "UInt64", InternalDissasmType::UInt64 },
                                                                { "Int8", InternalDissasmType::Int8 },
                                                                { "Int16", InternalDissasmType::Int16 },
                                                                { "Int32", InternalDissasmType::Int32 },
                                                                { "Int64", InternalDissasmType::Int64 },
                                                                { "OneArray", InternalDissasmType::UnidimnsionalArray },
                                                                { "BiArray", InternalDissasmType::BiimensionalArray } };

TypeID Settings::AddType(std::string_view name, std::string_view definition)
{
    uint32& availableValue = INTERNAL_SETTINGS->availableID;

    DissasmType userType = { InternalDissasmType::UserDefined, name };

    char* newBuffer = new char[definition.size() + 1];
    memcpy(newBuffer, definition.data(), definition.size());
    newBuffer[definition.size()] = '\0';
    INTERNAL_SETTINGS->buffersToDelete.push_back(newBuffer);

    char* start = newBuffer;
    char* end   = newBuffer + definition.size();

    const char *startDef = start, *endDef = nullptr;

    char buffer[128];
    char* startingNamePtr = start;
    uint32 size           = 0;
    uint32 arraySizes     = 0;
    DissasmType newType   = {};

    while (start < end)
    {
        if (*start == ' ')
        {
            *start       = '\0';
            buffer[size] = '\0';
            auto it      = types.find(buffer);
            if (it != types.end())
            {
                newType.primaryType = (InternalDissasmType) it->second;
            }
            else
            {
                // err
            }
            size            = 0;
            startingNamePtr = start + 1;
        }
        else if (*start == '[')
        {
            *start = '\0';
            size = 0;
            arraySizes++;
        }
        else if (*start == ']')
        {
            buffer[size] = '\0';
            *start       = '\0';
            auto res     = Number::ToUInt32(buffer);
            if (!res.has_value())
            {
                // err
            }
            else
            {
                if (arraySizes == 1)
                {
                    newType.secondaryType = (uint32) newType.primaryType;
                    newType.primaryType   = InternalDissasmType::UnidimnsionalArray;
                    newType.width         = res.value();
                }
                else // bidimensional
                {
                    newType.primaryType = InternalDissasmType::BiimensionalArray;
                    newType.height      = res.value();
                }
            }
        }
        else if (*start == ';')
        {
            arraySizes   = 0;
            *start       = '\0';
            buffer[size] = '\0';
            newType.name = startingNamePtr;

            size = 0;
            userType.internalTypes.push_back(newType);
            newType = {};
        }
        else if (*start == '\n' || *start == '\r')
        {
            size = 0;
        }
        else
            buffer[size++] = *start;
        start++;
    }

    INTERNAL_SETTINGS->userDeginedTypes[availableValue] = userType;
    ++availableValue;
    return availableValue - 1;
}