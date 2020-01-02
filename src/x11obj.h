
#ifndef X11OBJ_H
#define X11OBJ_H

#include <napi.h>
#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <X11/XKBlib.h>


class X11Obj : public Napi::ObjectWrap<X11Obj> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  X11Obj(const Napi::CallbackInfo& info);

 private:
  static Napi::FunctionReference constructor;

  void moveCursor(const Napi::CallbackInfo& info);
  void mouseButton(const Napi::CallbackInfo& info);


  Display *display;
  double value_;
};

#endif