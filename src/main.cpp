
// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
// Include GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <string>
#include <fstream>
#include "Utils.h"

GLuint renderingProgram;

using namespace std;
#define N 9
#define dibujo 25

GLuint m_VAO;
GLuint m_VBO[4];
//GLuint m_VBO1;

int numberOfVertices = 52;
int dimVertices = numberOfVertices*3 ;

GLfloat ojoIzq[156];
GLfloat ojoDer[156];


GLfloat pcontrolTest[dibujo][N][2] = {
		{
		{-0.3,  -0.4}, //Inicio de dibujo (izquierda)
		{-0.3, -0.5},
		{-0.3, -0.6},
		{-0.35, -0.65},
		{-0.35, -0.7},
		{-0.375, -0.83},
		{-0.375, -0.83},
		{-0.375, -0.83},
		{-0.375, -0.83}
		},

		{
		{-0.22,  -0.33},
		{-0.29, -0.4},
		{-0.32, -0.45},
		{-0.38, -0.47},
		{-0.45, -0.35},
		{-0.7, 0.0},
		{-0.29, 0.0},
		{-0.22,  -0.1},
		{-0.22,  -0.1}
		},

		{
		{-0.35, -0.13},
		{-0.5,  0.5},
		{-0.5,  0.5},
		{-0.5,  0.5},
		{-0.5,  0.5},
		{-0.5,  0.5},
		{-0.5,  0.5},
		{-0.5,  0.5},
		{-0.5,  0.5}
		},

		{
		{-0.5,  0.49},
		{-0.5,  0.6},
		{-0.475,  0.65},
		{-0.450,  0.7},
		{-0.5,  0.75},
		{-0.4,  0.8},
		{-0.375,  0.85},
		{-0.35,  0.85},
		{-0.35,  0.85}
		},

		{
		{-0.35,  0.85}, //Aca iniciar cabello
		{-0.34,  0.87},
		{-0.33,  0.88},
		{-0.30,  0.9},
		{-0.30,  0.9},
		{-0.30,  0.9},
		{0.15,  1.0},
		{0.16,  0.98},
		{0.16,  0.98}
		},

		{
		{0.15,  0.98}, // Cabeza parte superior derecha
		{0.386,  0.93},
		{0.31,  0.83},
		{0.335,  0.83},
		{0.360,  0.78},
		{0.385,  0.73},
		{0.371,  0.68},
		{0.45,  0.47},
		{0.45,  0.47}
		},

		{
		{0.436,  0.225}, //Ojo derecho
		{0.50,  0.25},
		{0.56,  0.35},
		{0.48,  0.48},
		{0.44,  0.50},
		{0.42,  0.50},
		{0.34,  0.6},
		{0.20,  0.53},
		{0.18,  0.42}
		},

		{
		{0.19,  0.40},//Ojo izquierdo
		{0.10,  0.60},
		{-0.20,  0.50},
		{-0.23,  0.4},
		{-0.30,  0.2},
		{-0.15,  0.1},
		{0.32,  -0.20}, //Ref para nariz
		{0.23,  0.40},
		{0.18,  0.42}
		},

		{
		{0.37,  0.087}, //Parte superior de nariz//8
		{0.42,  0.08},
		{0.46,  0.08},
		{0.48,  0.08},
		{0.55,  0.3},
		{0.42,  0.275},
		{0.36,  0.25},
		{0.26,  0.225},
		{0.19,  0.22}//23
		},

		{
		{0.43,  0.089}, //Parte inferior de nariz
		{0.44,  0.088},
		{0.45,  0.083},
		{0.43,  0.083},
		{0.37,  0.083},
		{0.37,  0.083},
		{0.46,  0.083},
		{0.30,  0.083},
		{0.10,  0.038} //35 09
		},

		{
		{0.43,  0.09}, //Boca derecha circunferencia superior
		{0.45,  0.07},
		{0.46,  0.06},
		{0.59,  0.0},
		{0.56,  -0.01},
		{0.54,  -0.06},
		{0.58,  -0.08},
		{0.62,  -0.10},
		{0.60,  -0.30}
		},

		{
		{0.0,  -0.35}, //sonrisa
		{0.3,  -0.41},
		{0.3,  -0.41},
		{0.4,  -0.40},
		{0.5,  -0.38},
		{0.63,  -0.35},
		{0.63,  -0.33},
		{0.63,  -0.32},
		{0.60,  -0.29}
		},

		{
		{0.125,  0.041}, // Boca circunferencia izquierda
		{-0.05,  0.005},
		{-0.1,  -0.2},
		{-0.1,  -0.3},
		{-0.15,  -0.4},
		{0.1,  -0.6},
		{0.2,  -0.7},
		{0.4,  -0.6},
		{0.50,  -0.4}
		},

		{
		{0.50,  -0.40}, //Boca semi circulito
		{0.50,  -0.39},
		{0.50,  -0.39},
		{0.50,  -0.39},
		{0.50,  -0.39},
		{0.50,  -0.39},
		{0.50,  -0.39},
		{0.53,  -0.39},
		{0.55,  -0.36}
		},

		{
		{0.365,  -1.072},
		{0.365,  -0.95},
		{0.355,  -0.95},
		{0.345,  -0.90},
		{0.34,  -0.85},//cambio de puntos, leonidas
		{0.335,  -0.80},
		{0.33,  -0.70},
		{0.33,  -0.60},
		{0.33,  -0.57}

		},

		{
		{-0.25, -0.2}, //Orejita arriba
		{-0.25, -0.2},
		{-0.25, -0.2},
		{-0.25, -0.2},
		{-0.25, -0.2},
		{-0.25, -0.2},
		{-0.25, -0.2},
		{-0.35, -0.1},
		{-0.40, -0.25}
		},

		{
		{-0.32, -0.2}, //Orejita abajo
		{-0.32, -0.2},
		{-0.32, -0.2},
		{-0.32, -0.2},
		{-0.32, -0.2},
		{-0.32, -0.2},
		{-0.32, -0.2},
		{-0.40, -0.3},
		{-0.25, -0.3}
		},

		{
		{0.041, -0.32}, //Mueca boca
		{0.041, -0.32},
		{0.041, -0.32},
		{0.041, -0.32},
		{0.041, -0.32},
		{0.041, -0.32},
		{0.041, -0.32},
		{0.001, -0.35},
		{0.02, -0.4}
		},

		{
		{0.37,  -1.063}, //Cierre de imagen
		{0.30,  -1.08},
		{0.25,  -1.08},
		{0.20,  -1.075},
		{0.15,  -1.07},
		{0.10,  -1.065},
		{0.05,  -1.06},
		{-0.10,  -1.05},
		{-0.375,  -0.83}
		},

		{
		{-0.35,  0.85}, //1er cabello
		{-0.35,  0.85},
		{-0.35,  0.85},
		{-0.35,  0.85},
		{-0.35,  0.85},
		{-0.35,  0.85},
		{-0.35,  1.1},
		{-0.15,  1.1},
		{0.04,  0.95}
		},

		{
		{-0.15,  0.93}, //2do cabello
		{-0.15,  0.93},
		{-0.15,  0.93},
		{-0.15,  0.93},
		{-0.15,  0.93},
		{-0.15,  0.93},
		{-0.15,  1.13},
		{0.15,  1.13},
		{0.20,  0.95}
		},

		{
		{-0.4, 0.11}, //Patilla 1 izq
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.51, 0.3}
		},

		{
		{-0.50, 0.28}, //Patilla 2 izq
		{-0.50, 0.28},
		{-0.50, 0.28},
		{-0.50, 0.28},
		{-0.50, 0.28},
		{-0.50, 0.28},
		{-0.50, 0.28},
		{-0.50, 0.28},
		{-0.49, 0.08}
		},

		{
		{-0.4, 0.11}, //Patilla 2 derecha
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.4, 0.11},
		{-0.37, 0.3}
		},

		{
		{-0.37, 0.3}, //Patilla 2 izq
		{-0.37, 0.3},
		{-0.37, 0.3},
		{-0.37, 0.3},
		{-0.37, 0.3},
		{-0.37, 0.3},
		{-0.37, 0.3},
		{-0.37, 0.3},
		{-0.28, 0.11}
		}

};



