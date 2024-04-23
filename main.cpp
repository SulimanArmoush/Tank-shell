#define DEFAULT_WINDOW_WIDTH 800
#define DEFAULT_WINDOW_HEIGHT 800
#define WINDOW_TITLE "OpenGL Application"
#define TIMER_MS 1000.0f / 60.0f
#include "GL/glut.h"
#include <windows.h>
#include "Point.h"
#include "PrimitiveDrawer.h"
#include "math.h"
#include "texture.h"

float camera_x = 0.0f, camera_y = 8.0f, camera_z = -15.0f; // Camera position
float look_x = 0.0f, look_y = 2.0f, look_z = 0.0f; // Look direction
bool keys[256];
bool specialKeys[256];

int SKYFRONT, SKYBACK, SKYLEFT, SKYRIGHT, SKYUP, SKYDOWN ,image3  ,image4 , image5 , image6;
void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
    // Center the Skybox around the given x,y,z position
    x = x - width / 2;
    y = y - height / 2;
    z = z - length / 2;
    glEnable(GL_TEXTURE_2D);

    // Draw Front side
    glBindTexture(GL_TEXTURE_2D, SKYFRONT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);
    glEnd();

    // Draw Back side
    glBindTexture(GL_TEXTURE_2D, SKYBACK);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
    glEnd();

    // Draw Left side
    glBindTexture(GL_TEXTURE_2D, SKYLEFT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z + length);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z);
    glEnd();

    // Draw Right side
    glBindTexture(GL_TEXTURE_2D, SKYRIGHT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z + length);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);
    glEnd();

    // Draw Up side
    glBindTexture(GL_TEXTURE_2D, SKYUP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
    glEnd();

    // Draw Down side
    glBindTexture(GL_TEXTURE_2D, SKYDOWN);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 0x812F);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 0x812F);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(x, y, z + length);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y, z + length);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y, z);
    glEnd();

    glColor3f(1, 1, 1);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}


void handleSpecialKeypress(int key, int x, int y) {
    specialKeys[key] = true;
}

void handleSpecialKeyrelease(int key, int x, int y) {
    specialKeys[key] = false;
}

void cleanup() {}

void initRendering() {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

    glEnable(GL_TEXTURE_2D);
    // skybox
    SKYFRONT = LoadTexture("ft.bmp", 255);
    SKYBACK = LoadTexture("bk.bmp", 255);
    SKYLEFT = LoadTexture("lf.bmp", 255);
    SKYRIGHT = LoadTexture("rt.bmp", 255);
    SKYUP = LoadTexture("up.bmp", 255);
    SKYDOWN = LoadTexture("dn.bmp", 255);
    image3 =  LoadTexture("building.bmp", 255);
    image4 =  LoadTexture("wall.bmp", 255);
    image5 =  LoadTexture("wood.bmp", 255);
    image6 =  LoadTexture("boo.bmp", 255);



    glDisable(GL_TEXTURE_2D);
}
void handleResize(int new_screen_width, int new_screen_height) {
    glViewport(0, 0, new_screen_width, new_screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, (double) new_screen_width / (double) new_screen_height, 1.0, 1000.0);
    glutPostRedisplay();
}
float    x = 0.0f   ,y = 1.0f ,z = 0.0f , c = 0.0f  , cc = 0.0f
        ,ccc = 0.0f ,p=0.0f   ,b1=0     , t = 0.0f  ,  rr = 0.0f
        ,rrr = 0.0f ,ro = 0.0f,xr = 0.0f, yr = 1.0f , zr = 0.0f
        ,r = 0.0f
                ,b3=0.0f ,ra=0.0f;

