#include "input_device_ctrl.h"
#include <windows.h>


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

}

void InputController::moveCursor(const Napi::CallbackInfo& info) {
    //TODO add validation of args comming to function
    Napi::Number x, y;
    
    x = info[0].As<Napi::Number>();
    y = info[1].As<Napi::Number>();

    INPUT input;
    input.type = INPUT_MOUSE;
    input.mi.mouseData = 0;
    input.mi.time = 0;
    input.mi.dx = x.Int64Value();
    input.mi.dy = y.Int64Value();
    input.mi.dwFlags = MOUSEEVENTF_MOVE;//MOUSEEVENTF_ABSOLUTE

    SendInput(1, &input, sizeof(INPUT));
}

void InputController::mouseButton(const Napi::CallbackInfo& info) {
    //TODO add validation of args comming to function

    Napi::Number button;
    Napi::Boolean press;

    button = info[0].As<Napi::Number>();
    press = info[1].As<Napi::Boolean>();


}