void crearOjos(GLfloat m_Vertices[],GLfloat x,GLfloat y){

		GLfloat z = 0;
		GLfloat radius = 1;
		GLint numberOfSides = 50;
		GLfloat twicePi = 2.0f * M_PI;

		GLfloat verticesX[numberOfVertices];
		GLfloat verticesY[numberOfVertices];
		GLfloat verticesZ[numberOfVertices];

		verticesX[0] = x*0.020;
		verticesY[0] = y*0.020;
		verticesZ[0] = z;

		for (int i = 1; i < numberOfVertices; i++) {
			verticesX[i] = (x + (radius * cos(i * twicePi / numberOfSides)))*0.020;
			verticesY[i] = (y + (radius * sin(i * twicePi / numberOfSides)))*0.020;
			verticesZ[i] = z;
		}

		for (int i = 0; i < numberOfVertices; i++) {
			m_Vertices[i * 3] = verticesX[i];
			m_Vertices[i * 3 + 1] = verticesY[i];
			m_Vertices[i * 3 + 2] = verticesZ[i];
		}
}

int numPointsBz;
int nPointsCurveBz;


vector<float> graficaPuntosBezier() {
  vector<float> temp;
  for(int j=0; j< dibujo;j++){
	  for (int i = 0; i < N; i++) {
	      temp.push_back(pcontrolTest[j][i][0]);
	      temp.push_back(pcontrolTest[j][i][1]);
	   }
  }

  return temp;
}

float factorial(int n) {
  float p = 1;
  for (int i = 1; i <= n; i++)
    p = p * (float) i;
  return p;
}

