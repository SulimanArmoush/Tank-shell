#ifndef PRIMITIVEDRAWER_H
#define PRIMITIVEDRAWER_H

class PrimitiveDrawer {
public:
    PrimitiveDrawer();
    void DrawPoint(Point point);
    void DrawLine(Point start, Point end);
    void DrawTriangle(Point v1, Point v2, Point v3);
    void DrawQuad(Point v1, Point v2, Point v3, Point v4);

    void drawCube(Point start, int width, int height, int length);
};

#endif
