//Semestre 2017 - 2
//***Programa que crea un prisma de medidas dinamicas*********//
//***permite definir las medidas iniciales y despues modificar sus dimensiones en tiempo de ejecucion*********//
//************** Alumno (s): *********************************//
//*************  basilio torres carlos alberto			******//
//*************	 reporte practica 3						******//
//***************version de visuall studio: 2017**************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"
#include <stdio.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -3.80002f;
/*Largo, ancho y alto me permiten establecer condiciones iniciales de mi prisma y ademas
me permiten modificar dimensiones en tiempo real*/

float largo, ancho, alto;

void InitGL ( GLvoid )     // Inicializamos parametros
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
	/*
		Para definir correctamente mi figura, determine que en cada eje que busco modificar hago que cada vertice
		se mueva la mitad de la longitud necesitada sobre ese mismo eje, logrando que toda la figura tenga como centro
		el origen
		
		ancho mueve los vertices sobre el eje x
		alto  mueve los vertices sobre el eje y
		largo mueve los vertices sobre el eje z
	*/
	GLfloat vertice [8][3] = {
				{ancho/2 ,-alto/2, largo/2},    //Coordenadas Vértice 0 V0 ifd
				{-ancho/2 ,-alto/2, largo/2},    //Coordenadas Vértice 1 V1  ifi
				{-ancho/2 ,-alto/2, -largo/2},    //Coordenadas Vértice 2 V2 iai
				{ancho/2 ,-alto/2, -largo/2},    //Coordenadas Vértice 3 V3 iad
				{ancho/2 , alto/2,  largo/2},    //Coordenadas Vértice 4 V4 fsd
				{ancho/2 , alto/2, -largo/2},    //Coordenadas Vértice 5 V5  asd
				{-ancho/2 ,alto/2, -largo/2},    //Coordenadas Vértice 6 V6 asi
				{-ancho/2 ,alto/2,  largo/2},    //Coordenadas Vértice 7 V7 fsi
				};


		glBegin(GL_POLYGON);	//Front
			glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
	
		glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		//Poner Código Aquí.
	glTranslated(transX, transY, transZ);
	prisma();
		
  											

    glutSwapBuffers ( );
    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.5, 0.5,-0.5, 0.5, 0.1, 50.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		/*Para hacer mas interesante este programa, en tiempo real puedes modificar las medidas del prisma con las siguientes teclas
			h-> aumenta el ancho(eje x)
			b->disminuye el ancho(eje x)
			j->aumenta el alto(eje y)
			n->disminuye el alto(eje y)
			k->aumenta el largo(eje z)
			m->disminuye el largo(eje z)
		*/
		case 'h':
		case 'H':
			ancho += 0.2f;
			break;
		case 'b':
		case 'B':
			ancho -= 0.2f;
			break;
		case 'j':
		case 'J':
			alto += 0.2f;
			break;
		case 'n':
		case 'N':
			alto -= 0.2f;
			break;
		case 'k':
		case 'K':
			largo += 0.2f;
			break;
		case 'm':
		case 'M':
			largo -= 0.2f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}

/*Inicialmente la funcion principal invoca a la funcion define_medidas() y pide los valores correspondientes al usuario*/
void define_medidas() {
	printf("Determina el ancho de tu figura: ");
	scanf_s("%f", &ancho);
	printf("Determina el alto de tu figura: ");
	scanf_s("%f", &alto);
	printf("Determina el largo de tu figura: ");
	scanf_s("%f", &largo);
}

int main ( int argc, char** argv )   // Main Function
{
	define_medidas();
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



