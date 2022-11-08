#include "asm.hpp"

namespace GView::Type::ASM
{
using namespace GView::View::LexicalViewer;

int32 BinarySearch(uint32 hash, uint32* list, int32 elementsCount)
{
    if (elementsCount <= 0)
        return -1;
    auto start = 0;
    auto end   = elementsCount - 1;
    while (start <= end)
    {
        auto mij   = (start + end) >> 1;
        auto h_mij = list[mij];
        if (hash < h_mij)
        {
            end = mij - 1;
            continue;
        }
        if (hash > h_mij)
        {
            start = mij + 1;
            continue;
        }
        return mij;
    }
    return -1;
}

namespace Keyword
{
    uint32 list[] = {
        0x00309752,0x00B4E5FB,0x015E2B88,0x01AD46EC,0x02BB6D61,0x02CE7EFE,0x04337A4A,0x044AE098,0x0465E34F,0x04BAB926,
        0x050B90E4,0x0539A734,0x05D572FA,0x05E14E11,0x05FCCAE0,0x06275D70,0x064AE3BE,0x06B4EF6D,0x06BABC4C,0x070E4BB3,
        0x073970F7,0x07CC4BBF,0x07FED40D,0x08FC074C,0x0961C38C,0x09907F86,0x09A8EF90,0x0A927767,0x0A9BF0F9,0x0ADBC663,
        0x0B7BB9DE,0x0C5E5F59,0x0C9D6B14,0x0CA654F2,0x0CD0B30D,0x0CEDBEBE,0x0D2E243A,0x0D6A3BE0,0x0D8384B1,0x0D86190E,
        0x0D903D89,0x0DE9E3E9,0x0DF519FF,0x0E1B207D,0x0F29C2A6,0x0F4D5AC2,0x0F4F78F8,0x0F651FD7,0x0F79994A,0x0F8CDACF,
        0x0FA8F902,0x0FB38F06,0x104EC596,0x10AFF083,0x10DBCFD5,0x113F565C,0x12013031,0x120CABB1,0x12BF639D,0x1309D89E,
        0x136A4552,0x139046FB,0x13938AC6,0x13BAD0C3,0x13EEAC26,0x140BA881,0x14C41969,0x14DAE92B,0x150612F8,0x15495C23,
        0x154F826A,0x156B35AB,0x159896AF,0x15CE9CE7,0x15CED9DA,0x166B5253,0x16C0E5AA,0x171B2EA8,0x176942B7,0x1799D020,
        0x179B2420,0x17A66643,0x17FEC0B1,0x180BC6D6,0x18904EDA,0x18C19939,0x18E16BFA,0x18F52B50,0x19398E59,0x194B01A7,
        0x197F3C04,0x19989CFB,0x19EC1B50,0x1A51E941,0x1A7DA861,0x1AC19C5F,0x1AFCEBEF,0x1B6B3F1D,0x1B77352B,0x1C0E6CC2,
        0x1C362229,0x1C65344E,0x1C682779,0x1CADB36B,0x1D0D2AE3,0x1D4EDA0D,0x1D5E7A1C,0x1DEC9C65,0x1E3BD3CB,0x1E6F4F21,
        0x1E7BD7C7,0x1EB3A6A3,0x1EF534C2,0x1F1D79D7,0x1F4C998D,0x1FEDDCA7,0x200EF598,0x206A59C9,0x20794539,0x20CA82B5,
        0x21684F8D,0x2190A54E,0x219919BD,0x21A56C85,0x2245B70C,0x224F96E1,0x226A5CEF,0x22991B50,0x22CB75CC,0x2307FE66,
        0x240BD9BA,0x2433F02A,0x2439645B,0x244F9A07,0x24796180,0x247C1006,0x251F25CC,0x25B1963E,0x25B8C114,0x25C1ADB0,
        0x25CFEAC7,0x25E85ED3,0x260EFF0A,0x266B506E,0x26DE5E20,0x2710098C,0x271D527E,0x273FFDA4,0x275B57AC,0x27F2EE98,
        0x28544A21,0x286B5394,0x287F53A1,0x28B3C93F,0x28BA7921,0x28EECD35,0x2928A568,0x29683BF0,0x2990073B,0x29B19C8A,
        0x29B5EE6C,0x29F79D72,0x2A76A9AA,0x2A99EE09,0x2AA57AB0,0x2AB0CBF5,0x2B288B2C,0x2B4A65AB,0x2B58407C,0x2BC1B722,
        0x2C06372D,0x2C1D8E4E,0x2C6DAFF2,0x2C99F12F,0x2CB7443F,0x2CF46160,0x2D036BEA,0x2D0DF946,0x2D25D94D,0x2D8760C7,
        0x2DD6CFBC,0x2E693984,0x2E775314,0x2EE5BE26,0x2F036F10,0x2F91A723,0x2FA6C3D3,0x300ACD85,0x303AD62A,0x307DBEA7,
        0x30BBE883,0x30C60FF7,0x30E5C14C,0x30E8AB4D,0x30F467AC,0x3145CEA9,0x31A08F03,0x31ADD47A,0x31BA99AB,0x3216B6F1,
        0x3288F721,0x333BF4DA,0x33952F14,0x3412D131,0x341F3D69,0x3424E5E6,0x3445D362,0x3482DCCC,0x348D31D4,0x352F0811,
        0x356868D3,0x36081C4F,0x36510A58,0x372F0B37,0x374E7677,0x377C2DEF,0x378E3C99,0x38189831,0x384271B5,0x3845D9AE,
        0x384FE55D,0x386BD144,0x3899AF41,0x38A8DF31,0x38AD95DF,0x38C7CF96,0x38CBE105,0x38ED59EB,0x390ADBB0,0x390D4E3C,
        0x3912B7BA,0x392F27E6,0x396DC469,0x3979828F,0x39B758B6,0x3A0CB3FC,0x3A189B57,0x3A28A2C9,0x3A3910E1,0x3A58E193,
        0x3AB09E84,0x3B2F2B0C,0x3B391274,0x3B42B4F9,0x3B549EE1,0x3BA33506,0x3C1D738D,0x3C4E7E56,0x3C8028D4,0x3CD47CE9,
        0x3D45977D,0x3D6AE611,0x3DA3382C,0x3DE5D5C3,0x3E0CBA48,0x3E69E0F8,0x3E6DB608,0x3F04839F,0x3F47CA1E,0x402AFD06,
        0x40BF0CFD,0x40D520DB,0x41387A9E,0x41CBEF30,0x41CCB46A,0x422B002C,0x422F1C88,0x43667255,0x4368B0EC,0x43E5DF35,
        0x4427A55E,0x446F1D49,0x44A6E4E2,0x44C4D457,0x4518ACA8,0x469348DD,0x46BABABA,0x46EE2EAD,0x470E2234,0x482F25FA,
        0x482F3F83,0x488E575C,0x48AE506A,0x48CC3317,0x48F97069,0x4915673D,0x492BBB43,0x49B0B621,0x49CE3A5F,0x49E18F98,
        0x4AA34CA3,0x4AC10AA0,0x4AE81A10,0x4B18B61A,0x4B6AFC1B,0x4B830101,0x4BA8FD1A,0x4C75E965,0x4CD958CF,0x4CDF5548,
        0x4D4E0E46,0x4DDC906D,0x4E08B1DC,0x4E17251F,0x4E2F48F5,0x4E990E98,0x4EA6FA3A,0x4F29972F,0x4F2B14A3,0x4F5EF006,
        0x4FD79360,0x4FE1990A,0x4FF911EC,0x4FFEFAF1,0x5011AFB8,0x50789BB8,0x509FCDDC,0x50A35615,0x51335FD0,0x5145FD79,
        0x5169FEE1,0x51935A2E,0x51AD12ED,0x51C4E8CE,0x52157568,0x522F968A,0x524470DF,0x5247E807,0x524BAD10,0x5254F33E,
        0x526079C4,0x5295758C,0x52AA242B,0x52E4640C,0x52EB3813,0x52EE32B3,0x530123FD,0x533362F6,0x536A0207,0x536D474A,
        0x53E2B39C,0x5404C49B,0x54419CE5,0x5473C0C0,0x5494584D,0x54C8A426,0x55764C09,0x55A23BD9,0x55E05BD4,0x55E573A1,
        0x55EACF14,0x5611B92A,0x56CE4ED6,0x5727C347,0x57301E72,0x57432A9C,0x5837877E,0x58AA2D9D,0x5904AC8D,0x591D3520,
        0x5A1F0ED8,0x5AFA533B,0x5B173996,0x5B486ABE,0x5C013228,0x5CE1AD81,0x5D02942F,0x5D342984,0x5D448230,0x5D45D8B1,
        0x5E1481F3,0x5E72636E,0x5E736DA9,0x5EE1B0A7,0x5EE476F0,0x5F044569,0x5F41AE36,0x5FD7AC90,0x603E6810,0x604E2C2F,
        0x60D7AE23,0x60FF15B4,0x620A87DF,0x625E9455,0x62C92FEB,0x63AA3EEE,0x64037D57,0x64148B65,0x64184786,0x6426B6C8,
        0x645F1115,0x6511D0C7,0x653D5A80,0x659932CD,0x65AA4214,0x65F22701,0x66184AAC,0x66F2BB33,0x679E71AF,0x67D32E3E,
        0x680ADC3B,0x685AF15A,0x6863EFEB,0x68AFA035,0x68C20CAE,0x693F0759,0x69461E14,0x6961ABF7,0x69C8B1F2,0x6B3F0A7F,
        0x6B920597,0x6BEE5A0E,0x6C468018,0x6C651FD0,0x6CBE222A,0x6CF2C4A5,0x6CFE1F96,0x6D8312AB,0x6D9208BD,0x6DAEE608,
        0x6DDA42A7,0x6DDCCF8E,0x6E45F374,0x6E63F95D,0x6EAB0A9A,0x6EDA4719,0x6F149CB6,0x6F2D713F,0x6FEE153B,0x6FF7BEDE,
        0x6FFEDD47,0x701456FD,0x7046DEB0,0x7084D38D,0x70C26F1D,0x70D33C69,0x710391CE,0x71149FDC,0x71657293,0x729DEC0F,
        0x73185F23,0x7461BD48,0x74C8C343,0x75325524,0x7545BC99,0x75C573F0,0x763E0219,0x76462320,0x76CBD58B,0x77567EF2,
        0x77657C05,0x77BE337B,0x77E37EE0,0x77F2D5F6,0x781C0E7E,0x786E304B,0x790BBEB9,0x79146528,0x79186895,0x79640AAE,
        0x79A73638,0x79C20F5D,0x79C27D48,0x79F2D91C,0x7A3D7B8F,0x7AB1F417,0x7B63CFC5,0x7B640DD4,0x7BBAF006,0x7BCA54F2,
        0x7BDDF83D,0x7BE8F760,0x7C2D85B6,0x7C3F2542,0x7C462C92,0x7C63D158,0x7CE30957,0x7D26CB84,0x7DCCAF78,0x7F3FAC7A,
        0x7FDA61DC,0x80870F47,0x80BDD620,0x81314B6E,0x815E7409,0x81655F37,0x816B9BF1,0x81E900D2,0x82569043,0x8263DACA,
        0x82658D56,0x82BF4DD3,0x82C03E7E,0x82C21D88,0x82F7DCC7,0x836B9F17,0x83B2F681,0x83CCB8EA,0x83E2141C,0x83E4C86C,
        0x84326CC1,0x8465907C,0x846A4AB0,0x8495BB9D,0x84DFA3A3,0x854BFEF3,0x85B20568,0x86189339,0x862350CC,0x86434744,
        0x8650F820,0x86A45E72,0x86A64951,0x86BDDF92,0x86C1BF25,0x86CA6643,0x86D5D880,0x8738A2FF,0x873E7EAF,0x874F2739,
        0x874FDC5D,0x876FFFDD,0x87928442,0x87A14C08,0x88B222B3,0x88FFCE3F,0x8920E6B7,0x892E4CA0,0x893CA333,0x89464109,
        0x89591C1D,0x89698D2D,0x89A784CA,0x89DFAB82,0x89E31DCE,0x8A3E5031,0x8A6B9B1F,0x8B29A47E,0x8B46442F,0x8B479A46,
        0x8B55E951,0x8B780BE3,0x8BB20EDA,0x8C01E932,0x8C26E321,0x8CC2BEE5,0x8CD5E1F2,0x8D2C2071,0x8D2E9A1F,0x8D3A0962,
        0x8D479D6C,0x8D4B5283,0x8D68C704,0x8D95C9C8,0x8E2A50C7,0x8E6573AE,0x8E6BB068,0x8EB22C25,0x8EE91549,0x8EF2D0EC,
        0x8F07642D,0x8F0F40EC,0x8F2C2397,0x8F4674FE,0x8F63EF41,0x904FEA88,0x9061C418,0x908460A8,0x90CCCD61,0x90E4DCE3,
        0x9163F267,0x91A46FC3,0x91C1D076,0x92CCD087,0x92F203AC,0x93236543,0x93BDF409,0x941F8FF6,0x946BB9DA,0x94CB0E3D,
        0x94D000E2,0x95237D12,0x9564040D,0x95BDF72F,0x9620FB2E,0x963AF860,0x967A1124,0x96B876F2,0x96E4A4C7,0x96E4E655,
        0x9701FA83,0x9718ADFC,0x976BAF96,0x97A66414,0x97D99A6C,0x97E4A65A,0x97F9AD51,0x98E98317,0x998C9C83,0x99CD174A,
        0x99D5F669,0x99D99D92,0x99F9B077,0x9A1A4E97,0x9A2C34E8,0x9A47B1E3,0x9A58F150,0x9ACF33B7,0x9B4F46B5,0x9B51192F,
        0x9B9472F8,0x9BADFCEB,0x9BB2409C,0x9BD5F98F,0x9BF9B39D,0x9C31EC48,0x9C560414,0x9C68DEA1,0x9D4A747B,0x9D8E85DE,
        0x9DAB202A,0x9DC7157E,0x9DD387A7,0x9DD55301,0x9DF2E889,0x9DF5C906,0x9E2B44DC,0x9E3CC442,0x9E91F1AA,0xA005479F,
        0xA02C3E5A,0xA047BB55,0xA138F764,0xA29C03EB,0xA2E54358,0xA31B4EE0,0xA361E201,0xA38DC60B,0xA3ADFC02,0xA3D337D3,
        0xA4151BCA,0xA4F9C1C8,0xA51A5FE8,0xA561E527,0xA5DB5693,0xA6BDA0D8,0xA6EA84C6,0xA76EB971,0xA86558F2,0xA89C0D5D,
        0xA8C0867D,0xA8E54CCA,0xA8E99C47,0xA8EA87EC,0xA91B5852,0xA925DB25,0xA934A9B1,0xA945AA24,0xA9EA55B0,0xAA41BE51,
        0xAA50D3D2,0xAA746C43,0xAAB6B798,0xAAD12E09,0xAAF9CB3A,0xAB1A365F,0xAB1A695A,0xAB34ACD7,0xAB920621,0xABAD8317,
        0xABC7562E,0xAC28681A,0xACB6BABE,0xACD1312F,0xAD406772,0xADE490B2,0xADF9BD7E,0xAE14578B,0xAE298967,0xAE69BA92,
        0xAE84AC0C,0xAEC73041,0xAFC75C7A,0xAFD071E5,0xAFEDD953,0xB038704C,0xB0390F01,0xB0555A72,0xB06112BC,0xB095E9B1,
        0xB0B35B00,0xB0BFD935,0xB0E4956B,0xB12BAFC6,0xB1331353,0xB19EBDB7,0xB1C094A8,0xB1DB6A16,0xB1F6596B,0xB2159E66,
        0xB23B2474,0xB280B1E6,0xB28B216C,0xB2E76FAA,0xB34BB9F3,0xB38C6BF1,0xB39C1EAE,0xB3B6C5C3,0xB3E10DB2,0xB3F184A9,
        0xB440DEEC,0xB4E49BB7,0xB4F15191,0xB5656D69,0xB5879B5B,0xB59C21D4,0xB5D3D133,0xB5E56141,0xB5EA9C63,0xB5FFEF36,0xB61B6CC9,0xB645BE9B,0xB64A354A,0xB6E49EDD,0xB73AECEB,0xB7E56467,0xB81B6FEF,0xB84BC1D2,0xB891747C,0xB900585A,0xB940E6CB,0xB9D7C7AA,0xBA369C70,0xBA407BE9,0xBA4A3B96,0xBA6ED75A,0xBADB77A2,0xBB41D914,0xBB429EFB,0xBBA75F6D,0xBBD377AB,0xBBE13A32,0xBBEAA5D5,0xBC34C79A,0xBD4187D1,0xBD4BC9B1,0xBD57C40E,0xBDD93DC4,0xBDF051E0,0xBEABA1E4,0xBF23EDE9,0xBF259CCF,0xBF34B9E7,0xBF418AF7,0xBF4517EB,0xBF71E4CA,0xC02755D4,0xC08A9165,0xC0F9DB67,0xC123F10F,0xC1B98553,0xC1C7FFDC,0xC1C9D705,0xC1D3811D,0xC1E4B02E,0xC20D3A05,0xC238121B,0xC24BD190,0xC25979D3,0xC25CDCC6,0xC2D5911E,0xC2E3F4F1,0xC2EDF73C,0xC3275A8D,0xC3CF89C0,0xC3E20D76,0xC3E4B354,0xC40132B8,0xC40BA802,0xC4346C40,0xC4381541,0xC48C86B4,0xC4EEAD91,0xC53754F2,0xC595E50A,0xC5C50532,0xC6333462,0xC6B5D32D,0xC6D7DC21,0xC70D0400,0xC73B2506,0xC7B98EC5,0xC7CFA946,0xC853262C,0xC8D7DF47,0xC930FA84,0xC95331BB,0xC98A9F90,0xC9AC77AB,0xC9B3825B,0xC9B4BADF,0xC9F9B733,0xCA345D91,0xCA419C48,0xCACC016E,0xCAD3F242,0xCAEBB1A0,0xCAFA4039,0xCB0D4830,0xCB241D53,0xCB8065FA,0xCBF5C49E,0xCC3460B7,0xCC6BDB7E,0xCC6DC7AC,0xCC71367E,0xCCA8F943,0xCCD3926E,0xCCD95561,0xCCFA435F,0xCD67F1F7,0xCDD02564,0xCDF0CE91,0xCDF5C7C4,0xCED39594,0xD04515D2,0xD05E15AA,0xD18CEABF,0xD19E5C79,0xD1E60C9E,0xD203B608,0xD208E8AB,0xD2B9A016,0xD2C519A9,0xD2CBE900,0xD3E1E2AF,0xD41C8FB1,0xD44538FA,0xD446A4C7,0xD4B9A33C,0xD4E6E3E4,0xD503CDEA,0xD54D16B9,0xD55771CE,0xD55CFAAF,0xD5E245F2,0xD5F43016,0xD7347208,0xD7348271,0xD787C85F,0xD7FA54B0,0xD822C764,0xD8311221,0xD8C379CD,0xD8DE413D,0xD9E81AFF,0xD9EDCF36,0xD9EE8E62,0xDA2DE244,0xDA3B42EF,0xDA4F123F,0xDA62A687,0xDACFC72F,0xDAED48C0,0xDAF5DC3B,0xDAFA14B3,0xDB0156ED,0xDB6B353F,0xDB8314FF,0xDC2AEC3F,0xDC4E3915,0xDCD03D01,0xDD347B7A,0xDDEF486B,0xDDFA5E22,0xDDFDE10D,0xDE1C9F6F,0xDE71BEC8,0xDE8CFF36,0xDE96704F,0xDEA9B101,0xDEB4DBEE,0xDEC82A52,0xDEFC15F1,0xDF175A04,0xDF715467,0xDFA33D2E,0xE02DEBB6,0xE03B470E,0xE05AF722,0xE07F96D3,0xE0B3DE6C,0xE0E25743,0xE0F0EC7A,0xE0F5E5AD,0xE14D1681,0xE1D52E73,0xE23531D0,0xE2CF6E79,0xE3055593,0xE37655A4,0xE3C2984B,0xE3C7926C,0xE487DCD6,0xE4D24A4E,0xE562AB48,0xE58122A4,0xE5DBA35D,0xE5FB4AE7,0xE6057A9B,0xE6F2531B,0xE715E833,0xE72AFD90,0xE73539AF,0xE7BCA0FC,0xE7D73493,0xE8349D34,0xE8BA5165,0xE8FC39C2,0xE93025A6,0xE9CC0D35,0xEA3C6BD0,0xEA9CEFAB,0xEB0DB0AB,0xEB84ED81,0xEBA585E6,0xEC48A6D3,0xEC4F2E95,0xEC8E2E20,0xED45ED5B,0xEDB3F2E3,0xEEDBB188,0xEF0D7842,0xEF515928,0xEF963BC5,0xF03C7542,0xF0453BFB,0xF04F9361,0xF06D8280,0xF0CA4D8F,0xF0D551EB,0xF0FEAFD8,0xF11B9B12,0xF14F94F4,0xF1B4CE5E,0xF1BA5F90,0xF1D2C19A,0xF21FA277,0xF2BC5E75,0xF2C7AA09,0xF30ED245,0xF3976575,0xF3B4D184,0xF3BB55C4,0xF46D43D3,0xF4813A41,0xF48DBFF4,0xF54BFFBD,0xF56B5E2D,0xF57C9009,0xF5D08ED8,0xF759C48B,0xF76D88A5,0xF7976BC1,0xF80576A2,0xF82E032B,0xF88ECEE6,0xF89649F0,0xF8C2B95A,0xF8CB98B6,0xF8ED77FA,0xFA8B2068,0xFACD70F6,0xFB925FCA,0xFB9D5051,0xFBDBAEC6,0xFC160942,0xFC48C003,0xFC8ED532,0xFCA8DB19,0xFCD755A2,0xFD274F45,
        0xFD7EA503,0xFDDBB1EC,0xFDEB86D4,0xFE1BAF89,0xFE4C0DE8,0xFEA5A3CF,0xFEA8DE3F,0xFF72C455,0xFF9D10BA,0xFFF9C7D1
        };
	
