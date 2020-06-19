#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>
using namespace std;

class Archivo
{
	public:
		Archivo();
		
		void leerArchivo(string);
		void meterUsuario();
		
		
		~Archivo();
	protected:
		string name;
		
};

#endif
