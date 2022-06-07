#include <iostream>
#include "glut.h"

class Point {
private:
	float X;
	float Y;
public:
	Point();
	Point(float aX, float aY);
	float getX() const;
	float getY() const;
	void setX(float aX);
	void setY(float aY);
	void draw() const;
};

Point::Point() {
	X = 0;
	Y = 0;
}

Point::Point(float aX, float aY) {
	X = aX;
	Y = aY;
}

float Point::getX() const {
	return X;
}

float Point::getY() const {
	return Y;
}

void Point::setX(float aX) {
	X = aX;
}

void Point::setY(float aY) {
	Y = aY;
}

void Point::draw() const {
	glBegin(GL_POINTS);
	glVertex2f(X, Y);
	glEnd();
}

Point center(0, 0);
Point c(0, 0);
float angel = 20;
float tr = 20;
float b = 200;
float a = 75;
double i = 0.0;


void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	c.draw();
	glPushMatrix();

	glTranslatef(a * cos(i), b * sin(i), 0);


	glTranslatef(center.getX(), center.getY(), 0);
	glRotatef(angel, 0, 0, 1);
	glTranslatef(-center.getX(), -center.getY(), 0);
	
	glBegin(GL_POLYGON);
	glPolygonMode(GL_FRONT, GL_FILL);

	
	glColor3f(0, 255, 0);

	glBegin(GL_QUADS);
		glVertex2f(center.getX() - 25, center.getY() - 25);
		glVertex2f(center.getX() - 25, center.getY() + 25);
		glVertex2f(center.getX() + 25, center.getY() + 25);
		glVertex2f(center.getX() + 25, center.getY() - 25);
	glEnd();
	
	tr++;
	angel++;

	glColor3f(0, 0, 0);
	center.draw();
	
	glPopMatrix();
	glFlush();

	// Отправляем на прорисовку
}


void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(40, timer, 0);
}

void myInit() {
	glClearColor(1, 1, 1, 0);
	//задание цвета фона (белый)
	glColor3f(0, 0, 0);
	// задание цвета рисования (черный)
	glPointSize(1);
	// размер точки
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-320, 320, -320, 320);
	// задание окнной системы координат (Слева снизу начало)

}

void animation(void) {
	i = (i < 6.25) ? i + 0.000001 : 0.0;
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	//инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//устанавливаем режим дисплея
	glutInitWindowSize(640, 640);
	//устанавливаем размер окна
	glutCreateWindow("OpenGL example");
	//открываем окно на экране

	glutDisplayFunc(myDisplay);
	glutTimerFunc(40, timer, 0);
	glutIdleFunc(animation);

	//регистрируем функцию обратного вызова
	myInit();

	glutMainLoop();
	//входим в бесконечный цикл

}
