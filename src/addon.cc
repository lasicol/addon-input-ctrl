#include <napi.h>
#include "x11obj.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return X11Obj::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)