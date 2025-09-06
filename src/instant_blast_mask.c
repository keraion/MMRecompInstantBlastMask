#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

#define CFG_IS_INSTANT_BLAST_MASK (recomp_get_config_u32("instant_blast_mask"))

typedef enum CfgBool {
  CFG_NO,
  CFG_YES
} CfgBool;

PlayState* playState;

RECOMP_CALLBACK("*", recomp_on_play_init)
void OnPlayInit(PlayState* play) {
    playState = play;
}

RECOMP_HOOK_RETURN("Player_ProcessItemButtons")
void updateBlastMaskTimer() {
    Player* player = GET_PLAYER(playState);
    if (CFG_IS_INSTANT_BLAST_MASK == CFG_YES ) {
        player->blastMaskTimer = 0;
    }
}
