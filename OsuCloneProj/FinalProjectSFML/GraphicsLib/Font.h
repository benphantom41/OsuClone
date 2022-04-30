#ifndef Font_h
#define Font_h
#include <string>

#include<SFML/Graphics/Font.hpp>

#include <Trackable.h>

using namespace std;

//Font class that allows the font that is loaded to be used in the draw function in GraphicsSystems
class Font: public Trackable
{
	friend class GraphicsSystem;

public:
	//constructor and deconstructor
	Font();
	Font(string name, int size);
	~Font();

	int getSize();

private:

	int mSize;
	string mFont;
	
	sf::Font* mpFont;
	sf::Font* getFont();

};
#endif
