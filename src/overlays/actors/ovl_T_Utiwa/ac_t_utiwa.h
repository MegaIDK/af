#ifndef AC_T_UTIWA_H
#define AC_T_UTIWA_H

#include "ultra64.h"
#include "m_actor.h"
#include "unk.h"
#include "overlays/actors/ovl_Tools/ac_tools.h"

struct Game_Play;
struct T_Utiwa;

typedef void (*T_UtiwaActionFunc)(struct T_Utiwa*);

typedef struct T_Utiwa {
    /* 0x000 */ ToolActor tool_actor;
    /* 0x1C0 */ UNK_TYPE1 unk_1C0[0x8];
    /* 0x1C8 */ T_UtiwaActionFunc unk_1C8;
    /* 0x1CC */ s32 unk_1CC;
} T_Utiwa; // size = 0x1D0

#endif
