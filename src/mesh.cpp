#include "../inc/mesh.h"
void engine::Mesh::Mesh( engine::Geomtry geom, bool upload) {
	this->geom = geom;
	if(upload) {
		this->create();
	}
}
void engine::Mesh::create() {
	if(loadedData()) {
		//Create an Buffer
		glGenBuffers(1, &this->vboID);
		glBindBuffer(GL_ARRAY_BUFFER, vboID);
		//Upload Vertex Data 
		//TODO: Manipulate Render Mode
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * this->geom->vertices.size(), NULL, GL_STATIC_DRAW);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * this->geom->vertices.size(), this->geom->vertices.front());
		//Set the Pointer to the data
		glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
		glNormalPointer(GL_FLOAT, sizeof(Vertex),  BUFFER_OFFSET(12));
		glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(24));
		
		//Create the Index Buffer
		glGenBuffers(1, &this->indexVBOID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexVBOID);
		//Upload the Index Buffer 
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &this->geom->indices.front(), GL_STATIC_DRAW);
	}
	else return false;
}

void engine::Mesh::render() {
        //Enable VBOs
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);	

	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glNormalPointer(GL_ARRAY_BUFFER
