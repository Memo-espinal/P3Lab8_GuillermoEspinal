#include <iostream>
#include <vector>
#include <string >
#include "Usuario.h"
#include "Post.h" 
#include "Comentario.h"
#include <sstream>
#include <fstream>

using namespace std;
//Variables globales
Usuario* actual;
vector<Usuario*> Usuarios;

//METODO PARA SPLITEAR UN STRING Y QUE DEVUELVA UN VECTOR
vector<string> split(const string& str, const string& delim){
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
//METODO PARA METER ALUMNOS AL ARCHIVO MAYBE
void meterAlumno(Usuario* meter){
	
}
//METODO PARA VERIFICAR SI YA EXISTE ESE USER
bool Verificar(string nick){
	ifstream leer ("Usuarios.txt",ios::in);
	vector<string> splited;
	string nombre;
	string nickname;
	string contra;
	string posts;
	if(leer.is_open()){
		string buffer;
		//aqui mero we
		while (getline(leer,buffer)){
			if (buffer.length()>0){
				splited = split(buffer,";");
				nombre = splited[0];
				nickname = splited[1];
				contra = splited[2];
				posts=splited[3];
			}
			if (nickname==nick){
				return false;
			}
		}
	}
	return true;
	
}
void CargarArchivo(){
	ifstream leer;
	leer.open("Usuarios.txt",ios::in);
	vector<string> splited;
	string nombre, nickname, contra, posts;
	if (leer.is_open()){
		string buffer;
		while (getline(leer,buffer)){
			if (buffer.length()>0){
				//cout << "LLEGUE ADENTRO DEL IF DE CARGAR\n";
				splited = split(buffer,";");
//				cout<<"Me mamo despues del split\n";
//				cout << "ESTE ES EL SIZE DE SPLITED= "<< splited.size();
				nombre = splited[0];
				nickname = splited[1];
				contra = splited[2];
				posts=splited[3];
				//cout<<"ME MAMO ANTES DE CREAR Y AGREGAR UN NUEVO USUARIO";
				Usuario* usuario_nuevo= new Usuario(nombre,nickname,contra,posts);
				Usuarios.push_back(usuario_nuevo);
			}
		}
	}
	leer.close();
}
void Interfaz(Usuario* usuario){
	loop:
		vector<Usuario*>follow;
		follow=usuario->getFollowing();
		
		if (follow.size()>0){
			vector<Post*>posts;
			for(){
				
			}
		}
		cout<< "Sup perro "<< usuario->getName()<< endl;
		Crear postComentar postDar likeDar hateSeguirusuarioDejar de seguir a un usuario
		cout << "1.- Crear Post"<<endl;
		cout << "2.- Comentar post"<< endl;
		cout <<"3.-Dar like"<<endl;
		cout <<"4.-Dar hate"<< endl;
		cout <<"5.- Seguir usuario"<< endl;
		cout <<"6.- Dejar de seguir a un usuario"
		//break;
}

int main(int argc, char** argv) {
	CargarArchivo();
	loop: 
	int resp=0;
	cout << "Ingrese que quiere hacer :"<< endl;
	cout << "1.- Agregar Usuario"<< endl;
	cout << "2.- Ingresar"<< endl;
	cin>> resp;
	switch (resp){
		case 1 :{
			string nombre,contra,nick,post;
			cout<< "Ingrese el nombre :"<< endl;
			getline(cin,nombre);
			getline(cin,nombre);
			cout << "Ingrese el nombre de Usuario:"<< endl;
			getline(cin, nick);
			while(!Verificar(nick)){
				cout << "Ese usuario ya esta tomado vuelva a ingresarlo porfavor:"<< endl;
				getline(cin,nick);
			}
			cout << "Ingrese la contrasena: "<< endl;
			getline(cin,contra);
			ofstream escribir;
			post="--";
			escribir.open("Usuarios.txt",ios::app);
			if (escribir.is_open()){
				escribir << nombre <<';'<< nick<<';'<<contra<<';'<<post<< '\n';
			}
			escribir.close();
			//cout<<"ANtes de cargar archivo me mamo";
			CargarArchivo();
			goto loop;
			break;
		}
		case 2 :{
			string usu,contra;
			cout<< "Ingrese su nombre de usuario: "<< endl;
			getline(cin,usu);
			getline(cin,usu);
			cout <<"Ingrese su contrasena: "<< endl;
			getline(cin,contra);
			bool logged= true;
			for(int i=0 ; i < Usuarios.size();i++){
				if (usu==Usuarios[i]->getNick()){
					if (contra==Usuarios[i]->getContra()){
						actual= Usuarios[i];
						logged=true;
						cout<<"!!----Login perfecto-----!!"<< endl;
						break;	
					}else{
						//cout<<"POR ALGUNA RAZON ENTRE AL ELSE DE CONTRA";
						logged=false;
						cout<<"XX----Contrasena Incorrecta---XX\n"<< endl;
					}
				}else{
					
					logged=false;
					cout<<"Usuario no existe"<< endl;
				}
			}
			
			if(logged==true){
				//cout<< "entre al if\n";
				Interfaz(actual);
			}else if(logged==false){
				goto loop;
			}
			
			break;
		}
			
	}
	
	return 0;
}
