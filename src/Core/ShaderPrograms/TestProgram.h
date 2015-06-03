#pragma once

#include "../GL/GLHeader.h"

/**
 * Testing shader program
 */
class TestProgram
{
private:
	static GLuint aVert;
	static GLuint aColor;
	static GLuint programID;
public:
	/**
	 * Render.
	 * @param VAOID ID of Vertex Array Attribute (VAO)
	 * @param verticesCount Number of vertices to draw.
	 */
	static void draw(GLuint VAOID, int verticesCount);

	/** Compiles this shader program. */
	static void compile();

	/** Delete this shader program. */
	static void deleteShaderProgram();

	/** Get ID vertex attribute: aVert. For vertices. */
	static GLuint getAVert();

	/** Get ID vertex attribute: aColor. For color. */
	static GLuint getAColor();
};