    uint32 TextToKeywordID(const GView::View::LexicalViewer::TextParser& text, uint32 start, uint32 end)
    {
        auto res = BinarySearch(text.ComputeHash32(start, end, false), list, 992);
        if (res == -1)
            return TokenType::None;
        return 1000 + res;
    };
} // namespace Keyword

namespace Constant
{
    uint32 list[] = { 0x0B069958, 0x2F8F13BA, 0x4DB211E5, 0x77074BA4 };

    uint32 TextToConstantID(const GView::View::LexicalViewer::TextParser& text, uint32 start, uint32 end)
    {
        auto res = BinarySearch(text.ComputeHash32(start, end, false), list, 4);
        if (res == -1)
            return TokenType::None;
        return 8000 + res;
    };
} // namespace Constant

namespace Datatype
{
    uint32 list[] = {
        0x1D334E0F, 0x645A021F, 0x6A98E9FD, 0x8DF098B4
    };

    uint32 TextToDatatypeID(const GView::View::LexicalViewer::TextParser& text, uint32 start, uint32 end)
    {
        auto res = BinarySearch(text.ComputeHash32(start, end, false), list, 4);
        if (res == -1)
            return TokenType::None;
        return 6000 + res;
    };
} // namespace Datatype

namespace Operators
{

    struct OperatorPair
    {
        uint32 tokenType;
        uint32 hash;
    };

