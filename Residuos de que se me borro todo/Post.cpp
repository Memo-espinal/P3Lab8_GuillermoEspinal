#include "Post.h"
#include <string>
using namespace std;


Post::Post()
{
}
Post::Post(string Dtitulo,string Dcontenido,int Dlikes,int Dhates){
	titulo=Dtitulo;
	likes=Dlikes;
	hates=Dhates;
	contenido=Dcontenido;
	
}
//string Post::toString(){
//	string let = titulo <<","<<contenido<<","<<likes+","<<hates<<"|";
//	return let;
//	}
Post::~Post()
{
}
