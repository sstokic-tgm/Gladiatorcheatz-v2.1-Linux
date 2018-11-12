//CBoneAccessor
// Created by assemble on 12.11.18.
//


#pragma once

#include "../SDK.h"

class CBoneAccessor
{

public:

    inline matrix3x4_t *GetBoneArrayForWrite()
    {
        return m_pBones;
    }

    inline void SetBoneArrayForWrite(matrix3x4_t *bone_array)
    {
        m_pBones = bone_array;
    }

    alignas(16) matrix3x4_t *m_pBones;
    int32_t m_ReadableBones; // Which bones can be read.
    int32_t m_WritableBones; // Which bones can be written.
};
