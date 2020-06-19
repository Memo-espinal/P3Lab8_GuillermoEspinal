#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <vector>
#include "Post.h"

using std::string;
using std::vector;

//class Post;

class Usuario
{
	public:
		Usuario();
		Usuario(string,string,string,string);
		
		
		string getName();
		string getNick();
		string getContra();
		vector<Usuario*> getFollowing();
		vector<Post*>getPosts();
		void addPost(Post*);
		void addFollowing(Usuario*);
		void cargarPosts(string);
		vector<string> split(const string&, const string&);
		
		
		
		~Usuario();
	protected:
		string nombre;
		string nick;
		string contra;
		
		vector<Usuario*>following;
		vector<Post*>posteos;
		//friend class 
};

#endif
