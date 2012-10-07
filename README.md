Arduino-Chrono
==============

An Arduino-based chronometer for Tooski

Warning: This project is still in Beta, so some things may or may not work. If you find a problem, bug or have an idea don't hesitate to send me a message. It always makes people happy, right ?

Presentation
-------------
Here are all the files I used to build my own chronometer. It was initialy an idea for the website Tooski.ch, so made for skiers, and that's why the text on the screen is in French. However it is really easy to modify it and to understand the code, as the comments are in English.

It is based on Arduino, uses Xbee for wireless communication (~300m) and the detectors are using IR beams to detect when something goes through them. By the way I take this occasion to thank Ken Shirriff for his library that helped a lot ! If you go throught the folders, you will find the part list, the schematics and of course the commented Arduino code. Not to mention that there is also the instructions on how to use it once you are done building it.

Once again critics, comments and suggestions are really welcome, and keep in mind I may do errors, so point them out to me. Also if you modify or improve my code, let me know because I'll be happy to see what you've done.

Futur implementations:
----------------------
1. Storing the times into an SD card and make a table out of them.

2. Allow multiple skiers at the same time.

3. Implementing a camera that takes a photo when the chrono starts.

4. Having a camera that films you only from when the chrono starts to when it ends.

License
-------
Copyright (c) 2012 Sébastien Arnold

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.