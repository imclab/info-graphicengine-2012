#include <iostream>
#include "../inc/renderer.h"

engine::Renderer::Renderer(string name, int width, int height) {
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0,0);
	glutCreateWindow(name);
}
engine::Renderer::Renderer(string name) {
        glutInit(&argc,argv);
        glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); 
        glutInitWindowPosition(0,0);
        glutFullScreen();
 	glutCreateWindow(name);
}	
void engine::Renderer::renderer() {}
void engine::Renderer::setTitle(string name) {
	this.name = name;
	glutSetWindowTitle(this.name);
}
void enginer::Renderer::setPosition(int x, int y) {
	this.x = x; this.y = y;
	glutInitWindowsPosition(this.x, this.y);
}
void engine::Renderer::setDim(int width,  int height) {
	this.height = height; this.width = width;
	glutInitWindowSize(this.width, this.height);
}
 
