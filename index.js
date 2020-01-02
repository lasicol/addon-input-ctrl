 
var addon = require('bindings')('addon');

var obj = new addon.X11Obj();
// obj.moveCursor(100,100);

const clickMouseButton = (button) => {
    obj.mouseButton(button, true);
    obj.mouseButton(button, false);
}

clickMouseButton(3);

