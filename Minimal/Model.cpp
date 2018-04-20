#include "Model.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <assimp/mesh.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <glm/gtc/matrix_transform.hpp>

Model::Model()
{
	
}

void Model::Draw()
{
	for (unsigned int i = 0; i < meshes.size(); i++)
	{
		//do something like meshes[i].Draw(shader); here
	}
}

void Model::loadModel(std::string path)
{
	Assimp::Importer import;
	const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs);

	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
	{
		std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
		return;
	}
	directory = path.substr(0, path.find_last_of('/'));

	processNode(scene->mRootNode, scene);
}

void Model::processNode(aiNode *node, const aiScene *scene)
{
	// process all the node's meshes (if any)
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		aiMesh *mesh = scene->mMeshes[node->mMeshes[i]];
		meshes.push_back(processMesh(mesh, scene));
	}
	// then do the same for each of its children
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		processNode(node->mChildren[i], scene);
	}
}

aiMesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
	std::vector<aiVector3D*> vertices;
	std::vector<unsigned int> indices;
	//std::vector<Texture> textures;

	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		aiVector3D* vertex;
		// process vertex positions, normals and texture coordinates
		vertex->x = mesh->mVertices[i].x;
		vertex->y = mesh->mVertices[i].y;
		vertex->z = mesh->mVertices[i].z;
		vertices.push_back(vertex);
	}

	// process indices
	// process material
	if (mesh->mMaterialIndex >= 0)
	{
		//
	}
	
	aiMesh *toReturn = new aiMesh();
	//aiMesh->mVertices = vertices;
	return *toReturn;
}

Model::~Model()
{
}
