namespace engine {
	class Geometry {
		private:
		public:
		std::vector<Vector3> vertices;
		std::vector<Vector3> colors;
		std::vector<Vector3> normals;
		std::vector<Face3> faces;
		void computeNormals();
	}
};
