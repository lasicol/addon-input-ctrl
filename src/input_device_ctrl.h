
#ifndef INPUT_DEVICE_CTRL_H
#define INPUT_DEVICE_CTRL_H

#include <napi.h>
#ifdef __linux__ 
#include <X11/Xlib.h>
#elif _WIN32

#endif


class InputController : public Napi::ObjectWrap<InputController> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  InputController(const Napi::CallbackInfo& info);

 private:
  static Napi::FunctionReference constructor;

  void moveCursor(const Napi::CallbackInfo& info);
  void mouseButton(const Napi::CallbackInfo& info);
  
  #ifdef __linux__ 
  Display* display;
  #endif
  

};

#endif