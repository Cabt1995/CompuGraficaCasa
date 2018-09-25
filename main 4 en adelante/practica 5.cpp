//Semestre 2017 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float hombro = 0.0f;
float hombrox = 0.0f;
float hombroy = 0.01;
float codo = 0.0f;
float codox = 0.0f;
float mano = 0.0f;
float manox = 0.0f;
float dedo = 0.0f;
float dedoy = 0.0f;
float dedoz = 0.0f;
float dedoz_s = 0.0f;
float dedo_sup = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


void InitGL(void)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
	};

	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glColor3f(0.4, 0.2, 0.6);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glColor3f(0.8, 0.2, 0.4);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glTranslatef(transX, 0.0f, transZ);
	//Poner C�digo Aqu�.
	glPushMatrix();//torso
	glScalef(2, 2, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//cuello
	glTranslated(0, 1.11, 0);
	glScalef(.8, .2, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//cabeza
	glTranslated(0, 1.73, 0);
	glScalef(1.2, 1, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//mano izquierda
	glTranslated(-1 - hombrox, .50 + hombroy, 0);
	glRotatef(-hombro, 0, 0, 1);
	glPushMatrix(); //hombro
	glTranslatef(-.7, 0, 0);
	glScalef(1, .4, .3);
	prisma();
	glPopMatrix();

	glPushMatrix(); //codo
	glTranslatef(-1 + codox, 0, 0);
	glRotatef(-codo, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-.8, 0, 0);
	glScalef(1, .4, .3);
	prisma();
	glPopMatrix();

	glPushMatrix();//mano
	glTranslatef(-1 - manox, 0, 0);
	glRotatef(-mano, 0, 1, 0);

	glPushMatrix();
	glTranslatef(-.5, 0, 0);
	glScalef(.3, .3, .3);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//meter aqui resto del codigo
	glPopMatrix();

	glPushMatrix();//mano derecha
		glTranslated(1+hombrox, .50+hombroy, 0);
		glRotatef(hombro,0,0,1);
		glPushMatrix(); //hombro
			glTranslatef(.7, 0, 0);
			glScalef(1, .4, .3);
			prisma();
		glPopMatrix();

		glPushMatrix(); //codo
			glTranslatef(1+codox, 0, 0);
			glRotatef(codo, 0, 1, 0);

			glPushMatrix();
			glTranslatef(.8, 0, 0);
				glScalef(1, .4, .3);
				prisma();
			glPopMatrix();

			glPushMatrix();//mano
				glTranslatef(1+manox, 0, 0);
				glRotatef(mano, 0, 1, 0);

				glPushMatrix();
					glTranslatef(.5, 0, 0);
					glScalef(.3, .3, .3);
					prisma();
				glPopMatrix();

				glPushMatrix();//dedo
					glTranslatef(0.5, 0.27+dedoy, dedoz);
					glRotatef(dedo,1,0,0);
					
					glPushMatrix();
						glTranslatef(0, 0, 0);
						glScalef(.07, .15, .1);
						prisma();
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0, 0, 0);
						glRotatef(dedo_sup, 1, 0, 0);
						glPushMatrix();
						glTranslatef(0, .16, 0);
							glScalef(.07, .05, .1);
							prisma();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();

				
		glPopMatrix ();
	glPopMatrix();
		//meter aqui resto del codigo
	glPopMatrix();


	glPushMatrix();//pierna izquierda
	glTranslated(-.5, -1.42, 0);
	glScalef(.6, .8, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//pierna izquierda
	glTranslated(-.5, -2.25, 0);
	glScalef(.6, .8, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//pierna izquierda
	glTranslated(-.5, -2.95, 0);
	glScalef(.6, .5, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//pierna derecha
	glTranslated(.5, -1.42, 0);
	glScalef(.6, .8, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//pierna derecha
	glTranslated(.5, -2.25, 0);
	glScalef(.6, .8, 1.25);
	prisma();
	glPopMatrix();

	glPushMatrix();//pierna derecha
	glTranslated(.5, -2.95, 0);
	glScalef(.6, .5, 1.25);
	prisma();
	glPopMatrix();
	glutSwapBuffers();
	// Swap The Buffers
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
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.3f;
		break;
	case 's':
	case 'S':
		transZ -= 0.3f;
		break;
	case 'a':
	case 'A':
		transX -= 0.3f;
		break;
	case 'd':
	case 'D':
		transX += 0.3f;
		break;
	case 'h':
		if (hombro > -75) {
			hombro -= 1;
			hombrox += .004;
			hombroy += .01f;
		}
		else {
			if (hombro > -90) {
				hombro -= 1;
				hombrox += .004;
				hombroy -= .01f;
			}
		}
		break;
		case 'H':
				if (hombro < -15) {
					hombro += 1;
					hombrox -= .004;
					hombroy -= .01f;
				}
				else {
					if (hombro < 0) {
						hombro += 1;
						hombrox -= .004;
						hombroy += .01f;
					}
				}
			break;
		case 'C':
			if (codo > -90)
			{
				codo -= 1;
				codox += .001;
			}
			break;
		case 'c':
			if (codo < 0)
			{
				codo += 1;
				codox -= .001;
			}
			break;

		case 'M':
			if (mano > -90) {
				mano -= 1;
				manox += .002;
			}
			break;
		case 'm':
			if (mano < 0) {
				mano += 1;
				manox -= .002;
			}
			break;
		case 'I':
			if (dedo < 90) {
				dedo += 1;
				dedoy -= .001;
				dedoz += .003;
				dedoz_s -= .0025;
				printf("%.2f\n", dedoz_s);
			}
			break;
		case 'i':
			if (dedo > 0) {
				dedo -= 1;
				dedoy += .001;
				dedoz -= .003;
				dedoz_s += .0025;
			}
			break;
		case 'O':
			if (dedo_sup < 30) {
				dedo_sup += 1;
				dedo += 1;
			}
			break;
		case 'o':
			if (dedo_sup > 0) {
				dedo_sup -= 1;
				dedo -= 1;
			}
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
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	screenW = glutGet(GLUT_SCREEN_WIDTH);
	screenH = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 4"); // Nombre de la Ventana
	printf("Resolution H: %i \n", screenW);
	printf("Resolution V: %i \n", screenH);
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}