const addon = require('bindings')('addon');

export interface X11Class {
    moveCursor(deltaX: number, deltaY: number): void,
    mouseButton(buttonNum: number, press: boolean): void,
}

export var X11Class: {
    new(): X11Class
} = addon.X11Obj
