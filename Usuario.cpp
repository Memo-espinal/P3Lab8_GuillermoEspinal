#include "Usuario.h"
#include <fstream>
#include<sstream>

Usuario::Usuario()
{
}
Usuario::Usuario(string Dnombre,string Dnick,string Dcontra,string Dposts){
	this->nombre=Dnombre;
	this->nick=Dnick;
	this->contra= Dcontra;
	cargarPosts(Dposts);
}
string Usuario::getName(){
	return nombre;
	
}
string Usuario::getNick(){
	return nick;
}
string Usuario::getContra(){
	return contra;
}
vector<Usuario*> Usuario::getFollowing(){
	return following;
}
void Usuario::addFollowing(Usuario* Dadd){
	following.push_back(Dadd);		
}
vector<Post*>Usuario::getPost(){
	return posteos;
}
void Usuario::addPost(Post* Npost){
	posteos.push_back(Npost);			
}
//parseo para poder cargar los posts de los usuarios
vector<string> Usuario:: split(const string& str, const string& delim){
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

void Usuario::cargarPosts(string str_posts){
	if (str_posts.length()>2){
		vector<string> postdivididos;
		postdivididos=split(str_posts,"|");
		vector<string> postsinterinos;
		for (int i =0 ; i < postdivididos.size();i++){
			string titulo;
			string contenido;
//			int likes=0;
//			int hates=0;
			postsinterinos= split(postdivididos[i],",");
			titulo=postsinterinos[0];
			contenido= postsinterinos[1];
			//esto es para los likes que son ints y hay que hacer unas maniobras
			string slikes= postsinterinos[2];
			stringstream sslikes(slikes);
			int likes =0;
			sslikes>>likes;
			//esto es para los hates
			string shates= postsinterinos[3];
			stringstream sshates(shates);
			int hates =0;
			sshates>>hates;
			Post* nuevo = new Post(titulo,contenido,likes,hates);
			posteos.push_back(nuevo);
		}
	}

	
}
		
		

Usuario::~Usuario()
{
	for(int i =0 ; i<following.size();i++){
		delete following[i];
	}
}
