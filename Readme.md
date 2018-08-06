# LCD Simulation library

![image](doc/images/Screenshot from 2018-08-06 20-14-27.png)

## Motivation

Building user interfaces for small microcontrollers is a pain. You need to
visualize your changes to have a feeling how it is working, but it takes 
too long to compile and burn to the device.

With this library you can save the burning step and test your user interface
in your pc. Not only the graphics part, but the user interaction (keyboard) 
too.

## Usage

The library is located in the lib directory. It has two files, uisim.h and 
uisim.c. It uses the [SDL2](https://www.libsdl.org/index.php) library to draw 
the virtual lcd screen and to read the user input via keyboard.

The header file (uisim.h) is selfs-explanatory.

## License

```
/*
 * uisim
 * Copyright (C) 2018  Diego Asanza <f.asanza@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 ```