    uint8 chars_ids[128]          = { 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,  0, 0,  0,
                                      0, 13, 0, 0, 0, 6, 9, 0, 0, 0, 4, 2, 0, 3, 16, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 7,  1, 8,  12,
                                      0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0,  0, 10, 0,
                                      0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 11, 0, 14, 0 };
    constexpr uint32 HASH_DEVIDER = 265;
    OperatorPair operator_hash_table[HASH_DEVIDER] = { { TokenType::None, 0 },
                                                       { TokenType::Operator_Assignment, 0x00000001 },
                                                       { TokenType::Operator_Plus, 0x00000002 },
                                                       { TokenType::Operator_Minus, 0x00000003 },
                                                       { TokenType::Operator_Multiply, 0x00000004 },
                                                       { TokenType::Operator_Division, 0x00000005 },
                                                       { TokenType::Operator_Modulo, 0x00000006 },
                                                       { TokenType::Operator_Smaller, 0x00000007 },
                                                       { TokenType::Operator_Bigger, 0x00000008 },
                                                       { TokenType::Operator_AND, 0x00000009 },
                                                       { TokenType::Operator_XOR, 0x0000000a },
                                                       { TokenType::Operator_OR, 0x0000000b },
                                                       { TokenType::Operator_Condition, 0x0000000c },
                                                       { TokenType::Operator_LogicalNOT, 0x0000000d },
                                                       { TokenType::Operator_NOT, 0x0000000e },
                                                       { TokenType::Operator_TWO_POINTS, 0x0000000f },
                                                       { TokenType::Operator_MemberAccess, 0x00000010 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_AndAssignment, 0x00000121 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_UnsignedRightShiftAssignment, 0x00042101 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_LogicAND, 0x00000129 },
                                                       { TokenType::Operator_Equal, 0x00000021 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_ArrowFunction, 0x00000028 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_XorAssignment, 0x00000141 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_PlusAssignment, 0x00000041 },
                                                       { TokenType::Operator_Increment, 0x00000042 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_OrAssignment, 0x00000161 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_StrictDifferent, 0x00003421 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_MinusAssignment, 0x00000061 },
                                                       { TokenType::Operator_LogicOR, 0x0000016b },
                                                       { TokenType::Operator_Decrement, 0x00000063 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_MupliplyAssignment, 0x00000081 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_Exponential, 0x00000084 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_Different, 0x000001a1 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_DivisionAssignment, 0x000000a1 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_ModuloAssignment, 0x000000c1 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_LogicNullishAssignment, 0x00003181 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_LogicORAssignment, 0x00002d61 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_SmallerOrEQ, 0x000000e1 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_LogicANDAssignment, 0x00002521 },
                                                       { TokenType::Operator_LeftShift, 0x000000e7 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_RightShiftAssignment, 0x00002101 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_LeftShiftAssignment, 0x00001ce1 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_SignRightShift, 0x00002108 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_ExponentiationAssignment, 0x00001081 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_BiggerOrEq, 0x00000101 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_StrictEqual, 0x00000421 },
                                                       { TokenType::None, 0 },
                                                       { TokenType::Operator_RightShift, 0x00000108 } };

