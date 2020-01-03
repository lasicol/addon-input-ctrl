const addon = require("../dist");

const obj = new addon.X11Class();

// Move cursor
obj.moveCursor(100,100);

// Click mouse button
const clickMouseButton = (button) => {
    obj.mouseButton(button, true);
    obj.mouseButton(button, false);
}
clickMouseButton(3);