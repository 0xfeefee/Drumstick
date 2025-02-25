
#pragma once

namespace drumstick {

    /*
        Disabling padding* in order to map directly with one { memcpy } when using
        { Data_View.get<File_Header>() } or when casting directly from { u8* };
    */
    #pragma pack(push, 1)
    struct File_Header {
        u8   version;
        char date_time[17];
        s16  row_count;     // (NY)
        s16  column_count;  // (NX)
        u8   level_count;   // (L)
        s16  distance;      // (in meters)
        u8   quant_count;   // (N)

        void
        print_self();
    };
    #pragma pack(pop)

}
