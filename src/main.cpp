#include <coreinit/debug.h>
#include <whb/proc.h>
#include <sysapp/title.h>
#include <sysapp/launch.h>

int main() {
	WHBProcInit();

	if (WHBProcIsRunning()) {
		if (
			SYSCheckTitleExists(0x000500301004D000) || // * JPN
			SYSCheckTitleExists(0x000500301004D100) || // * USA
			SYSCheckTitleExists(0x000500301004D200)    // * EUR
		) {
			_SYSSwitchTo(SYSAPP_PFID_NOTIFICATIONS);
		} else {
			OSFatal("Failed to find Notifications");
		}

		while(WHBProcIsRunning()) {}
	}

	return 0;
}
