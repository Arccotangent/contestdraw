/*
This file is part of ContestDraw.

ContestDraw is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
any later version.

ContestDraw is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ContestDraw.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONTESTDRAW_SALT_H
#define CONTESTDRAW_SALT_H

#include <iostream>

class Salt {
public:
	static std::string generateRandomSalt();
};


#endif //CONTESTDRAW_SALT_H