bool Boom = false , down = false ;
void drawScene() {

    GLUquadric* quad = gluNewQuadric();

    PrimitiveDrawer primitiveDrawer = PrimitiveDrawer();
    glClearColor(0.53, 0.81, 0.98, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear information from last draw
    glMatrixMode(GL_MODELVIEW);                         // Switch to the drawing perspective
    glLoadIdentity();                                   // Reset the drawing perspective
    gluLookAt(camera_x, camera_y, camera_z, look_x, look_y, look_z, 0, 1, 0);
    // Start drawing here
///اعدادات الاضاءة
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat lightpos[] = {45.0, 195.0, 295.0, p};
    GLfloat lightpos2[] = {0,10 ,-10 , p};
    GLfloat lightColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightColor3[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos2);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor3);
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientColor);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.5);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, ambientColor);
    GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };
    GLfloat mat_specular[] = { 0.1, 0.1 ,0.1, 1.0 };
//    GLfloat mat_shininess[] = { 128.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
///سكاي بوكس
    Draw_Skybox(0,0,0,1000,1000,1000);
///رسم القمر
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(50.0, 200.0, 500.0);
    glutSolidSphere(25.0, 50, 50);
    glPopMatrix();


///رسم الطريق
    glPushMatrix();
    glColor3f(0,0,0);
    primitiveDrawer.DrawQuad(Point(-10,0,5000),Point(10,0,5000),Point(10,0,-5000),Point(-10,0,-5000));
    glColor3f(1,1,1);
    primitiveDrawer.DrawQuad(Point(-1,0.1,5000),Point(1,0.1,5000),Point(1,0.1,-5000),Point(-1,0.1,-5000));
    glColor3f(1,1,0);
    primitiveDrawer.drawCube(Point(10,  1, -5000),4,1,10000);
    glColor3f(1,1,0);
    primitiveDrawer.drawCube(Point(-14,  1, -5000),4,1,10000);
    glPopMatrix();

    glPushMatrix(); /// بداية رسم الدبابة
    ///توابع التحريك
    glTranslated(x,y,z);
    glRotatef(c, 0, 1, 0);
    glScalef(1.5,1.5,1.5);

    ///رسم جسم الدبابة "المكعب"
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image5);
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(-1,1.21,-1.5);
    glTexCoord2f(1, 1);       glVertex3f(-1,1.21,1.5);
    glTexCoord2f(0, 1);       glVertex3f(1,1.21,1.5);
    glTexCoord2f(0, 0);       glVertex3f(1,1.21,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(-1,1.21,1.51);
    glTexCoord2f(1, 1);       glVertex3f(-1,0,1.51);
    glTexCoord2f(0, 1);       glVertex3f(1,0,1.51);
    glTexCoord2f(0, 0);       glVertex3f(1,1.21,1.51);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(-1,1.21,-1.51);
    glTexCoord2f(1, 1);       glVertex3f(-1,0,-1.51);
    glTexCoord2f(0, 1);       glVertex3f(1,0,-1.51);
    glTexCoord2f(0, 0);       glVertex3f(1,1.21,-1.51);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(-1,1.21,-1.51);
    glTexCoord2f(1, 1);       glVertex3f(-1,0,-1.51);
    glTexCoord2f(0, 1);       glVertex3f(-1,0,1.51);
    glTexCoord2f(0, 0);       glVertex3f(-1,1.21,1.51);
    glEnd();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(1,1.21,-1.51);
    glTexCoord2f(1, 1);       glVertex3f(1,0,-1.51);
    glTexCoord2f(0, 1);       glVertex3f(1,0,1.51);
    glTexCoord2f(0, 0);       glVertex3f(1,1.21,1.51);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();


///رسم كرة الدبابة
    glPushMatrix();
    glTranslated(0,1.2,0);
    glColor3f(0.1,0.0,0.0);
    glutSolidSphere(0.7,30,30);
    glPopMatrix();
///رسم السبطانة (:
    glPushMatrix();
    glColor3f(0.0,1.0,0.0);
    glTranslated(0,1.5,0);
    glRotatef(cc, 1, 0, 0);
    glRotatef(ccc, 0, 1, 0);
    gluCylinder(quad, 0.1, 0.15, 2, 30, 30);
    glPopMatrix();


///رسم اسطوانات الدبابة
    glPushMatrix();
    int n = 8;
    double ini[] = {-1.2, -0.6, 0, 0.6, 1.2};
    for (int i = 0; i < n; i++) {
        glPushMatrix();
        glColor3f(0.2, 0.1, 0.0);
        glTranslated(-1, -0.1, ini[i % 5]);
        glRotatef(90, 0, 1, 0);
        gluCylinder(quad, 0.28, 0.28, 2, 30, 30);
        glPopMatrix();
    }
    glPopMatrix();
///رسم الجنزير الأيمن
    glPushMatrix();
    glTranslated(0.8,0.9,0);
    glRotatef(90, 0, 0, 1);
    int num = 100;
    double init[] = {-1.2, -0.6, 0, 0.6, 1.2};
    for (int i = 0; i < num; i++) {
        glPushMatrix();
        glColor3f(0.2, 0.2, 0.2); //
        glTranslated(-1 + 0.3*cos(i*2*M_PI/num), -0.1, init[i % 5] + 0.3*sin(i*2*M_PI/num)); // تغيير الإحداثيات هنا
        glScalef(0.1f, 0.05f, 0.3f); //
        glutSolidCube(1.0);
        glColor3f(1,1,1);

        glPopMatrix();
    }
    glPopMatrix();
///رسم الجنزير الأيسر
    glPushMatrix();
    glTranslated(-1,0.9,0);
    glRotatef(90, 0, 0, 1);
    int nume = 100;
    double inite[] = {-1.2, -0.6, 0, 0.6, 1.2};
    for (int i = 0; i < num; i++) {
        glPushMatrix();
        glColor3f(0.2, 0.2, 0.2); //
        glTranslated(-1 + 0.3*cos(i*2*M_PI/nume), -0.1, inite[i % 5] + 0.3*sin(i*2*M_PI/num)); // تغيير الإحداثيات هنا
        glScalef(0.1f, 0.05f, 0.3f); //
        glutSolidCube(1.0);
        glColor3f(1,1,1);

        glPopMatrix();
    }
    glPopMatrix();

    glPopMatrix();/// نهاية رسم الدبابة

    ///رسم الأبنية على الجهتين بحلقة تكرار
    glPushMatrix();
    for(int i=-500 ; i<500 ; i +=28){
        glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image3);
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(14, 1, i);
    glTexCoord2f(1, 1);       glVertex3f(14, 20, i);
    glTexCoord2f(0, 1);       glVertex3f(14, 20, i+14);
    glTexCoord2f(0, 0);       glVertex3f(14, 1, i+14);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image4);
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0);       glVertex3f(-14, 1, i);
    glTexCoord2f(1, 1);       glVertex3f(-14, 20, i);
    glTexCoord2f(0, 1);       glVertex3f(-14, 20, i+14);
    glTexCoord2f(0, 0);       glVertex3f(-14, 1, i+14);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, image4);
        glBegin(GL_QUADS);
        glTexCoord2f(1, 0);       glVertex3f(14, 1, i-14);
        glTexCoord2f(1, 1);       glVertex3f(14, 20, i-14);
        glTexCoord2f(0, 1);       glVertex3f(14, 20, i);
        glTexCoord2f(0, 0);       glVertex3f(14, 1, i);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, image3);
        glBegin(GL_QUADS);
        glTexCoord2f(1, 0);       glVertex3f(-14, 1, i-14);
        glTexCoord2f(1, 1);       glVertex3f(-14, 20, i-14);
        glTexCoord2f(0, 1);       glVertex3f(-14, 20, i);
        glTexCoord2f(0, 0);       glVertex3f(-14, 1, i);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
}

    ///رسم اعمدة الانارة على الجهتين بحلقة تكرار
    for(int i=-1000 ; i<=1000 ; i +=100) {
        glLineWidth(10);
        glColor3f(0, 0, 0);
        glPushMatrix();
        primitiveDrawer.DrawLine(Point(11, 0, i), Point(11, 10, i));
        primitiveDrawer.DrawLine(Point(-11, 0, i), Point(-11, 10, i));
        glColor3f(1, 1, 1);
        glPushMatrix();
        glTranslated(-11,10 ,i );
        glutSolidSphere(1,10,10);
        glPopMatrix();
        glPushMatrix();
        glTranslated(11,10 ,i );
        glutSolidSphere(1,10,10);
        glPopMatrix();

        ///رسم اعلام على الجهتين بحلقتي تكرار

        glPushMatrix();
        glTranslatef(17,25 ,i );
        for (int i = -3; i < 4; i++) {
            float y1 = 0.2f * cos(t + i)-0.01;
            float y2 = 0.2f * cos(t + i +1) -0.01;
            glColor3f(1.0, 1.0, 1.0);
            primitiveDrawer.DrawQuad(Point(i, y1, 0), Point(i + 1, y2, 0), Point(i + 1, y2 - 1, 0), Point(i, y1 - 1, 0));
            glColor3f(0.0, 0.0, 0.0);
            primitiveDrawer.DrawQuad(Point(i, y1 + 1, 0), Point(i + 1, y2 + 1, 0), Point(i + 1, y2, 0), Point(i, y1, 0));
            glColor3f(0.0, 1.0, 0.0);
            primitiveDrawer.DrawQuad(Point(i, y1 - 1, 0), Point(i + 1, y2 - 1, 0), Point(i + 1, y2 - 2, 0), Point(i, y1 - 2, 0));
            glColor3f(1.0, 0.0, 0.0);
            primitiveDrawer.DrawTriangle(Point(-3,  1, 0), Point(-1, y2-0.5, 0), Point(-3,  - 2, 0));
            glLineWidth(5);
            glColor3f(1.0, 1.0, 1.0);
            primitiveDrawer.DrawLine(Point(-3,  1, 0),Point(-3,  - 6, 0));
        }
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-11,25 ,i );
        for (int i = -3; i < 4; i++) {
            float y1 = 0.2f * cos(t + i)-0.01;
            float y2 = 0.2f * cos(t + i +1) -0.01;
            glColor3f(1.0, 1.0, 1.0);
            primitiveDrawer.DrawQuad(Point(i, y1, 0), Point(i + 1, y2, 0), Point(i + 1, y2 - 1, 0), Point(i, y1 - 1, 0));
            glColor3f(0.0, 0.0, 0.0);
            primitiveDrawer.DrawQuad(Point(i, y1 + 1, 0), Point(i + 1, y2 + 1, 0), Point(i + 1, y2, 0), Point(i, y1, 0));
            glColor3f(0.0, 1.0, 0.0);
            primitiveDrawer.DrawQuad(Point(i, y1 - 1, 0), Point(i + 1, y2 - 1, 0), Point(i + 1, y2 - 2, 0), Point(i, y1 - 2, 0));
            glColor3f(1.0, 0.0, 0.0);
            primitiveDrawer.DrawTriangle(Point(-3,  1, 0), Point(-1, y2-0.5, 0), Point(-3,  - 2, 0));
            glLineWidth(5);
            glColor3f(1.0, 1.0, 1.0);
            primitiveDrawer.DrawLine(Point(-3,  1, 0),Point(-3,  - 6, 0));
        }
        glPopMatrix();
        glPopMatrix();

    }

    t += 0.1f;