float CoefNewton(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

float CurvaBezier(float t, int axis, GLfloat control [][2]) {
	float suma = 0.0;
	for (int i = 0; i < N; i++) {
		suma += control[i][axis] * CoefNewton(N - 1, i) * pow(t, N - 1 - i)
				* pow(1.0 - t, i);
	}
	return suma;
}

vector<float> graficaCurvaBezier(void) {
	vector<float> temp;
	temp.push_back(0.0); // para triangle fan, leonidas
	temp.push_back(0.0); // para triangle fan, leonidas
	for(int i=0; i< dibujo;i++){
		for (float t = 0; t <= 1; t += 0.01) {
				temp.push_back(CurvaBezier(t, 0,pcontrolTest[i]));
				temp.push_back(CurvaBezier(t, 1,pcontrolTest[i]));
		}

	}

	return temp;
}

void init (GLFWwindow* window) {
	renderingProgram = Utils::createShaderProgram("src/vertShader.glsl", "src/fragShader.glsl");

    // Create Vertex Array Object
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);
    glGenBuffers(4, m_VBO);

    //Se almacenan los puntos que generan grafica
	vector<float> pBezier = graficaPuntosBezier();

	numPointsBz = pBezier.size()/2;
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[0]);

	glBufferData(
			GL_ARRAY_BUFFER,
			pBezier.size()*sizeof(GLfloat),
			(void*)&pBezier[0],
			GL_STATIC_DRAW);

	//Se generan puntos de grafica
	vector<float> pCBezier = graficaCurvaBezier();

	nPointsCurveBz = pCBezier.size()/2;
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[1]);
	glBufferData(
			GL_ARRAY_BUFFER,
			pCBezier.size()*sizeof(GLfloat),
			(void*)&pCBezier[0],
			GL_STATIC_DRAW);

	//Se crea ojo izquierdo
	crearOjos(ojoIzq,-1.0,15);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[2]);
	glBufferData(
	    	GL_ARRAY_BUFFER,
			dimVertices* sizeof(GLfloat),
	    	(void*)ojoIzq,
	    	GL_STATIC_DRAW);

	//Se crea ojo derecho
	crearOjos(ojoDer,18,18);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[3]);
	glBufferData(
		    GL_ARRAY_BUFFER,
			dimVertices* sizeof(GLfloat),
		    (void*)ojoDer,
		   	GL_STATIC_DRAW);

}

void display(GLFWwindow* window, double currentTime) {

	glBindVertexArray(m_VAO);
    glClearColor(0.0f, 0.52f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(renderingProgram);
    glEnableVertexAttribArray(0);

    GLuint position = glGetAttribLocation(renderingProgram, "position");
    GLuint colorIn = glGetUniformLocation(renderingProgram, "colorIn");



    glEnableVertexAttribArray(position);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[1]);
    glVertexAttribPointer(
    		0,
    		2,
    		GL_FLOAT,
    		GL_FALSE,
    		0,
    		(void*) 0
    		);

    //Rostros
    glUniform3f(colorIn, 0.92f, 0.92f, 0.0f);
    glDrawArrays(GL_TRIANGLE_FAN, 0, nPointsCurveBz*19/25);

    //boca
    glUniform3f(colorIn, 0.7f, 0.7f, 0.5f);
    glDrawArrays(GL_TRIANGLE_FAN, nPointsCurveBz*10/25, nPointsCurveBz*4/25);

    //ojitos
    glUniform3f(colorIn, 1.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLE_FAN, nPointsCurveBz*6/25+1 , nPointsCurveBz*2/25+ nPointsCurveBz/(25*2));


    glUniform3f(colorIn, 0.0f, 0.0f, 0.0f);
    glPointSize(5);




    // Dibujar puntos de control
    /*
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[0]);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), 0);
	glPointSize(5);
	glDrawArrays(GL_POINTS, 0, numPointsBz);
	*/



	// Draw Curves Surfaces
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO[1]);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GLfloat), 0);
    glDrawArrays(GL_LINE_STRIP, 1, nPointsCurveBz/dibujo); // 1 para omitir el punto de triangle fan
    glDrawArrays(GL_LINE_STRIP, (nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (2*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (3*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (4*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (5*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (6*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (7*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (8*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (9*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (10*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (11*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (12*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP	, (13*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
    glDrawArrays(GL_LINE_STRIP, (14*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	//Detalles de homero
	glDrawArrays(GL_LINE_STRIP, (15*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (16*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (17*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (18*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (19*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (20*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (21*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (22*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (23*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);
	glDrawArrays(GL_LINE_STRIP, (24*nPointsCurveBz/dibujo)+1, nPointsCurveBz/dibujo-1);


	//Dibujo de ojo izquierdo
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[2]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);
	//Dibujo de ojo derecho
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO[3]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLE_FAN, 0, numberOfVertices);


}

int main(void) {
    if (!glfwInit()) {
    	exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "Homer - OpenGL - Computacion visual", NULL, NULL);
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
    	exit(EXIT_FAILURE);
    }
    glfwSwapInterval(1);

    init(window);

    while (!glfwWindowShouldClose(window)) {
        display(window, glfwGetTime());
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
