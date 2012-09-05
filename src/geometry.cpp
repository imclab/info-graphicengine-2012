void engine::Geometry::computeNormals() {
	for( int i=0; i < vertices.size(); i+=3) {
		glm::normalize(glm::cross(vertices[i] - vertices[i-2], vertices[i-1] - vertices[i]));