///رسم الطلقة
    glPushMatrix();
    glTranslated(xr,yr,zr);
    glRotatef(r, 0, 1, 0);
    glScalef(1.5,1.5,3);
    glTranslated(0,1.5,0);
    glRotatef(rr, 1, 0, 0);
    glRotatef(rrr, 0, 1, 0);
    glColor3f(1.0, 0.0, 0.0);
    glTranslated(0, 0, b1);
    glutSolidSphere(0.2, 30, 30);
    glColor3f(1.0, 1.0, 1.0);
    glPopMatrix();

///رسم الحائط الهدف
glPushMatrix();
    glRotatef(ro,0,0,1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, image6);
    glBegin(GL_QUADS);

    glTexCoord2f(1, 0);       glVertex3f(0, 0, 50);
    glTexCoord2f(0, 0);       glVertex3f(-8, 0, 50);
    glTexCoord2f(0, 1);       glVertex3f(-8, 10, 50);
    glTexCoord2f(1, 1);       glVertex3f(0 , 10 , 50);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///شرط الطلقة
    if (Boom) {
        b1 += 2.0f;
        if(b1 >= 100){Boom=!Boom;
            b1=0;
            rr=cc;
            rrr=ccc;
            xr=x;
            yr=y;
            zr=z;
        }}
    ///شرط الهبوط
    if(0>=xr){
        if(zr>=45){
            if(zr<=55){
                down=true;
        }}}

    if(down)
    {
        if(ro<90)
            ro +=2;
        else
        down=false;
    }


