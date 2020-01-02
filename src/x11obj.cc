#include "x11obj.h"

Napi::FunctionReference X11Obj::constructor;

Napi::Object X11Obj::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env,
                  "X11Obj",
                  {
                   InstanceMethod("moveCursor", &X11Obj::moveCursor),
                   InstanceMethod("mouseButton", &X11Obj::mouseButton)
                   });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("X11Obj", func);
  return exports;
}

X11Obj::X11Obj(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<X11Obj>(info), display(nullptr) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  this->display = XOpenDisplay(0);
}

void X11Obj::moveCursor(const Napi::CallbackInfo& info) {
    //TODO add validation of args comming to function
    Napi::Number x, y;
    
    x = info[0].As<Napi::Number>();
    y = info[1].As<Napi::Number>();

    XTestFakeRelativeMotionEvent(display, x.Int32Value(), y.Int32Value(), 0);
	XFlush(display);
}

void X11Obj::mouseButton(const Napi::CallbackInfo& info) {
    //TODO add validation of args comming to function

    Napi::Number button;
    Napi::Boolean press;

    button = info[0].As<Napi::Number>();
    press = info[1].As<Napi::Boolean>();

    XTestFakeButtonEvent(display, button.Uint32Value(), press, 0);
	XFlush(display);

}