
#include <windows.h>		// Header File For Windows
#include <GL/glut.h>
#include <math.h>

#include "Point.h"
#include "PrimitiveDrawer.h"

PrimitiveDrawer::PrimitiveDrawer(){}

// Draw a point at the given position.
void PrimitiveDrawer::DrawPoint(Point point) {
    glBegin(GL_POINTS);
    glVertex3f(point.x,point.y,point.z);
    glEnd();
}

// Draw a line between the given two positions.
void PrimitiveDrawer::DrawLine(Point start, Point end) {
    glBegin(GL_LINES);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(end.x, end.y, end.z);
    glEnd();
}

// Draw a triangle with the given three vertices.
void PrimitiveDrawer::DrawTriangle(Point v1, Point v2, Point v3) {
    glBegin(GL_TRIANGLES);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glEnd();
}

// Draw a quadrilateral with the given four vertices.
void PrimitiveDrawer::DrawQuad(Point v1, Point v2, Point v3, Point v4) {
    glBegin(GL_QUADS);
    glVertex3f(v1.x, v1.y, v1.z);
    glVertex3f(v2.x, v2.y, v2.z);
    glVertex3f(v3.x, v3.y, v3.z);
    glVertex3f(v4.x, v4.y, v4.z);
    glEnd();
}
void PrimitiveDrawer::drawCube(Point start,int width,int height,int length ) {

    glBegin(GL_QUADS);
    // front face
    glVertex3f(start.x,  start.y,  start.z);
    glVertex3f(start.x+width, start.y, start.z);
    glVertex3f(start.x+width, start.y-height, start.z);
    glVertex3f(start.x, start.y-height, start.z);

    // back face
    glVertex3f(start.x, start.y, start.z+length);
    glVertex3f(start.x+width, start.y, start.z+length);
    glVertex3f(start.x+width, start.y-height, start.z+length);
    glVertex3f(start.x, start.y-height, start.z+length);

    // left face
    glVertex3f(start.x, start.y, start.z+length);
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(start.x, start.y-height, start.z);
    glVertex3f(start.x, start.y-height, start.z+length);

    // right face
    glVertex3f(start.x+width, start.y, start.z);
    glVertex3f(start.x+width, start.y, start.z+length);
    glVertex3f(start.x+width, start.y-height, start.z+length);
    glVertex3f(start.x+width, start.y-height, start.z);

    // top face
    glVertex3f(start.x, start.y, start.z);
    glVertex3f(start.x, start.y, start.z+length);
    glVertex3f(start.x+width, start.y, start.z+length);
    glVertex3f(start.x+width, start.y, start.z);

    // bottom face
    glVertex3f(start.x, start.y-height, start.z);
    glVertex3f(start.x, start.y-height, start.z+length);
    glVertex3f(start.x+width, start.y-height, start.z+length);
    glVertex3f(start.x+width, start.y-height, start.z);
    glEnd();
}

//int num_texture=-1; //Counter to keep track of the last loaded texture

// glutSolidSphere(3,30,30);
