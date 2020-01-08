#include <napi.h>
#include "input_device_ctrl.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return InputController::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)