# What is a wireframe ?
A wireframe in the context of computer graphics is a visual representation of a three-dimensional (3D) object. The object is represented by lines drawn along the edges of the object. These lines represent the "wires" that, when connected, form the structure of the object.

Wireframes are often used in the early stages of design and development to establish the basic structure of a 3D object before more details (like textures and lighting) are added. They are also used in 3D modeling software, and can be used to create 3D diagrams in a variety of fields, including architecture, engineering, and video game design.

## Components
`X-axis`\
`Y-axis`\
`Z-axis`\
Assume `X-axis` is pointing towards us

# Lines. What defines a line ?
In the context of computer graphics, a line is defined by two points: a start point and an end point. Each point has coordinates that determine its position in the space. In a 2D space, a point is defined by its x and y coordinates. In a 3D space, a point is defined by its x, y, and z coordinates.

The simplest way to draw a line between two points is to use a method called linear interpolation. This involves calculating the points along the line between the start and end points and then drawing a pixel at each of these points. The basic formula for linear interpolation between two points (x0, y0) and (x1, y1) is:

	for t from 0 to 1:
		x = x0 + t * (x1 -x0)
		y = y0 + t * (y1 -y0)
		drawPixel(x,y)

This will draw a line from (x0, y0) to (x1, y1). Note that this is a very basic method and doesn't take into account things like line thickness or anti-aliasing. For more advanced line drawing, you might want to look into algorithms like Bresenham's line algorithm or Wu's line algorithm.

# 0. Rotate a line
The line should start like this `|`, with a length of `100 pixels`

## 0.1 Rotate along the `X-axis`
Gradually increase 10 degrees until 360 degrees.\
The output should look like its a clock.

## 0.2 Rotate along the `Y-axis`
Gradually increase 10 degrees until 360 degrees.\
The line should look like its getting shorter and shorter until `180 degrees`, then it will start getting longer until it returns to its original length.

# 1. How to show a plane in different angles ?
a. implement a function that can draw lines\
b. draw a plane, 300 * 100\
c. rotate this mfcker

# 1.1 Rotation