    uint32 TextToOperatorID(const char16* txt, uint32 size, uint32& opSize)
    {
        // compute the hashes over the entire 3 cases
        uint32 hash1 = 0, hash2 = 0, hash3 = 0, hash4 = 0;
        if (((*txt) < 128) && (chars_ids[*txt] != 0))
        {
            hash1 = chars_ids[*txt];
            txt++;
            if ((size > 1) && ((*txt) < 128) && (chars_ids[*txt] != 0))
            {
                hash2 = (hash1 << 5) + chars_ids[*txt];
                txt++;
                if ((size > 2) && ((*txt) < 128) && (chars_ids[*txt] != 0))
                {
                    hash3 = (hash2 << 5) + chars_ids[*txt];
                    txt++;
                    if ((size > 3) && ((*txt) < 128) && (chars_ids[*txt] != 0))
                        hash4 = (hash3 << 5) + chars_ids[*txt];
                }
            }
        }
        {
            auto op = operator_hash_table[hash4 % HASH_DEVIDER];
            if ((op.tokenType != TokenType::None) && (op.hash == hash4))
            {
                opSize = 4;
                return op.tokenType;
            }
        }
        {
            auto op = operator_hash_table[hash3 % HASH_DEVIDER];
            if ((op.tokenType != TokenType::None) && (op.hash == hash3))
            {
                opSize = 3;
                return op.tokenType;
            }
        }
        {
            auto op = operator_hash_table[hash2 % HASH_DEVIDER];
            if ((op.tokenType != TokenType::None) && (op.hash == hash2))
            {
                opSize = 2;
                return op.tokenType;
            }
        }
        {
            auto op = operator_hash_table[hash1 % HASH_DEVIDER];
            if ((op.tokenType != TokenType::None) && (op.hash == hash1))
            {
                opSize = 1;
                return op.tokenType;
            }
        }
        return TokenType::None; // invalid operator
    }
} // namespace Operators

namespace CharType
{
    constexpr uint8 Word              = 0;
    constexpr uint8 Number            = 1;
    constexpr uint8 Operator          = 2;
    constexpr uint8 Comma             = 3;
    constexpr uint8 Semicolumn        = 4;
    constexpr uint8 Preprocess        = 5;
    constexpr uint8 String            = 6;
    constexpr uint8 BlockOpen         = 7;
    constexpr uint8 BlockClose        = 8;
    constexpr uint8 MemAddrOpen       = 9;
    constexpr uint8 MemAddrClose      = 10;
    constexpr uint8 ExpressionOpen    = 11;
    constexpr uint8 ExpressionClose   = 12;
    constexpr uint8 Space             = 13;
    constexpr uint8 Invalid           = 14;
    constexpr uint8 SingleLineComment = 15; // virtual (not in Cpp_Groups_IDs)
    constexpr uint8 Comment           = 16; // virtual (not in Cpp_Groups_IDs)
    constexpr uint8 Backquote         = 17;
    constexpr uint8 NewLine           = 18;
    constexpr uint8 Directive         = 19;


