#define __STDC_FORMAT_MACROS 1

#include <thread>

#include "api2/IAgoraService.h"
#include "api2/NGIAgoraLocalUser.h"
#include "api2/NGIAgoraRtcConnection.h"
// #include "base/log.h"
#include <unistd.h>

using namespace std;
using namespace agora;
using namespace agora::base;
using namespace agora::rtc;
//using namespace agora::server;

static IAgoraService *service = nullptr;
AgoraServiceConfiguration scfg = {};

extern "C" {

int create_agora_service(void) {
    service = createAgoraService();
    scfg.enableAudioProcessor = true;
    scfg.enableAudioDevice = false;
    scfg.enableVideo = true;
    scfg.serviceProfile = agora::base::PROFILE_LIVE_BROADCASTING;
    service->initialize(scfg);

    return service ? 1 : 0;
}

void destroy_agora_service(void) {
    service = nullptr;
}

}
