#include "input_device_ctrl.h"

#ifdef __linux__ 
#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <X11/extensions/XTest.h>
#include <X11/XKBlib.h>
#elif _WIN32
#include <windows.h>
#endif


Napi::FunctionReference InputController::constructor;

Napi::Object InputController::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func =
      DefineClass(env,
                  "InputController",
                  {
                   InstanceMethod("moveCursor", &InputController::moveCursor),
                   InstanceMethod("mouseButton", &InputController::mouseButton)
                   });

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("InputController", func);
  return exports;
}

InputController::InputController(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<InputController>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
    #ifdef __linux__ 
    this->display = XOpenDisplay(0);
    #elif _WIN32

    #endif
}

void InputController::moveCursor(const Napi::CallbackInfo& info) {
    //TODO add validation of args comming to function
    Napi::Number x, y;
    
    x = info[0].As<Napi::Number>();
    y = info[1].As<Napi::Number>();

    #ifdef __linux__
        XTestFakeRelativeMotionEvent( (Display *) display, x.Int32Value(), y.Int32Value(), 0);
        XFlush((Display *)display);
    #elif _WIN32
        INPUT input;
        input.type = INPUT_MOUSE;
        input.mi.mouseData = 0;
        input.mi.time = 0;
        input.mi.dx = x.Int64Value();
        input.mi.dy = y.Int64Value();
        input.mi.dwFlags = MOUSEEVENTF_MOVE;//MOUSEEVENTF_ABSOLUTE
        SendInput(1, &input, sizeof(INPUT));
    #endif
}

void InputController::mouseButton(const Napi::CallbackInfo& info) {
    //TODO add validation of args comming to function

    Napi::Number button;
    Napi::Boolean press;

    button = info[0].As<Napi::Number>();
    press = info[1].As<Napi::Boolean>();

    #ifdef __linux__
        XTestFakeButtonEvent((Display *)display, button.Uint32Value(), press, 0);
        XFlush((Display *)display);
    #elif _WIN32
        INPUT    Input={0};
        Input.type      = INPUT_MOUSE;
        if (press) {
            Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
        }
        else {
            Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
        }
        SendInput(1,&Input,sizeof(INPUT));
    #endif

}