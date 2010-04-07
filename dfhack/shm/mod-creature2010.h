/*
www.sourceforge.net/projects/dfhack
Copyright (c) 2009 Petr Mrázek (peterix)

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any
damages arising from the use of this software.

Permission is granted to anyone to use this software for any
purpose, including commercial applications, and to alter it and
redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must
not claim that you wrote the original software. If you use this
software in a product, an acknowledgment in the product documentation
would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and
must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#ifndef MOD_CREATURES2010_H
#define MOD_CREATURES2010_H

namespace DFHack
{
    namespace Creatures2010
    {

#define CREATURES2010_VERSION 1
typedef struct
{
    // creature offsets
    uint32_t creature_vector;
    uint32_t creature_pos_offset;
    uint32_t creature_profession_offset;
    uint32_t creature_custom_profession_offset;
    uint32_t creature_race_offset;
    uint32_t creature_flags1_offset;
    uint32_t creature_flags2_offset;
    uint32_t creature_name_offset;
    uint32_t creature_sex_offset;
    uint32_t creature_id_offset;
    uint32_t creature_labors_offset;
    uint32_t creature_happiness_offset;
    uint32_t creature_artifact_name_offset;
    uint32_t creature_soul_vector_offset;
    // soul offsets
    uint32_t soul_skills_vector_offset;
    // name offsets (needed for reading creature names)
    uint32_t name_firstname_offset;
    uint32_t name_nickname_offset;
    uint32_t name_words_offset;
} creature_offsets;

typedef struct
{
    bool inited;
    creature_offsets offsets;
} creature_modulestate;

typedef struct
{
    shm_cmd cmd[SHM_MAX_CLIENTS]; // MANDATORY!
    // box
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t x2;
    uint32_t y2;
    uint32_t z2;
    // starting index
    int32_t index;
} shm_creature_hdr;

enum CREATURE_COMMAND
{
    CREATURE_INIT = 0, // initialization
    CREATURE_FIND_IN_BOX,
    CREATURE_AT_INDEX,
    NUM_CREATURE_CMDS
};
DFPP_module Init(void);

    }
}

#endif