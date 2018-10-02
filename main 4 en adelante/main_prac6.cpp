//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Basilio Torres Carlos Alberto****//
//*************	Practica: 6								******//
//*************	Version de visual estudio: 2017         ******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol = 0;
int venus = 0;
int mercurio = 0;
int marte = 0;
int tierra = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
float ejey = 0.0f, ejex = 5.0f;
float camaraZ = 3.0;
float camaraX = 0.0;


GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara
	
	glRotatef(ejey, 0, 0, 1);
	glRotatef(ejex, 1, 0, 0);

	glPushMatrix();

			glPushMatrix();
				glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
				glColor3f(1.0, 0, 0);	//Sol amarillo
				glutSolidSphere(.2, 12, 12);  //radio de 2 unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90,0, 1, 0);
				glRotatef(mercurio - 1, 0, 0, 1);
				glTranslatef(0, 0, 0);
				glColor3f(0,0,1);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(mercurio - 1, 0, 0, 1);
				glTranslatef(-1, 0, 0);
				glColor3f(0,1,0);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(90, 1, 0, 0);
				glRotatef(1.7*mercurio, 0, 0, 1);
				glTranslatef(1, 0, 0);
				glColor3f(0,1,1);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();
			
			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(90, 1, 0, 0);
				glRotatef(1.7*mercurio, 0, 0, 1);
				glTranslatef(-1, 0, 0);
				glColor3f(1,0,0);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(45, 1, 0, 0);
				glRotatef(2.2*mercurio, 0, 0, 1);
				glTranslatef(1, 0, 0);
				glColor3f(1,0,1);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(45, 1, 0, 0);
				glRotatef(2.2*mercurio, 0, 0, 1);
				glTranslatef(-1, 0, 0);
				glColor3f(1,1,0);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();


			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(-45, 1, 0, 0);
				glRotatef(1.6*mercurio, 0, 0, 1);
				glTranslatef(-1, 0, 0);
				glColor3f(1,1,1);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glRotatef(-45, 1, 0, 0);
				glRotatef(1.6*mercurio, 0, 0, 1);
				glTranslatef(1, 0, 0);
				glColor3f(.5,1,1);
				glutSolidSphere(.1, 12, 12);  //radio de .1s unidades;
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				glColor3f(1, 1, 1);
				glutSolidTorus(.01,1.0001,12,12);
			glPopMatrix();
			
			glPushMatrix();
				glRotatef(90, 1, 0,0);
				glRotatef(45, 0, 1, 0);
				glColor3f(1, 1, 1);
				glutSolidTorus(.02,1.0001,12,12);
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				glRotatef(-45, 0, 1, 0);
				glColor3f(1, 1, 1);
				glutSolidTorus(.02, 1.0001, 12, 12);
			glPopMatrix();
			glPushMatrix();
				glRotatef(90, 0, 1, 0);
				glColor3f(1, 1, 1);
				glutSolidTorus(.02, 1.0001, 12, 12);
			glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 60)
	{
		/*
			Para las rotaciones, para evitar un desborde de memoria se realizo lo siguiente
			
			se decrementa el valor de la variable sol constntemente en uno, hsta llegar en -360 grados,

			al llegar a dicho valor se resetean todas las varibles.
		*/
		if (sol > -360)
		{
			sol = (sol-5);
			mercurio = mercurio - 5;
		}
		else {
			sol = 0;
		}
		

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:
		// Presionamos tecla ARRIBA...
		ejex += 1.0f;
		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		ejex -= 1.0f;
		break;
	case GLUT_KEY_LEFT:
		ejey -= 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		ejey += 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}