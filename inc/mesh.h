#include "./geometry.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

namespace engine {
class Mesh {
	private:
	   GLuint vboID;
	   GLuint indexVBO;
	   engine::Geometry geom;
	   engine::Geometry mergeGeom;
	   bool loadedData() { return geom == NULL; }
	   glm::Matrix4 mat;
	public:
	   Mesh(engine::Geometry geom, bool upload);
	   Mesh();
	   void render();
	   void create();
	   void update();
	   ~Mesh();
	   engine::Geometry getGeom();
}
}
	
	   
