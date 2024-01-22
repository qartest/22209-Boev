#include "wav_hdr.hpp"

namespace wav_hdr_functions{
    int GiveSeconds(wav_hdr input){
        if ((input.ChunkSize - 36) > 0){
            return ceil((input.ChunkSize - 36) / input.bytesPerSec);
        }
        return 0;
    }
}