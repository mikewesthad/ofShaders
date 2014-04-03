# ofShaders #

As I work through the [openFrameworks shaders tutorial](http://openframeworks.cc/tutorials/graphics/shaders.html), I'll be uploading my own heavily commented shaders.

Resources:

http://www.shaderific.com/glsl/
http://en.wikibooks.org/wiki/GLSL_Programming

## 01_ColorMap ##

Same as the first example from the openFrameworks shaders tutorial.  This program draws a rectangle that covers the screen, and the fragment shader colors the pixels based on their position on the screen, generating a color map: 

![01_ColorMap](./01_ColorMap_Result.png "Results from 01_ColorMap")

## 02_ConwaysGameOfLife ##

[Conway's Game of Life](http://en.wikipedia.org/wiki/Conway's_Game_of_Life) written to run in a shader:

![02_ConwaysGameOfLife](./02_ConwaysGameOfLife_Result.png "Results from 02_ConwaysGameOfLife")

## 03_ConwayRevisited ##

TDB, something with using applying a magnifier effect or showing off the power of shaders.  An example of running three simultaneous, independent games of life in a one rendering pass (using each color channel as a separate game):

![03_ConwayRevisited](./03_ConwayRevisited_Result.png "Results from 03_ConwayRevisited")

