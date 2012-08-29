#include <string>
#include <glut.h>
#include <glu.h>
using namespace std;

namespace engine {
class Renderer {
	private:
		int width, height;
		int x, y;
		string name;
	public:
		Renderer(string name);
		Renderer();
		void render(/* TODO: Kamera/Scene*/);
		void setTitle(string name, int width, int height);
		void setPosition(int x, int y);
		void setDim(int width, int height);
}
}
