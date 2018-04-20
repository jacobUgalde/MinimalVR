#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
	Model();
	Model(char *path);
	void Draw();
	//void Draw(Shader shader);
	~Model();
private:
	/*  Model Data  */
	std::vector<aiMesh> meshes;
	std::string directory;
	/*  Functions   */
	void loadModel(std::string path);
	void processNode(aiNode *node, const aiScene *scene);
	aiMesh processMesh(aiMesh *mesh, const aiScene *scene);
	std::vector<aiTexture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

