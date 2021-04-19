#include <iostream>
#include <stdexcept>
#include <vector>
#include "Direction.hpp"
#include <map>
#include <iterator>

using namespace std;

namespace ariel {// map 
	// Defines a Board constructor
	class Board {
		private:
			unsigned int NumRow=0;
			unsigned int NumColumn=0;
			 map <unsigned int,map<unsigned int,char> >MyBoard;

		public:
		void post(unsigned int row, unsigned int column, Direction direction,string const &message);
		string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
		void show();
		// // Constructors:
	
	};
}