    uint8 Cpp_Groups_IDs[] = { Invalid,Invalid,Invalid,Invalid,Invalid,Invalid,Invalid,
                               Invalid,Invalid,Space,NewLine,Invalid,Invalid,NewLine,
                               Invalid,Invalid,Invalid,Invalid,Invalid,Invalid,Invalid,
                               Invalid,Invalid,Invalid,Invalid,Invalid,Invalid,Invalid,
                               Invalid,Invalid,Invalid,Invalid,Space,Operator,String,
                               Comment,Invalid,Operator,Operator,String,ExpressionOpen,
                               ExpressionClose,Operator,Operator,Comma,Operator,Directive,Operator,
                               Number,Number,Number,Number,Number,Number,Number,
                               Number,Number,Number,Operator,Semicolumn,Operator,Operator,
                               Operator,Operator,Invalid,Word,Word,Word,Word,
                               Word,Word,Word,Word,Word,Word,Word,
                               Word,Word,Word,Word,Word,Word,Word,
                               Word,Word,Word,Word,Word,Word,Word,
                               Word,MemAddrOpen,Operator,MemAddrClose,Operator,Word,Invalid,
                               Word,Word,Word,Word,Word,Word,Word,
                               Word,Word,Word,Word,Word,Word,Word,
                               Word,Word,Word,Word,Word,Word,Word,
                               Word,Word,Word,Word,Word,BlockOpen,Operator,
                               BlockClose,Operator,Invalid};


    // uint8 Cpp_Groups_IDs[] = { Invalid,    Invalid,  Invalid,    Invalid,    Invalid,   Invalid,        Invalid,
    //                           Invalid,    Invalid,  Space,      NewLine,    Invalid,   Invalid,        NewLine,
    //                           Invalid,    Invalid,  Invalid,    Invalid,    Invalid,   Invalid,        Invalid,
    //                           Invalid,    Invalid,  Invalid,    Invalid,    Invalid,   Invalid,        Invalid,
    //                           Invalid,    Invalid,  Invalid,    Invalid,    Space,     Operator,       String,
    //                           Preprocess, Invalid,  Operator,   Operator,   String,    ExpressionOpen, ExpressionClose,
    //                           Operator,   Operator, Comma,      Operator,   Operator,  Operator,       Number,
    //                           Number,     Number,   Number,     Number,     Number,    Number,         Number,
    //                           Number,     Number,   Operator,   Semicolumn, Operator,  Operator,       Operator,
    //                           Operator,   Invalid,  Word,       Word,       Word,      Word,           Word,
    //                           Word,       Word,     Word,       Word,       Word,      Word,           Word,
    //                           Word,       Word,     Word,       Word,       Word,      Word,           Word,
    //                           Word,       Word,     Word,       Word,       Word,      Word,           Word,
    //                           MemAddrOpen,  Operator, MemAddrClose, Operator,   Word,      Backquote,      Word,
    //                           Word,       Word,     Word,       Word,       Word,      Word,           Word,
    //                           Word,       Word,     Word,       Word,       Word,      Word,           Word,
    //                           Word,       Word,     Word,       Word,       Word,      Word,           Word,
    //                           Word,       Word,     Word,       Word,       BlockOpen, Operator,       BlockClose,
    //                           Operator,   Invalid };

