#include <vector>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

struct Point
{
	int x; 
	int y;
};

class Cells
{
protected:
	Point pos;
	Fl_Color frameColor;
	Fl_Color cellColor;
	bool canBeMoved;
public:
	// les différents constructeurs
	Cells(Point pos, Fl_Color frameColor, Fl_Color cellColor);
	Cells();
	~Cells();
	Cells(const Cells &other);
	Cells &operator=(const Cells &other);

	// seters
	void setFrameColor(Fl_Color newFColor);
	void setCellColor(Fl_Color newCColor);

	// getters
	int getPosX();
	int getPosY();
	Fl_Color getFColor();
	Fl_Color getCColor();

	// les méthodes
	void draw();
};
