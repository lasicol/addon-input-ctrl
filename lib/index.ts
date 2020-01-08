const addon = require('bindings')('addon');

export interface InputController {
    moveCursor(deltaX: number, deltaY: number): void,
    mouseButton(buttonNum: number, press: boolean): void,
}

export var InputController: {
    new(): InputController
} = addon.InputController