    inline uint32 GetCharType(char16 c)
    {
        if (c < ARRAY_LEN(Cpp_Groups_IDs))
            return Cpp_Groups_IDs[c];
        return Invalid;
    }
} // namespace CharType

ASMFile::ASMFile()
{
}

bool ASMFile::Update()
{
    return true;
}
uint32 ASMFile::TokenizeWord(const GView::View::LexicalViewer::TextParser& text, TokensList& tokenList, uint32 pos)
{
    auto next = text.Parse(
          pos,
          [](char16 ch)
          {
              auto type = CharType::GetCharType(ch);
              return (type == CharType::Word) || (type == CharType::Number);
          });
    auto tokColor = TokenColor::Word;
    auto tokType  = Keyword::TextToKeywordID(text, pos, next);
    auto align    = TokenAlignament::None;
    auto opID     = 0U;
    auto flags    = TokenFlags::None;

    if (tokType == TokenType::None)
    {
        tokType = Constant::TextToConstantID(text, pos, next);
        if (tokType == TokenType::None)
        {
            tokType = Datatype::TextToDatatypeID(text, pos, next);
            if (tokType == TokenType::None)
            {
                tokType              = TokenType::Word;
                const auto lastToken = tokenList.GetLastTokenID();
                if (TokenType::IsClassicKeyword(lastToken))
                {
                    align = TokenAlignament::AddSpaceAfter;
                }
                else
                {
                    align = TokenAlignament::AddSpaceAfter | TokenAlignament::AddSpaceBefore;
                }
            }
            else
            {
                tokColor = TokenColor::Datatype;
            }
        }
        else
        {
            tokColor = TokenColor::Constant;
            flags    = TokenFlags::DisableSimilaritySearch;
        }
    }
    else
    {
        tokColor = TokenColor::Keyword;
        align    = TokenAlignament::AddSpaceAfter | TokenAlignament::AddSpaceBefore;
        flags    = TokenFlags::DisableSimilaritySearch;

        switch (tokType)
        {
        /* case TokenType::Keyword_Else:
            if (tokenList.GetLastTokenID() == TokenType::BlockClose)
            {
                align = align | TokenAlignament::AfterPreviousToken;
            }
            break;
        case TokenType::Keyword_If:
        case TokenType::Keyword_While:
        case TokenType::Keyword_For:
            align = align | TokenAlignament::StartsOnNewLine;
            break;*/
        default:
            break;
        }
    }
    /*
    if (next - pos > SIZABLE_VALUE)
        flags = flags | TokenFlags::Sizeable;
        */
    tokenList.Add(tokType, pos, next, tokColor, TokenDataType::None, align, flags | TokenFlags::Sizeable);
    return next;
}

int32 ASMFile::ParseRegEx(const GView::View::LexicalViewer::TextParser& text, TokensList& tokenList, uint32 pos)
{
    if (pos <= 0)
        return -1;
    auto lastTokenType = tokenList.GetLastToken().GetTypeID(TokenType::None);
    if (lastTokenType != TokenType::Operator_TWO_POINTS && lastTokenType != TokenType::Operator_Assignment &&
        lastTokenType != TokenType::MemAddrOpen)
        return -1;
    if (text[pos - 1] == '\\')
        return -1;
    while (pos < text.Len())
    {
        pos++;
        auto ch = text[pos];
        auto previewCh = text[pos - 1];
        if (ch == '/' && previewCh != '\\')
        {
            return pos + 1;
		}   
	}
    return -1;
}
uint32 ASMFile::TokenizeOperator(const GView::View::LexicalViewer::TextParser& text, TokensList& tokenList, uint32 pos)
{
    auto next = text.ParseSameGroupID(pos, CharType::GetCharType);
    uint32 next2;
    auto txt = text.GetSubString(pos, next);
    uint32 tokenType, sz;
    tokenType = Operators::TextToOperatorID(txt.data(), (uint32) txt.size(), sz);
    if (tokenType != TokenType::None)
    {
        TokenAlignament align = TokenAlignament::AddSpaceBefore | TokenAlignament::AddSpaceAfter;
        switch (tokenType)
        {
        case TokenType::Operator_MemberAccess:
            align = TokenAlignament::AfterPreviousToken;
            break;
        case TokenType::Operator_Assignment:
        case TokenType::Operator_PlusAssignment:
            align = TokenAlignament::SameColumn | TokenAlignament::AddSpaceAfter | TokenAlignament::AddSpaceBefore;
            break;
        case TokenType::Operator_Minus:
            next2 = text.ParseSpace(pos + 1);
            if (CharType::GetCharType(text[next2]) == CharType::Number)
            {
                // x = - 5
                if (TokenType::IsOperator(tokenList.GetLastTokenID()))
                {
                    next = text.ParseNumber(next2);
                    LocalUnicodeStringBuilder<128> tmp;
                    tmp.AddChar('-');
                    tmp.Add(text.GetSubString(next2, next));
                    auto t = tokenList.Add(TokenType::Number, pos, next, TokenColor::Number, TokenDataType::Number);
                    t.SetText(tmp);
                    // tokenList.Add(TokenType::Number, pos, next, TokenColor::Number, TokenDataType::Number);
                    return next;
                }
            }
            break;
        case TokenType::Operator_Division:
        {
            auto next2 = ParseRegEx(text, tokenList, pos);
            if (next2 != -1)
            {
                align = align | TokenAlignament::WrapToNextLine;
                tokenList.Add(TokenType::RegEx, pos, next2, TokenColor::String, TokenDataType::None, align, TokenFlags::DisableSimilaritySearch);
				return next2;
			}
            break;
        }
            /*
            case TokenType::Assign:
            case TokenType::PlusEQ:
            case TokenType::MinusEQ:
            case TokenType::MupliplyEQ:
            case TokenType::DivisionEQ:
            case TokenType::ModuloEQ:
            case TokenType::AndEQ:
            case TokenType::OrEQ:
            case TokenType::XorEQ:
            case TokenType::RightShiftEQ:
            case TokenType::LeftShiftEQ:
                align |= TokenAlignament::SameColumn;
                break;
                */
        }

        align = align | TokenAlignament::WrapToNextLine;
        tokenList.Add(tokenType, pos, pos + sz, TokenColor::Operator, TokenDataType::None, align, TokenFlags::DisableSimilaritySearch);
        return pos + sz;
    }
    else
    {
        // unknown operator
        tokenList.Add(TokenType::Word, pos, next, TokenColor::Word).SetError("Invalid ASM operator");
        return next;
    }
}

BlockType ASMFile::GetBlockTypeWhichContainLastToken(const TokensList& tokenList)
{
    TokenIndexStack blockToken;

    auto indexArrayBlock      = 0u;
    auto len                  = tokenList.Len();
    Token currentToken        = tokenList.GetLastToken();
    uint32_t currentTokenType = currentToken.GetTypeID(TokenType::None);
    while (currentTokenType != TokenType::None)
    {
        switch (currentTokenType)
        {
        case TokenType::BlockClose:
        case TokenType::ExpressionClose:
        case TokenType::MemAddrClose:
            blockToken.Push(currentToken.GetIndex());
            break;
        case TokenType::BlockOpen:
        {
            auto lastBlock = blockToken.Pop();
            if (lastBlock == Token::INVALID_INDEX)
                return BlockType::Block;
            if (tokenList[lastBlock].GetTypeID(TokenType::None) != TokenType::BlockClose)
                return BlockType::None;
            break;
        }
        case TokenType::ExpressionOpen:
        {
            auto lastBlock = blockToken.Pop();
            if (lastBlock == Token::INVALID_INDEX)
                return BlockType::Expression;
            if (tokenList[lastBlock].GetTypeID(TokenType::None) != TokenType::ExpressionClose)
                return BlockType::None;
            break;
        }
        case TokenType::MemAddrOpen:
        {
            auto lastBlock = blockToken.Pop();
            if (lastBlock == Token::INVALID_INDEX)
                return BlockType::Array;
            if (tokenList[lastBlock].GetTypeID(TokenType::None) != TokenType::MemAddrClose)
                return BlockType::None;
            break;
        }
        }
        currentToken     = currentToken.Precedent();
        currentTokenType = currentToken.GetTypeID(TokenType::None);
    }
    return BlockType::None;
}

uint32 ASMFile::TokenizeList(const TextParser& text, TokensList& tokenList, uint32 idx)
{
    TokenAlignament align = TokenAlignament::AddSpaceBefore | TokenAlignament::AddSpaceAfter;

    Token token = tokenList.GetLastToken();
    if (GetBlockTypeWhichContainLastToken(tokenList) == BlockType::Block)
        align |= TokenAlignament::NewLineAfter;
    else
        align |= TokenAlignament::WrapToNextLine;

    tokenList.Add(TokenType::Comma, idx, idx + 1, TokenColor::Operator, TokenDataType::None, align, TokenFlags::DisableSimilaritySearch);
    idx++;
    return idx;
}
uint32 ASMFile::TokenizePreprocessDirective(const TextParser& text, TokensList& list, BlocksList& blocks, uint32 pos)
{
    auto eol   = text.ParseUntillEndOfLine(pos);
    auto start = pos;
    pos        = text.ParseSpace(pos + 1, SpaceType::SpaceAndTabs);
    if ((CharType::GetCharType(text[pos])) != CharType::Word)
    {
        // we have an error
        list.Add(TokenType::Preprocess,
                 start,
                 eol,
                 TokenColor::Preprocesor,
                 TokenAlignament::StartsOnNewLine | TokenAlignament::NewLineAfter)
              .SetError("Invalid preprocess directive");
        return eol;
    }
    // we have a good preprocess directive ==> lets formalize it
    auto next = text.ParseSameGroupID(pos, CharType::GetCharType);
    list.Add(
          TokenType::Preprocess,
          start,
          eol /*next*/,
          TokenColor::Preprocesor,
          TokenAlignament::StartsOnNewLine | TokenAlignament::AddSpaceAfter | TokenAlignament::NewLineAfter);

    // auto tknIndex = list.Len();
    // Tokenize(next, eol, text, list, blocks);
    // auto tknCount = list.Len();
    //// change the color of every added token
    // for (auto index = tknIndex; index < tknCount; index++)
    //     list[index].SetTokenColor(TokenColor::Preprocesor);
    //// make sure that last token has a new line after it
    // list.GetLastToken().UpdateAlignament(TokenAlignament::NewLineAfter);
    //// crete a block
    // blocks.Add(tknIndex - 1, tknCount-1, BlockAlignament::AsBlockStartToken);

    return eol;
}
void ASMFile::BuildBlocks(GView::View::LexicalViewer::SyntaxManager& syntax)
{
    TokenIndexStack stBlocks;
    TokenIndexStack exprBlocks;
    TokenIndexStack arrayBlocks;
    auto indexArrayBlock = 0u;
    auto len             = syntax.tokens.Len();
    for (auto index = 0U; index < len; index++)
    {
        auto typeID = syntax.tokens[index].GetTypeID(TokenType::None);
        switch (typeID)
        {
        case TokenType::BlockOpen:
            stBlocks.Push(index);
            break;
        case TokenType::BlockClose:
            syntax.blocks.Add(stBlocks.Pop(), index, BlockAlignament::ParentBlockWithIndent, BlockFlags::EndMarker);
            break;
        case TokenType::ExpressionOpen:
            exprBlocks.Push(index);
            break;
        case TokenType::ExpressionClose:
            syntax.blocks.Add(exprBlocks.Pop(), index, BlockAlignament::CurrentToken, BlockFlags::EndMarker | BlockFlags::ManualCollapse);
            break;
        case TokenType::MemAddrOpen:
            arrayBlocks.Push(index);
            break;
        case TokenType::MemAddrClose:
            indexArrayBlock = arrayBlocks.Pop();
            if (indexArrayBlock < index)
            {
                if (index - indexArrayBlock >= 5)
                    syntax.blocks.Add(indexArrayBlock, index, BlockAlignament::CurrentToken, BlockFlags::EndMarker);
                else
                    syntax.blocks.Add(
                          indexArrayBlock, index, BlockAlignament::CurrentToken, BlockFlags::EndMarker | BlockFlags::ManualCollapse);
            }
            break;
        }
    }
}
void ASMFile::Tokenize(const TextParser& text, TokensList& tokenList, BlocksList& blocks)
{
    Tokenize(0, text.Len(), text, tokenList, blocks);
}
void ASMFile::Tokenize(uint32 start, uint32 end, const TextParser& text, TokensList& tokenList, BlocksList& blocks)
{
    auto idx     = start;
    auto next    = 0U;
    bool newLine = false;
    while (idx < end)
    {
        auto ch   = text[idx];
        auto type = CharType::GetCharType(ch);

        // check for comments
        if (ch == '/')
        {
            auto next = text[idx + 1];
            if (next == '/')
                type = CharType::SingleLineComment;
            else if (next == '*')
                type = CharType::Comment;
        }
        switch (type)
        {
        case CharType::NewLine:
            idx     = text.ParseSpace(idx, SpaceType::NewLine);
            newLine = true;
            break;
        case CharType::Space:
            idx = text.ParseSpace(idx, SpaceType::SpaceAndTabs);
            break;
        case CharType::SingleLineComment:
            next = text.ParseUntillEndOfLine(idx);
            tokenList.Add(
                  TokenType::Comment,
                  idx,
                  next,
                  TokenColor::Comment,
                  TokenDataType::MetaInformation,
                  TokenAlignament::NewLineAfter | TokenAlignament::AddSpaceBefore,
                  TokenFlags::DisableSimilaritySearch);
            idx = next;
            break;
        case CharType::Comment:
            next = text.ParseUntilNextCharacterAfterText(idx, "*/", false);
            tokenList.Add(
                  TokenType::Comment,
                  idx,
                  next,
                  TokenColor::Comment,
                  TokenDataType::MetaInformation,
                  TokenAlignament::AddSpaceBefore | TokenAlignament::AddSpaceAfter,
                  TokenFlags::DisableSimilaritySearch);
            idx = next;
            break;
        case CharType::MemAddrOpen:
            tokenList.Add(
                  TokenType::MemAddrOpen,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::None,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::MemAddrClose:
            tokenList.Add(
                  TokenType::MemAddrClose,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::None,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::ExpressionOpen:
            tokenList.Add(
                  TokenType::ExpressionOpen,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::AfterPreviousToken,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::ExpressionClose:
            tokenList.Add(
                  TokenType::ExpressionClose,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::AfterPreviousToken,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::BlockOpen:
            tokenList.Add(
                  TokenType::BlockOpen,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::NewLineAfter | TokenAlignament::StartsOnNewLine,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::BlockClose:
            tokenList.Add(
                  TokenType::BlockClose,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::StartsOnNewLine | TokenAlignament::NewLineAfter | TokenAlignament::ClearIndentAfterPaint,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::Number:
            next = text.ParseNumber(idx);
            if (next - idx > SIZABLE_VALUE)
                tokenList.Add(
                      TokenType::Number, idx, next, TokenColor::Number, TokenDataType::Number, TokenAlignament::None, TokenFlags::Sizeable);
            else
                tokenList.Add(TokenType::Number, idx, next, TokenColor::Number, TokenDataType::Number);
            idx = next;
            break;
        case CharType::String:
            next = text.ParseString(idx, StringFormat::DoubleQuotes | StringFormat::SingleQuotes | StringFormat::AllowEscapeSequences);
            if (next - idx > SIZABLE_VALUE)
                tokenList.Add(
                      TokenType::String, idx, next, TokenColor::String, TokenDataType::String, TokenAlignament::None, TokenFlags::Sizeable);
            else
                tokenList.Add(TokenType::String, idx, next, TokenColor::String, TokenDataType::String);
            idx = next;
            break;
        case CharType::Backquote:
            // De adaugat si ${}
            next = text.ParseString(idx, StringFormat::Apostrophe);
            tokenList.Add(TokenType::String, idx, next, TokenColor::String, TokenDataType::String);
            idx = next;
            break;
        case CharType::Comma:
            idx = TokenizeList(text, tokenList, idx);
            break;
        case CharType::Semicolumn:
            tokenList.Add(
                  TokenType::Semicolumn,
                  idx,
                  idx + 1,
                  TokenColor::Operator,
                  TokenDataType::None,
                  TokenAlignament::NewLineAfter | TokenAlignament::AfterPreviousToken | TokenAlignament::ClearIndentAfterPaint,
                  TokenFlags::DisableSimilaritySearch);
            idx++;
            break;
        case CharType::Preprocess:
            idx = TokenizePreprocessDirective(text, tokenList, blocks, idx);
            break;
        case CharType::Word:
            idx = TokenizeWord(text, tokenList, idx);
            break;
        case CharType::Operator:
            idx = TokenizeOperator(text, tokenList, idx);
            break;
        default:
            next = text.ParseSameGroupID(idx, CharType::GetCharType);
            tokenList.Add(TokenType::Word, idx, next, TokenColor::Word, TokenDataType::MetaInformation)
                  .SetError("Invalid character sequance");
            idx = next;
            break;
        }
        if (newLine && type != CharType::NewLine)
        {
            tokenList.GetLastToken().UpdateAlignament(TokenAlignament::StartsOnNewLine);
            newLine = false;
        }
    }
}
void ASMFile::IndentSimpleInstructions(GView::View::LexicalViewer::TokensList& list)
{
    /*
    auto len = list.Len();
    auto idx = 0U;
    while (idx < len)
    {
        auto typeID = list[idx].GetTypeID(TokenType::None);
        if ((typeID == (TokenType::Keyword | (KeywordsType::If << 16))) || (typeID == (TokenType::Keyword | (KeywordsType::While << 16))) ||
            (typeID == (TokenType::Keyword | (KeywordsType::For << 16))))
        {
            if (list[idx + 1].GetTypeID(TokenType::None) == TokenType::ExpressionOpen)
            {
                auto block = list[idx + 1].GetBlock();
                if (block.IsValid())
                {
                    auto endToken = block.GetEndToken();
                    if (endToken.IsValid())
                    {
                        // we have the following format if|while|for follower by (...)
                        auto nextTok = list[endToken.GetIndex() + 1];
                        if ((nextTok.IsValid()) && (nextTok.GetTypeID(TokenType::None) != TokenType::BlockOpen))
                        {
                            nextTok.UpdateAlignament(TokenAlignament::IncrementIndentBeforePaint | TokenAlignament::StartsOnNewLine);
                        }
                        // if the case is for
                        if (typeID == (TokenType::Keyword | (KeywordsType::For << 16)))
                        {
                            // search for every ';' between (...) and remove any new line
                            auto endTokID = endToken.GetIndex();
                            for (auto tkIdx = idx + 2; tkIdx < endTokID; tkIdx++)
                            {
                                auto currentTok = list[tkIdx];
                                if (currentTok.GetTypeID(TokenType::None) == TokenType::Semicolumn)
                                    currentTok.SetAlignament(TokenAlignament::AddSpaceAfter | TokenAlignament::AddSpaceBefore);
                            }
                        }
                    }
                }
            }
        }
        idx++;
    }*/
}
void ASMFile::CreateFoldUnfoldLinks(GView::View::LexicalViewer::SyntaxManager& syntax)
{
    /* Search for the following cases
     * for|if|while|switch (...) {...} and add collapse/expand on for|if and while
     * word (...) {...} or word (...) cons {...} and add collapse/expand on word
     * do {...} while (...) -> both do and while should compact the {...}
     */
    /*
    auto len = syntax.blocks.Len();
    for (auto idx = 0U; idx < len; idx++)
    {
        auto block = syntax.blocks[idx];
        // search for {...} blocks
        auto startToken = block.GetStartToken();
        if (startToken.GetTypeID(TokenType::None) != TokenType::BlockOpen)
            continue;
        auto precToken = startToken.Precedent();
        auto precTokenID = precToken.GetTypeID(TokenType::None);
        if (precTokenID == (TokenType::Keyword | (KeywordsType::Else << 16)))
        {
            // found else {...} case ==> make sure that else can fold/unfold the next block
            precToken.SetBlock(block);
            continue;
        }
        if (precTokenID == (TokenType::Keyword | (KeywordsType::Do << 16)))
        {
            // found else do {...} case ==> make sure that 'do' token can fold/unfold the next block
            precToken.SetBlock(block);
            // check for do {...} while
            auto endToken = block.GetEndToken();
            if (endToken.GetTypeID(TokenType::None) == TokenType::BlockClose)
            {
                auto nextToken = endToken.Next();
                if (nextToken.GetTypeID(TokenType::None) == (TokenType::Keyword | (KeywordsType::While << 16)))
                {
                    nextToken.SetBlock(block);
                    nextToken.SetAlignament(
                        TokenAlignament::AddSpaceBefore | TokenAlignament::AddSpaceAfter | TokenAlignament::AfterPreviousToken);
                }
            }
            continue;
        }

        if (precTokenID == (TokenType::Keyword | (KeywordsType::Const << 16)))
            precToken = precToken.Precedent();
        // at this point precToken should be a (...) block
        if (precToken.GetTypeID(TokenType::None) != TokenType::ExpressionClose)
            continue;
        auto targetToken = precToken.GetBlock().GetStartToken().Precedent();
        auto targetTokenID = targetToken.GetTypeID(TokenType::None);
        if ((targetTokenID == TokenType::Word) || ((targetTokenID & 0xFFFF) == TokenType::Keyword))
        {
            // all good
            targetToken.SetBlock(block);
        }
    }*/
}
void ASMFile::RemoveLineContinuityCharacter(TextEditor& editor)
{
    auto pos = 0;
    do
    {
        auto res = editor.Find(pos, "\\");
        if (!res.has_value())
            break;
        pos       = res.value() + 1;
        auto next = editor[pos];
        if ((next == '\n') || (next == '\r'))
        {
            auto nextAfterNext = editor[pos + 1];
            if (((nextAfterNext == '\n') || (nextAfterNext == '\r')) && (nextAfterNext != next))
            {
                // case like \CRLF or \LFCR
                editor.Delete(res.value(), 3);
            }
            else
            {
                // case line \CR or \LF
                editor.Delete(res.value(), 2);
            }
        }
    } while (true);
}
void ASMFile::PreprocessText(GView::View::LexicalViewer::TextEditor& editor)
{
    auto foundIE11Comment = false;
    do
    {
        auto res         = editor.Find(0, "/*@cc_on", true);
        foundIE11Comment = false;
        if (res.has_value())
        {
            auto next = editor.Find(res.value(), "@*/");
            if (next.has_value())
            {
                editor.Delete(next.value(), 3);
                editor.Delete(res.value(), 8);
                foundIE11Comment = true;
            }
        }
    } while (foundIE11Comment);
    // remove line continuity
    RemoveLineContinuityCharacter(editor);
}
void ASMFile::GetTokenIDStringRepresentation(uint32 id, AppCUI::Utils::String& str)
{
    switch (id)
    {
    case TokenType::None:
        str.Set("Unknwon/Error");
        break;
    case TokenType::Comment:
        str.Set("Comment");
        break;
    case TokenType::MemAddrOpen:
        str.Set("Array (open)");
        break;
    case TokenType::MemAddrClose:
        str.Set("Array (close)");
        break;
    case TokenType::BlockOpen:
        str.Set("Block (open)");
        break;
    case TokenType::BlockClose:
        str.Set("Block (close)");
        break;
    case TokenType::ExpressionOpen:
        str.Set("Expression (open)");
        break;
    case TokenType::ExpressionClose:
        str.Set("Expression (close)");
        break;
    case TokenType::Number:
        str.Set("Number constant");
        break;
    case TokenType::String:
        str.Set("String");
        break;
    case TokenType::Comma:
        str.Set("Separator (comma)");
        break;
    case TokenType::Semicolumn:
        str.Set("Separator (semicolumn)");
        break;
    case TokenType::Preprocess:
        str.Set("Preprocess directive");
        break;
    case TokenType::Word:
        str.Set("Word");
        break;
    case TokenType::RegEx:
        str.Set("Regular Expression");
        break;
    }
    if (TokenType::IsKeyword(id))
    {
        str.Set("Keyword");
    }
    if (TokenType::IsDatatype(id))
    {
        str.Set("Datatype");
    }
    if (TokenType::IsConstant(id))
    {
        str.Set("Constant");
    }
    if (TokenType::IsOperator(id))
    {
        str.Set("Operator");
    }
}
void ASMFile::AnalyzeText(GView::View::LexicalViewer::SyntaxManager& syntax)
{
    syntax.tokens.ResetLastTokenID(TokenType::None);
    Tokenize(syntax.text, syntax.tokens, syntax.blocks);
    BuildBlocks(syntax);
    OperatorAlignament(syntax.tokens);
    IndentSimpleInstructions(syntax.tokens);
    CreateFoldUnfoldLinks(syntax);
}
void ASMFile::OperatorAlignament(GView::View::LexicalViewer::TokensList& tokenList)
{
    auto len = tokenList.Len();
    for (auto index = 0u; index < len; index++)
    {
        Token t = tokenList[index];
        if (t.GetTypeID(TokenType::None) == TokenType::Operator_MemberAccess)
        {
            t.Next().UpdateAlignament(TokenAlignament::AfterPreviousToken, TokenAlignament::AddSpaceBefore);
        }

       /* if (t.GetTypeID(TokenType::None) == TokenType::Keyword_For && t.Next().GetTypeID(TokenType::None) == TokenType::ExpressionOpen)
        {
            auto idx = index + 1;
            auto end = t.Next().GetBlock().GetEndToken().GetIndex();
            for (; idx < end; idx++)
            {
                Token t2 = tokenList[idx];
                if (t2.GetTypeID(TokenType::None) == TokenType::Semicolumn)
                {
                    t2.Precedent().UpdateAlignament(TokenAlignament::None, TokenAlignament::AddSpaceAfter);
                    t2.SetAlignament(TokenAlignament::AddSpaceAfter);
                }
            }
            Token t3 = tokenList[end + 1];
            if (t3.GetTypeID(TokenType::None) == TokenType::BlockOpen)
            {
                t.SetBlock(t3.GetBlock());
            }
        }*/
    }
}
bool ASMFile::StringToContent(std::u16string_view string, AppCUI::Utils::UnicodeStringBuilder& result)
{
    return TextParser::ExtractContentFromString(
          string, result, StringFormat::DoubleQuotes | StringFormat::SingleQuotes | StringFormat::Apostrophe);
}
bool ASMFile::ContentToString(std::u16string_view content, AppCUI::Utils::UnicodeStringBuilder& result)
{
    UnicodeStringBuilder newContent;
    int32 preview = 0u;

    for (auto index = 0u; index < content.length(); index++)
    {
        if (index == 0)
        {
            if (content[index] == '`')
            {
                newContent.Add(content.substr(index - 1, index - preview));
                newContent.Add("\\'");
                preview = index + 1;
            }
        }
        else if (content[index] == '`' && content[index - 1] != '\\')
        {
            newContent.Add(content.substr(index - 1, index - preview));
            newContent.Add("\\'");
            preview = index + 1;
        }
    }
    if (preview != content.length())
    {
        newContent.Add(content.substr(preview, content.length() - preview));
    }
    result.Set("`");
    result.Add(newContent);
    result.Add("`");
    return true;
}
} // namespace GView::Type::ASM