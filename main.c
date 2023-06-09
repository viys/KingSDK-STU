#include "app.h"
#include "KingPowerManage.h"

void APP_Main(uint32 bootMode)
{
    POWER_REASON_E reason = bootMode;
    KING_SysLog("enter APP_Main... reason = %d", reason);
    
    KING_WakeLock(LOCK_SUSPEND, (uint8 *)"KingApp");

    KING_SysLog("enter APP_Main... reason =END");

}
