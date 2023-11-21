#include "ac_t_utiwa.h"
#include "m_lib.h"
#include "m_actor_dlftbls.h"
#include "m_object.h"
#include "overlays/gamestates/ovl_play/m_play.h"

void aTUT_actor_ct(Actor* thisx, Game_Play* game_play);
void func_80A1FAC4_jp(Actor* actor, s32 arg1);
void func_80A1FB2C_jp(Actor *thisx);
void func_80A1FB4C_jp(Actor *thisx);
void func_80A1FB6C_jp();
void func_80A1FB8C_jp(Actor *arg0, s32 arg1);
void aTUT_actor_move(Actor* thisx, Game_Play* game_play);
void aTUT_actor_draw(Actor* thisx, Game_Play* game_play);

#if 0
ActorProfile T_Utiwa_Profile = {
    /* */ ACTOR_T_UTIWA,
    /* */ ACTOR_PART_4,
    /* */ ACTOR_FLAG_10 | ACTOR_FLAG_20,
    /* */ 0x0000,
    /* */ OBJECT_53,
    /* */ sizeof(T_Utiwa),
    /* */ aTUT_actor_ct,
    /* */ (void*)none_proc1,
    /* */ aTUT_actor_move,
    /* */ aTUT_actor_draw,
    /* */ NULL,
};
#endif

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/aTUT_actor_ct.s")
void aTUT_actor_ct(Actor *thisx, Game_Play *game_play) {
    func_80A1FB8C_jp(thisx, 0);
}

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/func_80A1FAC4_jp.s")
static f32 D_80A1FD24_jp[2] = { 1.0f, 0.0f };

void func_80A1FAC4_jp(Actor *thisx, s32 arg1)
{
  xyz_t* scale = &thisx->scale;
  f32 sp18 = scale->x;
  chase_f(&sp18, D_80A1FD24_jp[arg1], 0.1f);
  scale->x = sp18;
  scale->y = sp18;
  scale->z = sp18;
} 

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/func_80A1FB2C_jp.s")
void func_80A1FB2C_jp(Actor *thisx) {
    func_80A1FAC4_jp(thisx, 0);
}

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/func_80A1FB4C_jp.s")
void func_80A1FB4C_jp(Actor *thisx) {
    func_80A1FAC4_jp(thisx, 1);
}

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/func_80A1FB6C_jp.s")
void func_80A1FB6C_jp(Actor *thisx) {
    Actor_delete(thisx);
}

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/func_80A1FB8C_jp.s")
static void (*D_80A1FD2C_jp[5])(Actor *) = {
    func_80A1FB2C_jp,
    func_80A1FB4C_jp,
    func_80A1FB6C_jp,
    ((void (*)(Actor *)) none_proc1),
    NULL,
}; 
static f32 D_FLT_80A1FD40_jp[5] = { 0, 1, 1, 1, 0 };

void func_80A1FB8C_jp(Actor *thisx, s32 arg1) {
    f32 temp_fv0;
    T_Utiwa* this = (T_Utiwa*)thisx;

    this->unk_1C8 = (void (*)(Actor *)) D_80A1FD2C_jp[arg1];
    this->unk_1CC = arg1;
    temp_fv0 = D_FLT_80A1FD40_jp[arg1];
    this->tool_actor.actor.scale.x = temp_fv0;
    this->tool_actor.actor.scale.y = temp_fv0;
    this->tool_actor.actor.scale.z = temp_fv0;
}

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/aTUT_actor_move.s")
void aTUT_actor_move(Actor *thisx, Game_Play *game_play) {
    T_Utiwa* this = (T_Utiwa*)thisx;

    s32 pad;
    if (this->tool_actor.unk1BC != this->unk_1CC ) {
        func_80A1FB8C_jp(&this->tool_actor, this->tool_actor.unk1BC);
    }
    this->unk_1C8(&this->tool_actor);
}

//#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/actors/ovl_T_Utiwa/ac_t_utiwa/aTUT_actor_draw.s")
void func_800BD5E8_jp(GraphicsContext *);              /* extern */
extern Gfx D_6000080;
static xyz_t D_80A1FD54_jp = { 0.0f, 0.0f, 0.0f };

void aTUT_actor_draw(Actor *thisx, Game_Play *game_play) {
    T_Utiwa* this = (T_Utiwa*)thisx;
    GraphicsContext *sp38 = game_play->state.gfxCtx;
    //void *sp24;
    //void *temp_s0;
    //void *temp_s0_2;

    OPEN_DISPS(sp38);
    if (this->tool_actor.unk1B8 == 1) {
        Matrix_put(thisx + 0x178);
        Matrix_Position(&D_80A1FD54_jp, &thisx->world.pos);
        this->tool_actor.unk1B8 = 0;
    } else {
        Matrix_translate(thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z, 0U);
        Matrix_scale(0.01f, 0.01f, 0.01f, 1U);
    }
    Matrix_scale(thisx->scale.x, thisx->scale.y, thisx->scale.z, 1U);
    func_800BD5E8_jp(sp38);
    //temp_s0 = sp38->polyOpa.tha.head;
    //temp_s0->unk0 = 0xDA380003;
    //sp24 = temp_s0;
    //temp_s0->unk4 = _Matrix_to_Mtx_new(sp38);
    gSPMatrix(POLY_OPA_DISP++, _Matrix_to_Mtx_new(sp38), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    //temp_s0_2 = temp_s0 + 8;
    //temp_s0_2->unk4 = &D_6000080;
    //temp_s0_2->unk0 = 0xDE000000;
    //sp38->polyOpa.tha.head = temp_s0_2 + 8;
    gSPDisplayList(POLY_OPA_DISP++, &D_6000080);
    CLOSE_DISPS();
}