// End drawing
    glutSwapBuffers();

}
void update(int value) {
    if (keys['A'] || keys['a']) {
        if(x<8){ x += 0.1f;}
        if(c<45){ c += 5;}

        if(!Boom) {
            if (xr < 8) { xr += 0.1f; }
            if (r < 45) { r += 5; }
        }}

    if (keys['D'] || keys['d']) {
        if(x>-8){ x -= 0.1f;}
        if(c>-45){ c -= 5;}

        if(!Boom) {
            if (xr > -8) { xr -= 0.1f; }
            if (r > -45) { r -= 5; }
        }}

    if (keys['W'] || keys['w']) {
        camera_z += 0.1f;
        look_z += 0.1f;
        if(c>0){ c -= 2;}
        if(c<0){ c += 2;}
        z += 0.1f;

        if(!Boom) {
            if (r > 0) { r -= 2; }
            if (r < 0) { r += 2; }
            zr += 0.1f;
        }}

    if (keys['S'] || keys['s']) {
        camera_z -= 0.1f;
        look_z -= 0.1f;
        if(c>0){ c -= 2;}
        if(c<0){ c += 2;}
        z -= 0.1f;

        if(!Boom) {
            if (r > 0) { r -= 2; }
            if (r < 0) { r += 2; }
            zr -= 0.1f;
        }}

    if (keys['6'] ) {
        camera_x += 0.1f;
        look_x -= 0.1f;
    }
    if (keys['4'] ) {
        camera_x -= 0.1f;
        look_x += 0.1f;
    }
    if (keys['8'] ) {
        camera_z += 0.1f;
        look_z -= 0.1f;
    }
    if (keys['2']) {
        camera_z -= 0.1f;
        look_z += 0.1f;
    }
    if (keys['0']) {
        camera_y += 0.1f;
        look_y+= 0.1f;
        y += 0.1f;
    }
    if (keys['9']) {
        if(y>1){
        camera_y -= 0.1f;
        look_y-= 0.1f;
        y -= 0.1f;
    }}
        if (keys['1']) {
                ro=0;
            }

    if (specialKeys[GLUT_KEY_LEFT]) {
        if(ccc<45){ ccc += 5;}
       if(!Boom){
           if(rrr<45){ rrr += 5;}
       }}

    if (specialKeys[GLUT_KEY_RIGHT]) {
        if(ccc>-45){ ccc -= 5;}
        if(!Boom) {
            if(rrr>-45){ rrr -= 5;}
        }}

    if (specialKeys[GLUT_KEY_UP]) {
        if(cc>-45){ cc -= 5;}
        if(!Boom){
            if(rr>-45){ rr -= 5;}
        }}

    if (specialKeys[GLUT_KEY_DOWN]) {
        if(cc<0){ cc += 5;}
        if(!Boom) {
            if(rr<0){ rr += 5;}
        }}


    glutPostRedisplay();
    glutTimerFunc(TIMER_MS, update, 0);
}


void handleKeypress(unsigned char key, int x, int y) {
    keys[toupper(key)] = true;
}
void handleKeyrelease(unsigned char key, int x, int y) {
    keys[toupper(key)] = false;
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
       // if(b1=0)
            Boom = !Boom;

    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        p=!p;
    }
}

int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    glutCreateWindow(WINDOW_TITLE);
    initRendering();
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutKeyboardUpFunc(handleKeyrelease);
    glutMouseFunc(handleMouse);
    glutSpecialFunc(handleSpecialKeypress);
    glutSpecialUpFunc(handleSpecialKeyrelease); 
    glutReshapeFunc(handleResize);
    glutTimerFunc(TIMER_MS, update, 0);
    glutMainLoop();
    return 0;
}