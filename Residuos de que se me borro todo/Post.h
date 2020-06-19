#ifndef POST_H
#define POST_H
//#include "Usuario.h"
//#include "Comentario.h"
#include<string>

using namespace std;

class Post
{
	public:
		Post();
		Post(string,string,int,int);
		
		int getLikes();
		int getHates();
		string getTitulo();
		//string toString();
		
		
		
		~Post();
	protected:
		
		int likes=0;
		int hates=0;
		string titulo;
		//Usuario* creador;
		string nombre_creador;
		string contenido;
};

#endif
